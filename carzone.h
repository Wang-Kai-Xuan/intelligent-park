#ifndef CARZONE_H
#define CARZONE_H

#include <QWidget>
#include <QFont>

namespace Ui {
class CarZone;
}

class CarZone : public QWidget
{
    Q_OBJECT

public:
    explicit CarZone(QWidget *parent = 0);
    ~CarZone();

    void setCarLabelId(QString carLabelId, QString carLabelId_2, QString carLabelId_3,
                           QString carLabelId_4, QString carLabelId_5, QString carLabelId_6,
                           QString carLabelId_7, QString carLabelId_8,QString carLabelId_9,
                           QString carLabelId_10, QString carLabelId_11,QString carLabelId_12);
    void setCarLabelStatus(bool carLabelStatus, bool carLabelStatus_2, bool carLabelStatus_3,
                          bool carLabelStatus_4, bool carLabelStatus_5, bool carLabelStatus_6,
                          bool carLabelStatus_7, bool carLabelStatus_8, bool carLabelStatus_9,
                          bool carLabelStatus_10, bool carLabelStatus_11, bool carLabelStatus_12);
    void setCarLabelStatus(bool carLabelStatus);
    void setCarLabel_2Status(bool carLabelStatus_2);
    void setCarLabel_3Status(bool carLabelStatus_3);
    void setCarLabel_4Status(bool carLabelStatus_4);
    void setCarLabel_5Status(bool carLabelStatus_5);
    void setCarLabel_6Status(bool carLabelStatus_6);
    void setCarLabel_7Status(bool carLabelStatus_7);
    void setCarLabel_8Status(bool carLabelStatus_8);
    void setCarLabel_9Status(bool carLabelStatus_9);
    void setCarLabel_10Status(bool carLabelStatus_10);
    void setCarLabel_11Status(bool carLabelStatus_11);
    void setCarLabel_12Status(bool carLabelStatus_12);

private:
    Ui::CarZone *ui;

};

#endif // CARZONE_H
