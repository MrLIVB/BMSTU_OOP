#include "cabin.h"

#include <iostream>

Cabin::Cabin()
{
    state = STILL;
    currentFloor = 0;
    targetFloor = 0;
    direction = 0;

    QObject::connect(&door, SIGNAL(doorIsClosed()), this, SLOT(moving()));
    QObject::connect(&timerMove, SIGNAL(timeout()), this, SLOT(moving()));
    QObject::connect(this, SIGNAL(floorAchived(int)), &door, SLOT(opening()));
    QObject::connect(&door, SIGNAL(doorIsOpened()), this, SLOT(free()));
}

void Cabin::free()
{
    if (state == MOVING)
    {
        state = STILL;
        qDebug() << "Elevator free\n";
    }
}

void Cabin::busy(int floor)
{
    if (state == STILL)
    {
        state = BUSY;
        targetFloor = floor;
        if (currentFloor < targetFloor)
            direction = 1;
        else
            direction = -1;
        emit door.startClosing();
    }
}

void Cabin::moving()
{
    if (state == BUSY)
    {
        state = MOVING;
        qDebug() << "Start moving to: " << (targetFloor + 1) << "\nfrom:" << (currentFloor + 1);
        if (currentFloor == targetFloor)
            emit floorAchived(currentFloor);
        else
            timerMove.start(floorTime);
    }
    else if (state == MOVING)
    {
        currentFloor += direction;
        qDebug() << "Moving, current floor: " << (currentFloor + 1);

        if (currentFloor == targetFloor){
            qDebug() << "Floor achieved";
            emit floorAchived(currentFloor);
        }
        else
            timerMove.start(floorTime);
    }
}
