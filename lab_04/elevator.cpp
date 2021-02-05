#include "elevator.h"

Elevator::Elevator()
{
    connect(&controller, SIGNAL(sendTarget(int)), &cabin, SLOT(busy(int)));
    connect(&cabin, SIGNAL(floorAchived(int)), &controller, SLOT(achieveFloor()));
}

QWidget *Elevator::getWidget()
{
    return &controller;
}
