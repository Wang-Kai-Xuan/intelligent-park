#include "floormap.h"
#include "ui_floormap.h"

FloorMap::FloorMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FloorMap)
{
    ui->setupUi(this);
}

FloorMap::~FloorMap()
{
    delete ui;
}
