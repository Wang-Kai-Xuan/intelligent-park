#include "parkmap.h"
#include "ui_parkmap.h"

ParkMap::ParkMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParkMap)
{
    ui->setupUi(this);
}

ParkMap::~ParkMap()
{
    delete ui;
}
