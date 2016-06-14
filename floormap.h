#ifndef FLOORMAP_H
#define FLOORMAP_H

#include <QWidget>

namespace Ui {
class FloorMap;
}

class FloorMap : public QWidget
{
    Q_OBJECT

public:
    explicit FloorMap(QWidget *parent = 0);
    ~FloorMap();

private:
    Ui::FloorMap *ui;
};

#endif // FLOORMAP_H
