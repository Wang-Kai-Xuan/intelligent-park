#ifndef PARKMAP_H
#define PARKMAP_H

#include <QWidget>

namespace Ui {
class ParkMap;
}

class ParkMap : public QWidget
{
    Q_OBJECT

public:
    explicit ParkMap(QWidget *parent = 0);
    ~ParkMap();

private:
    Ui::ParkMap *ui;
};

#endif // PARKMAP_H
