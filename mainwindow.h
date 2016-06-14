#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QPixmap>
#include <QImage>
#include <QGridLayout>
#include <QDebug>
#include "mapwindow.h"
#include "database.h"
#include "carpositioninfo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    queryRfid();
    dataFull();

private slots:
    void readyReadCom_slot();

    void sendData_slot();

    void serialPortError_slot(QSerialPort::SerialPortError error);

    void queryLineInfo_slot();

    void dataHandle_slot();

    void closeSerialCom_slot();

    void on_CancelBtn_clicked();

    void on_QueryMapBtn_clicked();

    //规划出到达区域入口的路径：直行n个路口，左转，直行m个路口
    void extern_path(int t_zonePositionX, int t_zonePositionY, QString & t_info);

    //根据车位区域内坐标推出行进方向，结合前后状况推算从区域口到达车位的走法。
    void intern_path(QString t_carId, int t_carPositionX, int t_carPositionY, QString & t_info);

private:
    Ui::MainWindow *ui;

    QSerialPort *m_serialCom;

    MapWindow *m_mapWindow;

    DataBase *m_dataBase;

    QString m_COM;

    CarPositionInfo m_carPositionInfo;

    QString m_rfidId;

    QString m_lineInfo;

    QString m_emptyPark;

    QString m_dataBuf;

    int m_readSuccess;

    void AutoSetPortHandle();

    void ComPortConfigure();
};

#endif // MAINWINDOW_H
