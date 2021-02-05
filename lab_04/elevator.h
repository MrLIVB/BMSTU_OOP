#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>
#include "cabin.h"
#include "controller.h"

class Elevator : public QObject
{
    Q_OBJECT
public:
    Elevator();
    QWidget *getWidget();
private:
    Controller controller;
    Cabin cabin;
};

#endif // ELEVATOR_H
