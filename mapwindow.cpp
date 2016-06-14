#include "mapwindow.h"

MapWindow::MapWindow(QWidget *parent) :
    QWidget(parent)
{
    /* 布局 */
    m_mainLayout = new QVBoxLayout(this);
    m_leftVLayout = new QVBoxLayout;
    m_leftVLayout_2 = new QVBoxLayout;
    m_rightVLayout = new QVBoxLayout;
    m_rightVLayout_2 = new QVBoxLayout;
    m_centerVLayout = new QVBoxLayout;
    m_topHLayout = new QHBoxLayout;
    m_centerHLayout = new QHBoxLayout;
    m_bottomHLayout = new QHBoxLayout;

    /*A B C D E F区域*/
    m_carZone_A = new CarZone;

    m_carZone_B = new CarZone;
    m_carZone_B->setCarLabelId("B01", "B02", "B03",
                                   "B04", "B05", "B06",
                                   "B07", "B08", "B09",
                                   "B10", "B11", "B12");

    m_carZone_C = new CarZone;
    m_carZone_C->setCarLabelId("C01", "C02", "C03",
                                "C04", "C05", "C06",
                                "C07", "C08", "C09",
                                "C10", "C11", "C12");

    m_carZone_D = new CarZone;
    m_carZone_D->setCarLabelId("F09", "F10", "F11",
                                "F12", "F05", "F06",
                                "F07", "F08", "F01",
                                "F02", "F03", "F04");

    m_carZone_E = new CarZone;
    m_carZone_E->setCarLabelId("E09", "E10", "E11",
                                "E12", "E05", "E06",
                                "E07", "E08", "E01",
                                "E02", "E03", "E04");

    m_carZone_F = new CarZone;
    m_carZone_F->setCarLabelId("D09", "D10", "D11",
                                "D12", "D05", "D06",
                                "D07", "D08", "D01",
                                "D02", "D03", "D04");
    initAllCarZoneStatus();

    /* 停车场出入口 */
    m_outDoorLabel = new QLabel;
    m_outDoorLabel->setStyleSheet("border-image: url(:/image/outdoor.png);");
    m_outDoorLabel->setMaximumSize(80, 30);
    m_outDoorLabel->setMinimumSize(80, 30);

    m_outDoorLeftExitLabel = new QLabel;
    m_outDoorLeftExitLabel->setStyleSheet("border-image: url(:/image/exit.png);");
    m_outDoorLeftExitLabel->setMaximumSize(80, 30);
    m_outDoorLeftExitLabel->setMinimumSize(80, 30);

    m_outDoorRightExitLabel = new QLabel;
    m_outDoorRightExitLabel->setStyleSheet("border-image: url(:/image/exit_3.png);");
    m_outDoorRightExitLabel->setMaximumSize(80, 30);
    m_outDoorRightExitLabel->setMinimumSize(80, 30);

    /* 路线查询处 */
    m_localPositionLabel = new QLabel;
    m_localPositionLabel->setStyleSheet("border-image: url(:/image/localposition.png);");
    m_localPositionLabel->setMaximumSize(80, 30);
    m_localPositionLabel->setMinimumSize(80, 30);

    m_localPositionLeftExitLabel = new QLabel;
    m_localPositionLeftExitLabel->setStyleSheet("border-image: url(:/image/exit.png);");
    m_localPositionLeftExitLabel->setMaximumSize(80, 30);
    m_localPositionLeftExitLabel->setMinimumSize(80, 30);

    m_localPositionRightExitLabel = new QLabel;
    m_localPositionRightExitLabel->setStyleSheet("border-image: url(:/image/exit_3.png);");
    m_localPositionRightExitLabel->setMaximumSize(80, 30);
    m_localPositionRightExitLabel->setMinimumSize(80, 30);

    // 左侧
    m_leftExitLabel_3 = new QLabel;
    m_leftExitLabel_3->setStyleSheet("border-image: url(:/image/exit_2.png);");
    m_leftExitLabel_3->setMaximumSize(30, 80);
    m_leftExitLabel_3->setMinimumSize(30, 80);

    m_leftExitLabel_4 = new QLabel;
    m_leftExitLabel_4->setStyleSheet("border-image: url(:/image/exit_4.png);");
    m_leftExitLabel_4->setMaximumSize(30, 80);
    m_leftExitLabel_4->setMinimumSize(30, 80);

    m_leftExitLabel = new QLabel;
    m_leftExitLabel->setStyleSheet("border-image: url(:/image/exit.png);");
    m_leftExitLabel->setMaximumSize(80, 30);
    m_leftExitLabel->setMinimumSize(80, 30);

    m_leftExitLabel_2 = new QLabel;
    m_leftExitLabel_2->setStyleSheet("border-image: url(:/image/exit.png);");
    m_leftExitLabel_2->setMaximumSize(80, 30);
    m_leftExitLabel_2->setMinimumSize(80, 30);

    // 中间
    m_centerExitLabel = new QLabel;
    m_centerExitLabel->setStyleSheet("border-image: url(:/image/exit_4.png);");
    m_centerExitLabel->setMaximumSize(30, 80);
    m_centerExitLabel->setMinimumSize(30, 80);

    m_centerExitLabel_2 = new QLabel;
    m_centerExitLabel_2->setStyleSheet("border-image: url(:/image/exit_4.png);");
    m_centerExitLabel_2->setMaximumSize(30, 80);
    m_centerExitLabel_2->setMinimumSize(30, 80);

    m_centerExitLabel_3 = new QLabel;
    m_centerExitLabel_3->setStyleSheet("border-image: url(:/image/exit_4.png);");
    m_centerExitLabel_3->setMaximumSize(30, 80);
    m_centerExitLabel_3->setMinimumSize(30, 80);

    // 右侧
    m_rightExitLabel_3 = new QLabel;
    m_rightExitLabel_3->setStyleSheet("border-image: url(:/image/exit_2.png);");
    m_rightExitLabel_3->setMaximumSize(30, 80);
    m_rightExitLabel_3->setMinimumSize(30, 80);

    m_rightExitLabel_4 = new QLabel;
    m_rightExitLabel_4->setStyleSheet("border-image: url(:/image/exit_4.png);");
    m_rightExitLabel_4->setMaximumSize(30, 80);
    m_rightExitLabel_4->setMinimumSize(30, 80);

    m_rightExitLabel = new QLabel;
    m_rightExitLabel->setStyleSheet("border-image: url(:/image/exit_3.png);");
    m_rightExitLabel->setMaximumSize(80, 30);
    m_rightExitLabel->setMinimumSize(80, 30);

    m_rightExitLabel_2 = new QLabel;
    m_rightExitLabel_2->setStyleSheet("border-image: url(:/image/exit_3.png);");
    m_rightExitLabel_2->setMaximumSize(80, 30);
    m_rightExitLabel_2->setMinimumSize(80, 30);

    /* 中间位置 */
    m_leftVLayout_2->addWidget(m_leftExitLabel_3, 0, Qt::AlignCenter);
    m_leftVLayout_2->addWidget(m_leftExitLabel_4, 0, Qt::AlignCenter);

    m_leftVLayout->addWidget(m_carZone_C, 0, Qt::AlignCenter);
    m_leftVLayout->addWidget(m_leftExitLabel, 0, Qt::AlignCenter);
    m_leftVLayout->addWidget(m_carZone_B, 0, Qt::AlignCenter);
    m_leftVLayout->addWidget(m_leftExitLabel_2, 0, Qt::AlignCenter);
    m_leftVLayout->addWidget(m_carZone_A, 0, Qt::AlignCenter);

    m_centerVLayout->addWidget(m_centerExitLabel, 0, Qt::AlignCenter);
    m_centerVLayout->addWidget(m_centerExitLabel_2, 0, Qt::AlignCenter);
    m_centerVLayout->addWidget(m_centerExitLabel_3, 0, Qt::AlignCenter);

    m_rightVLayout_2->addWidget(m_rightExitLabel_3, 0, Qt::AlignCenter);
    m_rightVLayout_2->addWidget(m_rightExitLabel_4, 0, Qt::AlignCenter);

    m_rightVLayout->addWidget(m_carZone_F, 0, Qt::AlignCenter);
    m_rightVLayout->addWidget(m_rightExitLabel, 0, Qt::AlignCenter);
    m_rightVLayout->addWidget(m_carZone_E, 0, Qt::AlignCenter);
    m_rightVLayout->addWidget(m_rightExitLabel_2, 0, Qt::AlignCenter);
    m_rightVLayout->addWidget(m_carZone_D, 0, Qt::AlignCenter);

    m_centerHLayout->addLayout(m_leftVLayout_2);
    m_centerHLayout->addLayout(m_leftVLayout);
    m_centerHLayout->addLayout(m_centerVLayout);
    m_centerHLayout->addLayout(m_rightVLayout);
    m_centerHLayout->addLayout(m_rightVLayout_2);

    /* 顶部 */
    m_topHLayout->addWidget(m_localPositionLeftExitLabel, 0, Qt::AlignCenter);
    m_topHLayout->addWidget(m_localPositionLabel, 0, Qt::AlignCenter);
    m_topHLayout->addWidget(m_localPositionRightExitLabel, 0, Qt::AlignCenter);

    /* 底部 */
    m_bottomHLayout->addWidget(m_outDoorLeftExitLabel, 0, Qt::AlignCenter);
    m_bottomHLayout->addWidget(m_outDoorLabel, 0, Qt::AlignCenter);
    m_bottomHLayout->addWidget(m_outDoorRightExitLabel, 0, Qt::AlignCenter);

    m_mainLayout->addLayout(m_topHLayout);
    m_mainLayout->addLayout(m_centerHLayout);
    m_mainLayout->addLayout(m_bottomHLayout);

    //this->setMinimumSize(900, 500);
    //this->setMaximumSize(900, 500);
}

MapWindow::~MapWindow()
{

}

void MapWindow::initAllCarZoneStatus()
{
    m_carZone_A->setCarLabelStatus(false, false, false,
                                   false, false, false,
                                   false, false, false,
                                   false, false, false);
    m_carZone_B->setCarLabelStatus(false, false, false,
                                   false, false, false,
                                   false, false, false,
                                   false, false, false);
    m_carZone_C->setCarLabelStatus(false, false, false,
                                   false, false, false,
                                   false, false, false,
                                   false, false, false);
    m_carZone_D->setCarLabelStatus(false, false, false,
                                   false, false, false,
                                   false, false, false,
                                   false, false, false);
    m_carZone_E->setCarLabelStatus(false, false, false,
                                   false, false, false,
                                   false, false, false,
                                   false, false, false);
    m_carZone_F->setCarLabelStatus(false, false, false,
                                   false, false, false,
                                   false, false, false,
                                   false, false, false);
}

void MapWindow::setCarZone_A(QString t_carId, bool t_carLabelStatus)
{
    if (t_carId == "A01")
    {
        this->m_carZone_A->setCarLabelStatus(t_carLabelStatus);
    }
    if (t_carId == "A02")
    {
        this->m_carZone_A->setCarLabel_2Status(t_carLabelStatus);
    }
    if (t_carId == "A03")
    {
        this->m_carZone_A->setCarLabel_3Status(t_carLabelStatus);
    }
    if (t_carId == "A04")
    {
        this->m_carZone_A->setCarLabel_4Status(t_carLabelStatus);
    }
    if (t_carId == "A05")
    {
        this->m_carZone_A->setCarLabel_5Status(t_carLabelStatus);
    }
    if (t_carId == "A06")
    {
        this->m_carZone_A->setCarLabel_6Status(t_carLabelStatus);
    }
    if (t_carId == "A07")
    {
        this->m_carZone_A->setCarLabel_7Status(t_carLabelStatus);
    }
    if (t_carId == "A08")
    {
        this->m_carZone_A->setCarLabel_8Status(t_carLabelStatus);
    }
    if (t_carId == "A09")
    {
        this->m_carZone_A->setCarLabel_9Status(t_carLabelStatus);
    }
    if (t_carId == "A10")
    {
        this->m_carZone_A->setCarLabel_10Status(t_carLabelStatus);
    }
    if (t_carId == "A11")
    {
        this->m_carZone_A->setCarLabel_11Status(t_carLabelStatus);
    }
    if (t_carId == "A12")
    {
        this->m_carZone_A->setCarLabel_12Status(t_carLabelStatus);
    }
}

void MapWindow::setCarZone_B(QString t_carId, bool t_carLabelStatus)
{
    if (t_carId == "B01")
    {
        this->m_carZone_B->setCarLabelStatus(t_carLabelStatus);
    }
    if (t_carId == "B02")
    {
        this->m_carZone_B->setCarLabel_2Status(t_carLabelStatus);
    }
    if (t_carId == "B03")
    {
        this->m_carZone_B->setCarLabel_3Status(t_carLabelStatus);
    }
    if (t_carId == "B04")
    {
        this->m_carZone_B->setCarLabel_4Status(t_carLabelStatus);
    }
    if (t_carId == "B05")
    {
        this->m_carZone_B->setCarLabel_5Status(t_carLabelStatus);
    }
    if (t_carId == "B06")
    {
        this->m_carZone_B->setCarLabel_6Status(t_carLabelStatus);
    }
    if (t_carId == "B07")
    {
        this->m_carZone_B->setCarLabel_7Status(t_carLabelStatus);
    }
    if (t_carId == "B08")
    {
        this->m_carZone_B->setCarLabel_8Status(t_carLabelStatus);
    }
    if (t_carId == "B09")
    {
        this->m_carZone_B->setCarLabel_9Status(t_carLabelStatus);
    }
    if (t_carId == "B10")
    {
        this->m_carZone_B->setCarLabel_10Status(t_carLabelStatus);
    }
    if (t_carId == "B11")
    {
        this->m_carZone_B->setCarLabel_11Status(t_carLabelStatus);
    }
    if (t_carId == "B12")
    {
        this->m_carZone_B->setCarLabel_12Status(t_carLabelStatus);
    }
}

void MapWindow::setCarZone_C(QString t_carId, bool t_carLabelStatus)
{
    if (t_carId == "C01")
    {
        this->m_carZone_C->setCarLabelStatus(t_carLabelStatus);
    }
    if (t_carId == "C02")
    {
        this->m_carZone_C->setCarLabel_2Status(t_carLabelStatus);
    }
    if (t_carId == "C03")
    {
        this->m_carZone_C->setCarLabel_3Status(t_carLabelStatus);
    }
    if (t_carId == "C04")
    {
        this->m_carZone_C->setCarLabel_4Status(t_carLabelStatus);
    }
    if (t_carId == "C05")
    {
        this->m_carZone_C->setCarLabel_5Status(t_carLabelStatus);
    }
    if (t_carId == "C06")
    {
        this->m_carZone_C->setCarLabel_6Status(t_carLabelStatus);
    }
    if (t_carId == "C07")
    {
        this->m_carZone_C->setCarLabel_7Status(t_carLabelStatus);
    }
    if (t_carId == "C08")
    {
        this->m_carZone_C->setCarLabel_8Status(t_carLabelStatus);
    }
    if (t_carId == "C09")
    {
        this->m_carZone_C->setCarLabel_9Status(t_carLabelStatus);
    }
    if (t_carId == "C10")
    {
        this->m_carZone_C->setCarLabel_10Status(t_carLabelStatus);
    }
    if (t_carId == "C11")
    {
        this->m_carZone_C->setCarLabel_11Status(t_carLabelStatus);
    }
    if (t_carId == "C12")
    {
        this->m_carZone_C->setCarLabel_12Status(t_carLabelStatus);
    }
}

void MapWindow::setCarZone_D(QString t_carId, bool t_carLabelStatus)
{
    if (t_carId == "D01")
    {
        this->m_carZone_D->setCarLabel_9Status(t_carLabelStatus);
    }
    if (t_carId == "D02")
    {
        this->m_carZone_D->setCarLabel_10Status(t_carLabelStatus);
    }
    if (t_carId == "D03")
    {
        this->m_carZone_D->setCarLabel_11Status(t_carLabelStatus);
    }
    if (t_carId == "D04")
    {
        this->m_carZone_D->setCarLabel_12Status(t_carLabelStatus);
    }
    if (t_carId == "D05")
    {
        this->m_carZone_D->setCarLabel_5Status(t_carLabelStatus);
    }
    if (t_carId == "D06")
    {
        this->m_carZone_D->setCarLabel_6Status(t_carLabelStatus);
    }
    if (t_carId == "D07")
    {
        this->m_carZone_D->setCarLabel_7Status(t_carLabelStatus);
    }
    if (t_carId == "D08")
    {
        this->m_carZone_D->setCarLabel_8Status(t_carLabelStatus);
    }
    if (t_carId == "D09")
    {
        this->m_carZone_D->setCarLabelStatus(t_carLabelStatus);
    }
    if (t_carId == "D10")
    {
        this->m_carZone_D->setCarLabel_2Status(t_carLabelStatus);
    }
    if (t_carId == "D11")
    {
        this->m_carZone_D->setCarLabel_3Status(t_carLabelStatus);
    }
    if (t_carId == "D12")
    {
        this->m_carZone_D->setCarLabel_4Status(t_carLabelStatus);
    }
}

void MapWindow::setCarZone_E(QString t_carId, bool t_carLabelStatus)
{
    if (t_carId == "E01")
    {
        this->m_carZone_E->setCarLabel_9Status(t_carLabelStatus);
    }
    if (t_carId == "E02")
    {
        this->m_carZone_E->setCarLabel_10Status(t_carLabelStatus);
    }
    if (t_carId == "E03")
    {
        this->m_carZone_E->setCarLabel_11Status(t_carLabelStatus);
    }
    if (t_carId == "E04")
    {
        this->m_carZone_E->setCarLabel_12Status(t_carLabelStatus);
    }
    if (t_carId == "E05")
    {
        this->m_carZone_E->setCarLabel_5Status(t_carLabelStatus);
    }
    if (t_carId == "E06")
    {
        this->m_carZone_E->setCarLabel_6Status(t_carLabelStatus);
    }
    if (t_carId == "E07")
    {
        this->m_carZone_E->setCarLabel_7Status(t_carLabelStatus);
    }
    if (t_carId == "E08")
    {
        this->m_carZone_E->setCarLabel_8Status(t_carLabelStatus);
    }
    if (t_carId == "E09")
    {
        this->m_carZone_E->setCarLabelStatus(t_carLabelStatus);
    }
    if (t_carId == "E10")
    {
        this->m_carZone_E->setCarLabel_2Status(t_carLabelStatus);
    }
    if (t_carId == "E11")
    {
        this->m_carZone_E->setCarLabel_3Status(t_carLabelStatus);
    }
    if (t_carId == "E12")
    {
        this->m_carZone_E->setCarLabel_4Status(t_carLabelStatus);
    }
}

void MapWindow::setCarZone_F(QString t_carId, bool t_carLabelStatus)
{
    if (t_carId == "F01")
    {
        this->m_carZone_F->setCarLabel_9Status(t_carLabelStatus);
    }
    if (t_carId == "F02")
    {
        this->m_carZone_D->setCarLabel_10Status(t_carLabelStatus);
    }
    if (t_carId == "F03")
    {
        this->m_carZone_F->setCarLabel_11Status(t_carLabelStatus);
    }
    if (t_carId == "F04")
    {
        this->m_carZone_F->setCarLabel_12Status(t_carLabelStatus);
    }
    if (t_carId == "F05")
    {
        this->m_carZone_F->setCarLabel_5Status(t_carLabelStatus);
    }
    if (t_carId == "F06")
    {
        this->m_carZone_F->setCarLabel_6Status(t_carLabelStatus);
    }
    if (t_carId == "F07")
    {
        this->m_carZone_F->setCarLabel_7Status(t_carLabelStatus);
    }
    if (t_carId == "F08")
    {
        this->m_carZone_F->setCarLabel_8Status(t_carLabelStatus);
    }
    if (t_carId == "F09")
    {
        this->m_carZone_F->setCarLabelStatus(t_carLabelStatus);
    }
    if (t_carId == "F10")
    {
        this->m_carZone_F->setCarLabel_2Status(t_carLabelStatus);
    }
    if (t_carId == "F11")
    {
        this->m_carZone_F->setCarLabel_3Status(t_carLabelStatus);
    }
    if (t_carId == "F12")
    {
        this->m_carZone_F->setCarLabel_4Status(t_carLabelStatus);
    }
}

