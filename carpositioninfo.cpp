#include "carpositioninfo.h"

CarPositionInfo::CarPositionInfo()
{}

CarPositionInfo::~CarPositionInfo()
{}

void CarPositionInfo::setCarId(QString t_carId)
{
    m_carId = t_carId;
}

void CarPositionInfo::setRfidId(QString t_rfidId)
{
    m_rfidId = t_rfidId;
}

void CarPositionInfo::setZoneId(QString t_zoneId)
{
    m_zoneId = t_zoneId;
}

void CarPositionInfo::setNorthCar(QString t_northCar)
{
    m_northCar = t_northCar;
}

void CarPositionInfo::setSouthCar(QString t_southCar)
{
    m_southCar = t_southCar;
}

void CarPositionInfo::setWestCar(QString t_westCar)
{
    m_westCar = t_westCar;
}

void CarPositionInfo::setEastCar(QString t_eastCar)
{
    m_eastCar = t_eastCar;
}

void CarPositionInfo::setCarPositionX(int t_carPositionX)
{
    m_carPositionX = t_carPositionX;
}

void CarPositionInfo::setCarPositionY(int t_carPositionY)
{
    m_carPositionY = t_carPositionY;
}

void CarPositionInfo::setZonePositionX(int t_zonePositionX)
{
    m_zonePositionX = t_zonePositionX;
}

void CarPositionInfo::setZonePositionY(int t_zonePositionY)
{
    m_zonePositionY = t_zonePositionY;
}

QString CarPositionInfo::getCarId() const
{
    return m_carId;
}

QString CarPositionInfo::getRfidId() const
{
    return m_rfidId;
}

QString CarPositionInfo::getZoneId() const
{
    return m_zoneId;
}

QString CarPositionInfo::getNorthCar() const
{
    return m_northCar;
}

QString CarPositionInfo::getSouthCar() const
{
    return m_southCar;
}

QString CarPositionInfo::getWestCar() const
{
    return m_westCar;
}

QString CarPositionInfo::getEastCar() const
{
    return m_eastCar;
}


int CarPositionInfo::getCarPositionX() const
{
    return m_carPositionX;
}

int CarPositionInfo::getCarPositionY() const
{
    return m_carPositionY;
}

int CarPositionInfo::getZonePositionX() const
{
    return m_zonePositionX;
}

int CarPositionInfo::getZonePositionY() const
{
    return m_zonePositionY;
}

void CarPositionInfo::clear()
{
    m_carId.clear();
    m_rfidId.clear();
    m_zoneId.clear();
    m_northCar.clear();
    m_southCar.clear();
    m_westCar.clear(); // 西
    m_eastCar.clear(); // 东
    m_carPositionX = 0;
    m_carPositionY = 0;
    m_zonePositionX = 0;
    m_zonePositionY = 0;
}

CarPositionInfo & CarPositionInfo::operator = (const CarPositionInfo & t_carPositionInfo)
{
    m_carId = t_carPositionInfo.m_carId;
    m_rfidId = t_carPositionInfo.m_rfidId;
    m_zoneId = t_carPositionInfo.m_zoneId;
    m_northCar = t_carPositionInfo.m_northCar;
    m_southCar = t_carPositionInfo.m_southCar;
    m_westCar = t_carPositionInfo.m_westCar; // 西
    m_eastCar = t_carPositionInfo.m_eastCar; // 东
    m_carPositionX = t_carPositionInfo.m_carPositionX;
    m_carPositionY = t_carPositionInfo.m_carPositionY;
    m_zonePositionX = t_carPositionInfo.m_zonePositionX;
    m_zonePositionY = t_carPositionInfo.m_zonePositionY;

    return *this;
}

QDebug operator << (QDebug dbg, const CarPositionInfo & t_carPositionInfo)
{
//    dbg << t_carPositionInfo.getCarId() << t_carPositionInfo.getRfidId() << t_carPositionInfo.getZoneId()
//        << t_carPositionInfo.getNorthCar() << t_carPositionInfo.getSouthCar()
//        << t_carPositionInfo.getWestCar() << t_carPositionInfo.getEastCar()
//        << t_carPositionInfo.getCarPositionX() << t_carPositionInfo.getCarPositionY()
//        << t_carPositionInfo.getZonePositionX() << t_carPositionInfo.getZonePositionY() << endl;

    dbg << t_carPositionInfo.m_carId << t_carPositionInfo.m_rfidId << t_carPositionInfo.m_zoneId
        << t_carPositionInfo.m_northCar << t_carPositionInfo.m_southCar
        << t_carPositionInfo.m_westCar << t_carPositionInfo.m_eastCar
        << t_carPositionInfo.m_carPositionX << t_carPositionInfo.m_carPositionY
        << t_carPositionInfo.m_zonePositionX << t_carPositionInfo.m_zonePositionY << endl;
    return dbg;
}

