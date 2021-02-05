#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include "times.h"

class Doors : public QObject
{
    Q_OBJECT
    enum doorsState {
        CLOSING,
        OPENING,
        CLOSED,
        OPENED
    };
private:
    const int movingTime = DOORTIME;
    const int waitingTIme = WAITINGTIME;
    doorsState state;

    QTimer timerOpen;
    QTimer timerClose;
    QTimer timerWaitOpen;

public:
    explicit Doors();
    doorsState getState() {return state;}

signals:
    void doorIsClosed();
    void doorIsOpened();
    void stopOpening();
    void startClosing();

public slots:
   void opened();
   void closed();

private slots:
   void opening();
   void closing();
};

#endif // DOORS_H
