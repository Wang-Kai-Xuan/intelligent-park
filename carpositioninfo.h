#ifndef CARPOSITIONINFO_H
#define CARPOSITIONINFO_H

#include <QString>
#include <QDebug>

class CarPositionInfo
{
public:
    CarPositionInfo();
    ~CarPositionInfo();

    /* 设置成员变量的值 */
    void setCarId(QString t_carId);

    void setRfidId(QString t_rfidId);

    void setZoneId(QString t_zoneId);

    void setNorthCar(QString t_northCar);

    void setSouthCar(QString t_southCar);

    void setWestCar(QString t_northCar);

    void setEastCar(QString t_southCar);

    void setCarPositionX(int t_carPositionX);

    void setCarPositionY(int t_carPositionY);

    void setZonePositionX(int t_zonePositionX);

    void setZonePositionY(int t_zonePositionY);

    /* 获取成员变量的值 */
    QString getCarId() const;

    QString getRfidId() const;

    QString getZoneId() const;

    QString getNorthCar() const;

    QString getSouthCar() const;

    QString getWestCar() const;

    QString getEastCar() const;

    int getCarPositionX() const;

    int getCarPositionY() const;

    int getZonePositionX() const;

    int getZonePositionY() const;

    /* 清除变量值 */
    void clear();

    /* 重载赋值运算符 */
    CarPositionInfo & operator = (const CarPositionInfo & t_carPositionInfo);

    friend QDebug operator << (QDebug dbg, const CarPositionInfo & t_carPositionInfo );

private:
    QString m_carId;

    QString m_rfidId;

    QString m_zoneId;

    QString m_northCar;

    QString m_southCar;

    QString m_westCar; // 西

    QString m_eastCar; // 东

    int m_carPositionX;

    int m_carPositionY;

    int m_zonePositionX;

    int m_zonePositionY;
};

#endif // CARPOSITIONINFO_H
