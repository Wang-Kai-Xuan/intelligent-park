#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QApplication>
#include <QDebug>
#include "carpositioninfo.h"

class DataBase
{
public:
    DataBase();
    ~DataBase();

    bool connect_dataBase();

    bool initialize_dataBase();

    bool setCar_database(QString t_carId, QString t_rfidId);

    bool queryRfidId_database(QString t_rfidId, CarPositionInfo & t_carPositionInfo);

    bool queryCarId_database(QString t_carId, CarPositionInfo & t_carPositionInfo);

    bool queryEmptyPark_database(QString & t_emptyPark);

private:

};

#endif // DATABASE_H
