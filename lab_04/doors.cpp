#include "doors.h"
#include <iostream>

Doors::Doors()
{
    state = OPENED;

    QObject::connect(&timerOpen, SIGNAL(timeout()), this, SLOT(opened()));
    QObject::connect(&timerClose, SIGNAL(timeout()), this, SLOT(closed()));
    QObject::connect(&timerWaitOpen, SIGNAL(timeout()), this, SLOT(closing()));
    QObject::connect(this, SIGNAL(startClosing()), this, SLOT(closing()));
}

void Doors::opened()
{
    if (state == OPENING)
    {
        state = OPENED;
        qDebug() << "Doors are opened  <    >";
        emit doorIsOpened();
        qDebug() << "Waiting           <    >";
        timerWaitOpen.start(waitingTIme);
    }
}

void Doors::closed()
{
    if (state == CLOSING)
    {
        state = CLOSED;
        qDebug() << "Doors are closed  --><--";
        emit doorIsClosed();
    }
}

void Doors::opening()
{
    if (state == CLOSED)
    {
        state = OPENING;
        qDebug() << "Doors are opening -<  >-";
        timerOpen.start(movingTime);
    }
    else if (state == CLOSING)
    {
        state = OPENING;
        qDebug() << "Doors are opening -<  >-";
        int t = timerClose.remainingTime();
        timerClose.stop();
        timerOpen.start(movingTime - t);
    }
}

void Doors::closing()
{
    if (state == OPENED)
    {
        state = CLOSING;
        qDebug() << "Doors are closing ->  <-";
        timerClose.start(movingTime);
    }
}
