#include "database.h"

DataBase::DataBase()
{}

DataBase::~DataBase()
{}

bool DataBase::connect_dataBase()
{
    QSqlDatabase dataBase;
    /* 打开数据库之前判断该数据库是否存在 */
    if(QSqlDatabase::contains("parkInfo.db") == true) // 如果数据库已经存在
    {
        dataBase = QSqlDatabase::database("parkInfo.db");
    }
    else
    {
        dataBase = QSqlDatabase::addDatabase("QSQLITE"); // 添加数据库设备驱动
        dataBase.setDatabaseName("parkInfo.db"); // 设置数据库名称
    }
    if (dataBase.open() == false)
    {
        qDebug() << "connect_dataBase open error" << dataBase.lastError().text();
        return false;
    }
    return true;
}

bool DataBase::initialize_dataBase()
{
    QSqlQuery query;
    bool result = true;

    /* 创建车位信息表 */
    result = query.exec("CREATE TABLE t_car("
                        "carId varchar(3) NOT NULL PRIMARY KEY,"
                        "rfidId varchar(8) NOT NULL,"
                        "zoneId varchar(2) NOT NULL,"
                        "northCar varchar(3) NOT NULL,"
                        "southCar varchar(3) NOT NULL,"
                        "westCar varchar(3) NOT NULL,"
                        "eastCar varchar(3) NOT NULL,"
                        "carPositionX int,"
                        "carPositionY int);");
    if (result == false)
    {
        qDebug() << "initialize_dataBase CREATE TABLE t_car failure" << query.lastError().text();
        return false;
    }

    /* 创建停车区域信息表 */
    result = query.exec("CREATE TABLE t_zone("
                        "zoneId varchar(2) NOT NULL PRIMARY KEY,"
                        "zonePositionX int,"
                        "zonePositionY int);");
    if (result == false)
    {
        qDebug() << "initialize_dataBase CREATE TABLE t_zone failure" << query.lastError().text();
        return false;
    }
    return true;
}

bool DataBase::setCar_database(QString t_carId, QString t_rfidId)
{
    QString rfidId;
    QSqlQuery query;
    bool result = true;

    /* 设置车位状态 */
    if (t_rfidId.isEmpty() == true || t_carId.isEmpty() == true) // 非法参数输入
    {
        return false;
    }

    /* 如果该卡号不为初始值，已经存在，再次停车也为该卡号，则刷卡停车无效 */
    if (t_rfidId != "00000000")
    {
        result = query.prepare("SELECT COUNT(*) FROM t_car WHERE rfidId = ?;");
        if (result == false)
        {
            qDebug() << "setCar_database SELECT COUNT t_car error" << query.lastError().text();
            return false;
        }
        query.bindValue(0, t_rfidId);
        result = query.exec();
        if (result == false)
        {
            qDebug() << "setCar_database exec COUNT t_car error" << query.lastError().text();
            return false;
        }
        if (query.next() == false)
        {
            qDebug() << "setCar_database query COUNT t_car error" << query.lastError().text();
            return false;
        }
        if (query.value(0).toInt() != 0)
        {
            qDebug() << "setCar_database this rfidId is existent";
            return false;
        }
    }

    /* 如果车位已经有车，则再次刷卡停车无效 */
    result = query.prepare("SELECT rfidId FROM t_car WHERE carId = ?;");
    if (result == false)
    {
        qDebug() << "setCar_database SELECT t_car error" << query.lastError().text();
        return false;
    }
    query.bindValue(0, t_carId);
    result = query.exec();
    if (result == false)
    {
        qDebug() << "setCar_database exec rfidId t_car error" << query.lastError().text();
        return false;
    }
    if (query.next() == false)
    {
        qDebug() << "setCar_database query rfidId t_car error" << query.lastError().text();
        return false;
    }
    rfidId = query.value(0).toString();
    if (t_rfidId != "00000000" && rfidId != "00000000")
    {
        qDebug() << "setCar_database false";
        return false;
    }  

    /* 如果车位无车或者输入rfidId为初始值，则更新 */
    result = query.prepare("UPDATE t_car SET rfidId = ? WHERE carId = ?;");
    if (result == false)
    {
        qDebug() << "setCar_database UPDATE t_car error" << query.lastError().text();
        return false;
    }
    query.bindValue(0, t_rfidId);
    query.bindValue(1, t_carId);
    result = query.exec();
    if (result == false)
    {
        qDebug() << "setCar_database exec t_car error" << query.lastError().text();
        return false;
    }
    return true;
}

bool DataBase::queryRfidId_database(QString t_rfidId, CarPositionInfo & t_carPositionInfo)
{
    QSqlQuery query;
    bool result = true;
    if (t_rfidId.isEmpty() == true) // 非法参数输入
    {
        return false;
    }
    result = query.prepare("SELECT t_car.carId, t_car.zoneId, "
                           "t_car.northCar, t_car.southCar, "
                           "t_car.westCar, t_car.eastCar, "
                           "t_car.carPositionX, t_car.carPositionY, "
                           "t_zone.zonePositionX, t_zone.zonePositionY "
                           "FROM t_car, t_zone WHERE t_car.rfidId = ? "
                           "AND t_car.zoneId = t_zone.zoneId;");
    if (result == false)
    {
        qDebug() << "queryRfidId_database SELECT t_car t_zone error" << query.lastError().text();
        return false;
    }
    query.bindValue(0, t_rfidId);
    result = query.exec();
    if (result == false)
    {
        qDebug() << "queryRfidId_database exec t_car t_zone error" << query.lastError().text();
        return false;
    }
    if (query.next() == false)
    {
        qDebug() << "queryRfidId_database query t_car t_zone error" << query.lastError().text();
        return false;
    }
    t_carPositionInfo.setCarId(query.value(0).toString());
    t_carPositionInfo.setRfidId(t_rfidId);
    t_carPositionInfo.setZoneId(query.value(1).toString());
    t_carPositionInfo.setNorthCar(query.value(2).toString());
    t_carPositionInfo.setSouthCar(query.value(3).toString());
    t_carPositionInfo.setWestCar(query.value(4).toString());
    t_carPositionInfo.setEastCar(query.value(5).toString());
    t_carPositionInfo.setCarPositionX(query.value(6).toInt());
    t_carPositionInfo.setCarPositionY(query.value(7).toInt());
    t_carPositionInfo.setZonePositionX(query.value(8).toInt());
    t_carPositionInfo.setZonePositionY(query.value(9).toInt());

    qDebug() << t_carPositionInfo;

    return true;
}


bool DataBase::queryCarId_database(QString t_carId, CarPositionInfo & t_carPositionInfo)
{
    QSqlQuery query;
    bool result = true;
    if (t_carId.isEmpty() == true) // 非法参数输入
    {
        return false;
    }
    result = query.prepare("SELECT t_car.rfidId, t_car.zoneId, "
                           "t_car.northCar, t_car.southCar, "
                           "t_car.westCar, t_car.eastCar, "
                           "t_car.carPositionX, t_car.carPositionY, "
                           "t_zone.zonePositionX, t_zone.zonePositionY "
                           "FROM t_car, t_zone WHERE t_car.carId = ? "
                           "AND t_zone.zoneId = t_car.zoneId;");
    if (result == false)
    {
        qDebug() << "queryCarId_database SELECT t_car t_zone error" << query.lastError().text();
        return false;
    }
    query.bindValue(0, t_carId);
    result = query.exec();
    if (result == false)
    {
        qDebug() << "queryCarId_database exec t_car t_zone error" << query.lastError().text();
        return false;
    }
    if (query.next() == false)
    {
        return false;
    }
    t_carPositionInfo.setCarId(t_carId);
    t_carPositionInfo.setRfidId(query.value(0).toString());
    t_carPositionInfo.setZoneId(query.value(1).toString());
    t_carPositionInfo.setNorthCar(query.value(2).toString());
    t_carPositionInfo.setSouthCar(query.value(3).toString());
    t_carPositionInfo.setWestCar(query.value(4).toString());
    t_carPositionInfo.setEastCar(query.value(5).toString());
    t_carPositionInfo.setCarPositionX(query.value(6).toInt());
    t_carPositionInfo.setCarPositionY(query.value(7).toInt());
    t_carPositionInfo.setZonePositionX(query.value(8).toInt());
    t_carPositionInfo.setZonePositionY(query.value(9).toInt());

    qDebug() << t_carPositionInfo;

    return true;
}

bool DataBase::queryEmptyPark_database(QString & t_emptyPark)
{
    QString t_str;
    QSqlQuery query;
    bool result = true;

    result = query.exec("SELECT COUNT(*) FROM t_car WHERE rfidId = '00000000' AND zoneId = 'A';");
    if (result == false)
    {
        qDebug() << "queryEmptyPark_database SELECT t_car A error" << query.lastError().text();
        return false;
    }
    if (query.next() == false)
    {
        return false;
    }
    t_str.clear();
    t_str = QString::number(query.value(0).toInt());
    if (t_str.size() == 1)
    {
        t_emptyPark += + "0" + t_str;
    }
    t_emptyPark += t_str;

    result = query.exec("SELECT COUNT(*) FROM t_car WHERE rfidId = '00000000' AND zoneId = 'B';");
    if (result == false)
    {
        qDebug() << "queryEmptyPark_database SELECT t_car B error" << query.lastError().text();
        return false;
    }
    if (query.next() == false)
    {
        return false;
    }
    t_str.clear();
    t_str = QString::number(query.value(0).toInt());
    if (t_str.size() == 1)
    {
        t_emptyPark += + "0" + t_str;
    }
    t_emptyPark += t_str;

    result = query.exec("SELECT COUNT(*) FROM t_car WHERE rfidId = '00000000' AND zoneId = 'C';");
    if (result == false)
    {
        qDebug() << "queryEmptyPark_database SELECT t_car C error" << query.lastError().text();
        return false;
    }
    if (query.next() == false)
    {
        return false;
    }
    t_str.clear();
    t_str = QString::number(query.value(0).toInt());
    if (t_str.size() == 1)
    {
        t_emptyPark += + "0" + t_str;
    }
    t_emptyPark += t_str;

    result = query.exec("SELECT COUNT(*) FROM t_car WHERE rfidId = '00000000' AND zoneId = 'D';");
    if (result == false)
    {
        qDebug() << "queryEmptyPark_database SELECT t_car D error" << query.lastError().text();
        return false;
    }
    if (query.next() == false)
    {
        return false;
    }
    t_str.clear();
    t_str = QString::number(query.value(0).toInt());
    if (t_str.size() == 1)
    {
        t_emptyPark += + "0" + t_str;
    }
    t_emptyPark += t_str;

    result = query.exec("SELECT COUNT(*) FROM t_car WHERE rfidId = '00000000' AND zoneId = 'E';");
    if (result == false)
    {
        qDebug() << "queryEmptyPark_database SELECT t_car E error" << query.lastError().text();
        return false;
    }
    if (query.next() == false)
    {
        return false;
    }
    t_str.clear();
    t_str = QString::number(query.value(0).toInt());
    if (t_str.size() == 1)
    {
        t_emptyPark += + "0" + t_str;
    }
    t_emptyPark += t_str;

    result = query.exec("SELECT COUNT(*) FROM t_car WHERE rfidId = '00000000' AND zoneId = 'F';");
    if (result == false)
    {
        qDebug() << "queryEmptyPark_database SELECT t_car F error" << query.lastError().text();
        return false;
    }
    if (query.next() == false)
    {
        return false;
    }
    t_str.clear();
    t_str = QString::number(query.value(0).toInt());
    if (t_str.size() == 1)
    {
        t_emptyPark += + "0" + t_str;
    }
    t_emptyPark += t_str;

    return true;
}

