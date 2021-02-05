#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include "doors.h"
#include "times.h"

class Cabin : public QObject
{
    Q_OBJECT
    enum cabinStates{
        MOVING,
        BUSY,
        STILL
    };

public:
    Cabin();

public slots:
    void free();
    void busy(int floor);
    void moving();

signals:
    void floorAchived(int floor);

private:
    int currentFloor = 0;
    int targetFloor;
    const int floorTime = FLOORTIME;
    int direction;

    cabinStates state;
    QTimer timerMove;

    Doors door;
};

#endif // CABIN_H
