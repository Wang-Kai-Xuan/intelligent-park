#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QDebug>
#include "carzone.h"

class MapWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MapWindow(QWidget *parent = 0);
    ~MapWindow();

    void initAllCarZoneStatus();

    void setCarZone_A(QString t_carId, bool t_carStatus);

    void setCarZone_B(QString t_carId, bool t_carStatus);

    void setCarZone_C(QString t_carId, bool t_carStatus);

    void setCarZone_D(QString t_carId, bool t_carStatus);

    void setCarZone_E(QString t_carId, bool t_carStatus);

    void setCarZone_F(QString t_carId, bool t_carStatus);

private:
    CarZone *m_carZone_A;
    CarZone *m_carZone_B;
    CarZone *m_carZone_C;
    CarZone *m_carZone_D;
    CarZone *m_carZone_E;
    CarZone *m_carZone_F;

    QLabel *m_outDoorLabel;
    QLabel *m_outDoorLeftExitLabel;
    QLabel *m_outDoorRightExitLabel;
    QLabel *m_localPositionLabel;
    QLabel *m_localPositionLeftExitLabel;
    QLabel *m_localPositionRightExitLabel;

    QLabel *m_leftExitLabel;
    QLabel *m_leftExitLabel_2;
    QLabel *m_leftExitLabel_3;
    QLabel *m_leftExitLabel_4;
    QLabel *m_centerExitLabel;
    QLabel *m_centerExitLabel_2;
    QLabel *m_centerExitLabel_3;
    QLabel *m_rightExitLabel;
    QLabel *m_rightExitLabel_2;
    QLabel *m_rightExitLabel_3;
    QLabel *m_rightExitLabel_4;

    QVBoxLayout *m_mainLayout;
    QVBoxLayout *m_leftVLayout; // A B C区
    QVBoxLayout *m_leftVLayout_2;
    QVBoxLayout *m_rightVLayout; // F E D区
    QVBoxLayout *m_rightVLayout_2;
    QVBoxLayout *m_centerVLayout;
    QHBoxLayout *m_topHLayout;
    QHBoxLayout *m_centerHLayout;
    QHBoxLayout *m_bottomHLayout;

};

#endif // MAPWINDOW_H
