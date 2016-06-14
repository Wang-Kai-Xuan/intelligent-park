#include "carzone.h"
#include "ui_carzone.h"

CarZone::CarZone(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CarZone)
{
    ui->setupUi(this);

    this->setMinimumSize(180, 100);
    this->setMaximumSize(180, 100);

    ui->carLabel->setMaximumSize(40, 20);
    ui->carLabel->setMinimumSize(40, 20);

    ui->carLabel_2->setMaximumSize(40, 20);
    ui->carLabel_2->setMinimumSize(40, 20);

    ui->carLabel_3->setMaximumSize(40, 20);
    ui->carLabel_3->setMinimumSize(40, 20);

    ui->carLabel_4->setMaximumSize(40, 20);
    ui->carLabel_4->setMinimumSize(40, 20);

    ui->carLabel_5->setMaximumSize(40, 20);
    ui->carLabel_5->setMinimumSize(40, 20);

    ui->carLabel_6->setMaximumSize(40, 20);
    ui->carLabel_6->setMinimumSize(40, 20);

    ui->carLabel_7->setMaximumSize(40, 20);
    ui->carLabel_7->setMinimumSize(40, 20);

    ui->carLabel_8->setMaximumSize(40, 20);
    ui->carLabel_8->setMinimumSize(40, 20);

    ui->carLabel_9->setMaximumSize(40, 20);
    ui->carLabel_9->setMinimumSize(40, 20);

    ui->carLabel_10->setMaximumSize(40, 20);
    ui->carLabel_10->setMinimumSize(40, 20);

    ui->carLabel_11->setMaximumSize(40, 20);
    ui->carLabel_11->setMinimumSize(40, 20);

    ui->carLabel_12->setMaximumSize(40, 20);
    ui->carLabel_12->setMinimumSize(40, 20);
}

CarZone::~CarZone()
{
    delete ui;
}

void CarZone::setCarLabelId(QString carLabelId, QString carLabelId_2, QString carLabelId_3,
                                QString carLabelId_4, QString carLabelId_5, QString carLabelId_6,
                                QString carLabelId_7, QString carLabelId_8, QString carLabelId_9,
                                QString carLabelId_10, QString carLabelId_11, QString carLabelId_12)
{
    ui->carLabel->setText(carLabelId);
    ui->carLabel_2->setText(carLabelId_2);
    ui->carLabel_3->setText(carLabelId_3);
    ui->carLabel_4->setText(carLabelId_4);
    ui->carLabel_5->setText(carLabelId_5);
    ui->carLabel_6->setText(carLabelId_6);
    ui->carLabel_7->setText(carLabelId_7);
    ui->carLabel_8->setText(carLabelId_8);
    ui->carLabel_9->setText(carLabelId_9);
    ui->carLabel_10->setText(carLabelId_10);
    ui->carLabel_11->setText(carLabelId_11);
    ui->carLabel_12->setText(carLabelId_12);
}

void CarZone::setCarLabelStatus(bool carLabelStatus, bool carLabelStatus_2, bool carLabelStatus_3, bool carLabelStatus_4, bool carLabelStatus_5, bool carLabelStatus_6, bool carLabelStatus_7, bool carLabelStatus_8, bool carLabelStatus_9, bool carLabelStatus_10, bool carLabelStatus_11, bool carLabelStatus_12)
{
    setCarLabelStatus(carLabelStatus);
    setCarLabel_2Status(carLabelStatus_2);
    setCarLabel_3Status(carLabelStatus_3);
    setCarLabel_4Status(carLabelStatus_4);
    setCarLabel_5Status(carLabelStatus_5);
    setCarLabel_6Status(carLabelStatus_6);
    setCarLabel_7Status(carLabelStatus_7);
    setCarLabel_8Status(carLabelStatus_8);
    setCarLabel_9Status(carLabelStatus_9);
    setCarLabel_10Status(carLabelStatus_10);
    setCarLabel_11Status(carLabelStatus_11);
    setCarLabel_12Status(carLabelStatus_12);
}

void CarZone::setCarLabelStatus(bool carLabelStatus)
{
    if (carLabelStatus == false)
    {
        ui->carLabel->setStyleSheet("border-image: url(:/image/notcar.PNG);");
    }
    else
    {
        ui->carLabel->setStyleSheet("border-image: url(:/image/iscar.PNG);");
    }
}

void CarZone::setCarLabel_2Status(bool carLabelStatus_2)
{
    if (carLabelStatus_2 == false)
    {
        ui->carLabel_2->setStyleSheet("border-image: url(:/image/notcar.PNG);");
    }
    else
    {
        ui->carLabel_2->setStyleSheet("border-image: url(:/image/iscar.PNG);");
    }
}

void CarZone::setCarLabel_3Status(bool carLabelStatus_3)
{
    if (carLabelStatus_3 == false)
    {
        ui->carLabel_3->setStyleSheet("border-image: url(:/image/notcar.PNG);");
    }
    else
    {
        ui->carLabel_3->setStyleSheet("border-image: url(:/image/iscar.PNG);");
    }
}

void CarZone::setCarLabel_4Status(bool carLabelStatus_4)
{
    if (carLabelStatus_4 == false)
    {
        ui->carLabel_4->setStyleSheet("border-image: url(:/image/notcar.PNG);");
    }
    else
    {
        ui->carLabel_4->setStyleSheet("border-image: url(:/image/iscar.PNG);");
    }
}

void CarZone::setCarLabel_5Status(bool carLabelStatus_5)
{
    if (carLabelStatus_5 == false)
    {
        ui->carLabel_5->setStyleSheet("border-image: url(:/image/notcar.PNG);");
    }
    else
    {
        ui->carLabel_5->setStyleSheet("border-image: url(:/image/iscar.PNG);");
    }
}

void CarZone::setCarLabel_6Status(bool carLabelStatus_6)
{
    if (carLabelStatus_6 == false)
    {
        ui->carLabel_6->setStyleSheet("border-image: url(:/image/notcar.PNG);");
    }
    else
    {
        ui->carLabel_6->setStyleSheet("border-image: url(:/image/iscar.PNG);");
    }
}

void CarZone::setCarLabel_7Status(bool carLabelStatus_7)
{
    if (carLabelStatus_7 == false)
    {
        ui->carLabel_7->setStyleSheet("border-image: url(:/image/notcar.PNG);");
    }
    else
    {
        ui->carLabel_7->setStyleSheet("border-image: url(:/image/iscar.PNG);");
    }
}

void CarZone::setCarLabel_8Status(bool carLabelStatus_8)
{
    if (carLabelStatus_8 == false)
    {
        ui->carLabel_8->setStyleSheet("border-image: url(:/image/notcar.PNG);");
    }
    else
    {
        ui->carLabel_8->setStyleSheet("border-image: url(:/image/iscar.PNG);");
    }
}

void CarZone::setCarLabel_9Status(bool carLabelStatus_9)
{
    if (carLabelStatus_9 == false)
    {
        ui->carLabel_9->setStyleSheet("border-image: url(:/image/notcar.PNG);");
    }
    else
    {
        ui->carLabel_9->setStyleSheet("border-image: url(:/image/iscar.PNG);");
    }
}

void CarZone::setCarLabel_10Status(bool carLabelStatus_10)
{
    if (carLabelStatus_10 == false)
    {
        ui->carLabel_10->setStyleSheet("border-image: url(:/image/notcar.PNG);");
    }
    else
    {
        ui->carLabel_10->setStyleSheet("border-image: url(:/image/iscar.PNG);");
    }
}

void CarZone::setCarLabel_11Status(bool carLabelStatus_11)
{
    if (carLabelStatus_11 == false)
    {
        ui->carLabel_11->setStyleSheet("border-image: url(:/image/notcar.PNG);");
    }
    else
    {
        ui->carLabel_11->setStyleSheet("border-image: url(:/image/iscar.PNG);");
    }
}

void CarZone::setCarLabel_12Status(bool carLabelStatus_12)
{
    if (carLabelStatus_12 == false)
    {
        ui->carLabel_12->setStyleSheet("border-image: url(:/image/notcar.PNG);");
    }
    else
    {
        ui->carLabel_12->setStyleSheet("border-image: url(:/image/iscar.PNG);");
    }
}
