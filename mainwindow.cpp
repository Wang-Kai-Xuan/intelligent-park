#include "mainwindow.h"
#include "ui_mainwindow.h"
QT_USE_NAMESPACE

static const char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog", "N/A");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /* 串口对象 */
    m_serialCom = new QSerialPort(this);
    AutoSetPortHandle();
    ComPortConfigure();

    /* 地图对象 */
    m_mapWindow = new MapWindow;

    /* 数据库对象 */
    m_dataBase = new DataBase;
    if (m_dataBase->connect_dataBase() == true)
    {
        m_dataBase->initialize_dataBase();
    }

    m_readSuccess = 0;

    connect(m_serialCom, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(serialPortError_slot(QSerialPort::SerialPortError)));
    connect(m_serialCom, SIGNAL(readyRead()), this, SLOT(readyReadCom_slot()));
    connect(this, SIGNAL(queryRfid()), this, SLOT(queryLineInfo_slot()));
    connect(this, SIGNAL(dataFull()), this, SLOT(dataHandle_slot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*********************************************************************
*
*
*
*            串口数据交换相关函数
*
*
*
*********************************************************************/
void MainWindow::readyReadCom_slot()
{
    /*读取串口缓冲区的所有数据给临时变量 tempData*/
    QByteArray tempData;
    tempData.clear();

    tempData = m_serialCom->readAll();
    qDebug() << "readyReadCom_slot tempData" << tempData.data();
    m_dataBuf.append(tempData);
    qDebug() << "readyReadCom_slot m_dataBuf" << m_dataBuf;

    if (m_dataBuf.size() >= 12 && m_readSuccess == 0) // 当前状态可读，并且数据满
    {
        emit dataFull();
    }
}

void MainWindow::dataHandle_slot()
{
    QString t_emptyPark;
    QString t_dataBuf = m_dataBuf;
    m_dataBuf.clear(); // 数据清空
    m_readSuccess = 1; // 当前状态不可读
    /* 分析数据类型，将数据写入数据库或从数据库读取相关信息显示到界面上 */
    qDebug() << "dataHandle_slot t_dataBuf" << t_dataBuf;

    /* 读到第一个字符为'r'，则代表现在有人在刷卡查询路线 */
    if (t_dataBuf.at(0) == 'r')
    {
        m_rfidId = t_dataBuf.mid(4, 8);
        qDebug() << "dataHandle_slot m_rfidId" << m_rfidId;
        if (m_rfidId.isEmpty() == false)
        {
            if (QMessageBox::question(this, "Qurey", "刷卡成功，\n按确认键继续！",
                                         QMessageBox::Ok, QMessageBox::Cancel) == QMessageBox::Ok)
            {
                emit queryRfid();
            }
            else
            {
                on_CancelBtn_clicked();
            }
        }
    }
    /* 读到第一个字符为'p'，则代表现在有人在停车或者将车开走，更新数据库并且更新液晶屏显示 */
    if (t_dataBuf.at(0) == 'p')
    {
        m_dataBase->setCar_database(t_dataBuf.mid(1, 3), t_dataBuf.mid(4, 8));
        m_dataBase->queryEmptyPark_database(t_emptyPark);
        m_emptyPark = t_emptyPark;
        sendData_slot();

        m_dataBuf.clear();  // 数据空，可读
        //m_readSuccess = 0;
    }
}

void MainWindow::sendData_slot()
{
    /* 从数据库读取相关信息发送给协调器，协调器发送给停车场出口处终端结点 */
    if (m_emptyPark.isEmpty() == false)
    {
        /*以 ASCII码形式将数据写入串口*/
        qDebug() << "on_sendBtn_clicked tempData" << m_emptyPark;
        m_serialCom->write(m_emptyPark.toLatin1());
    }
}

/*********************************************************************
*
*
*
*            主界面显示相关函数
*
*
*
*********************************************************************/
void MainWindow::queryLineInfo_slot()
{

    /* 查询数据库 */
    if (m_dataBase->queryRfidId_database(m_rfidId, m_carPositionInfo) == false)
    {
        ui->CardIDLabel->setText("此卡无效！");
        ui->CarLineLabel->setText("路线不存在！");

        m_dataBuf.clear(); // 数据空，可读
        //m_readSuccess = 0;
        return;
    }

    /* 路线规划 */
    //规划出到达区域入口的路径：直行n个路口，左转，直行m个路口
    extern_path(m_carPositionInfo.getZonePositionX(), m_carPositionInfo.getZonePositionY(), m_lineInfo);
    m_lineInfo += '\n';
    //根据车位区域内坐标推出行进方向，结合前后状况推算从区域口到达车位的走法。
    intern_path(m_carPositionInfo.getCarId(), m_carPositionInfo.getCarPositionX(), m_carPositionInfo.getCarPositionY(), m_lineInfo);

    /* 显示车位查找路线 */
    ui->CardIDLabel->setText(m_carPositionInfo.getCarId());
    ui->CarLineLabel->setText("由当前位置出发" + m_lineInfo);

    m_dataBuf.clear();  // 数据空，可读
    //m_readSuccess = 0;
}

void MainWindow::on_CancelBtn_clicked()
{
    /* 清除当前信息显示*/
    ui->CardIDLabel->setText("车位号");
    ui->CarLineLabel->setText("路\n线");
    m_carPositionInfo.clear();
    m_rfidId.clear();
    m_lineInfo.clear();
    m_emptyPark.clear();
    m_dataBuf.clear();
    m_readSuccess = 0;
}

void MainWindow::on_QueryMapBtn_clicked()
{
    /* 从数据库中读取数据，设置地图 */
    /* 初始化设置地图 */
    m_mapWindow->initAllCarZoneStatus();
    QString t_carId = m_carPositionInfo.getCarId();
    if (t_carId.isEmpty() == true)
    {
        QMessageBox::warning(this, "Warning", "请刷卡后查看", QMessageBox::Ok);
        return;
    }
    char t_zoneLabel = t_carId.at(0).toLatin1();
    switch (t_zoneLabel)
    {
        case 'A':
        {
            m_mapWindow->setCarZone_A(t_carId, true);
            break;
        }
        case 'B':
        {
            m_mapWindow->setCarZone_B(t_carId, true);
            break;
        }
        case 'C':
        {
            m_mapWindow->setCarZone_C(t_carId, true);
            break;
        }
        case 'D':
        {
            m_mapWindow->setCarZone_D(t_carId, true);
            break;
        }
        case 'E':
        {
            m_mapWindow->setCarZone_E(t_carId, true);
            break;
        }
        case 'F':
        {
            m_mapWindow->setCarZone_F(t_carId, true);
            break;
        }
        default: break;
    }
    m_mapWindow->show();
}

void MainWindow::extern_path(int t_zonePositionX, int t_zonePositionY, QString & t_info)
{
    if (t_zonePositionY > 1)
    {
        if (t_zonePositionX > 0)
        {
             t_info += "靠右向南";
        }
        else
        {
            t_info += "靠左向南";
        }
        t_info += "直行，在第个路口处";
        t_info[10] = t_zonePositionY + 47;
    }

    if (t_zonePositionX > 0)
    {
        t_info += "右转向东直行，";
        t_info += "\n";
    }
    else
    {
        t_info += "左转向西直行，";
        t_info += "\n";
    }
}

void MainWindow::intern_path(QString t_carId, int t_carPositionX, int t_carPositionY, QString & t_info)
{
    CarPositionInfo t_carPositionInfo = m_carPositionInfo;
    QString temp;
    QString r_temp;
    int len = 0; // 记录共经过多少个车位

    if (t_carPositionX > 0) // 检查后边，左边
    {
        while (t_carPositionX != 0 || t_carPositionY != 0)
        {
            if (t_carPositionInfo.getNorthCar() != "000")//后边有车位
            {
                t_info += t_carPositionInfo.getNorthCar();
                t_carPositionY--;
                m_dataBase->queryCarId_database(t_carPositionInfo.getNorthCar(), t_carPositionInfo); // 根据区域内坐标查车位信息
            }
            else //后边没车，往左走
            {
                t_info += t_carPositionInfo.getEastCar();
                t_carPositionX--;
                m_dataBase->queryCarId_database(t_carPositionInfo.getEastCar(), t_carPositionInfo); // 根据车位ID查询车位信息
            }
            len++;
        }
        qDebug() << "left t_info" << t_info.toLatin1();
        if (len > 0)
        {
            temp = t_info.right(len * 3);
            t_info = t_info.left(t_info.length() - len * 3) + "途经";
        }
        for (int i=1; i<=len; i++)
        {
            r_temp += (temp.right(3 * i)).left(3);
            r_temp += "车位，";
        }
        t_info = t_info + r_temp + "到达" + t_carId + "车位";
    }
    else//t_carPositionX<0，检查后边，右边
    {
        while (t_carPositionX != 0 || t_carPositionY != 0)
        {
            if (t_carPositionInfo.getNorthCar() != "000")//后边有车位
            {
                t_info += t_carPositionInfo.getNorthCar();
                t_carPositionY--;
                m_dataBase->queryCarId_database(t_carPositionInfo.getNorthCar(), t_carPositionInfo); //根据车位ID查询车位信息
            }
            else // 后边没车，往右走
            {
                t_info += t_carPositionInfo.getWestCar();
                t_carPositionX++;
                m_dataBase->queryCarId_database(t_carPositionInfo.getWestCar(), t_carPositionInfo); //根据区域内坐标查车位信息
            }
            len++;
        }
        if (len > 0)
        {
            temp = t_info.right(len * 3);
            t_info = t_info.left(t_info.length() - len * 3) + "途经";
        }
        for (int i=1; i<=len; i++)
        {
            r_temp += (temp.right(3 * i)).left(3);
            r_temp += "车位，";
        }
        t_info = t_info + r_temp + "到达" + t_carId + "车位";
    }
}

/*********************************************************************
*
*
*
*            串口初始化相关函数
*
*
*
*********************************************************************/
void MainWindow::serialPortError_slot(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError)
    {
        QMessageBox::critical(this, "Critical Error", m_serialCom->errorString());
        closeSerialCom_slot();
    }
}

void MainWindow::closeSerialCom_slot()
{
    if (m_serialCom->isOpen())
    {
        m_serialCom->close();
    }
}

void MainWindow::AutoSetPortHandle()
{
    QString description;
    QString manufacturer;
    QString serialNumber;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QStringList list;
        description = info.description();
        manufacturer = info.manufacturer();
        serialNumber = info.serialNumber();
        list << info.portName()
             << (!description.isEmpty() ? description : blankString)
             << (!manufacturer.isEmpty() ? manufacturer : blankString)
             << (!serialNumber.isEmpty() ? serialNumber : blankString)
             << info.systemLocation()
             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : blankString)
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : blankString);
        qDebug() << "AutoSetPortHandle list.first" << list.first();
        m_COM = list.first();
    }
}

void MainWindow::ComPortConfigure()
{
    /*com口设置*/
//    m_serialCom->setPortName(m_COM);
    m_serialCom->setPortName("COM2");

    /*波特率设置*/
    m_serialCom->setBaudRate(QSerialPort::Baud9600);

    /*数据位设置，我们设置为 8位数据位*/
    m_serialCom->setDataBits(QSerialPort::Data8);

    /*奇偶校验设置，我们设置为无校验*/
    m_serialCom->setParity(QSerialPort::NoParity);

    /*停止位设置，我们设置为 1位停止位*/
    m_serialCom->setStopBits(QSerialPort::OneStop);

    /*数据流控制设置，我们设置为无数据流控制*/
    m_serialCom->setFlowControl(QSerialPort::NoFlowControl);

    if (m_serialCom->open(QIODevice::ReadWrite) == false)
    {
       QMessageBox::critical(this, tr("Error"), m_serialCom->errorString());
    }
}


