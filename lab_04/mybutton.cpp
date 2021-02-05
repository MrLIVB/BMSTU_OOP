#include "mybutton.h"

#include <qdebug.h>

MyButton::MyButton()
{
    state = NOTPRESSED;

    QObject::connect(this, SIGNAL(clicked()), this, SLOT(pressed()));
    QObject::connect(this, SIGNAL(resetButton()), this, SLOT(reseted()));
}

void MyButton::setFloor(int floor)
{
    floorNumber = floor;
}

buttonStates MyButton::getState()
{
    return state;
}

void MyButton::pressed()
{
    if (state == NOTPRESSED)
    {
        setEnabled(false);
        state = PRESSED;
        emit floorRequest(floorNumber);
    }
}

void MyButton::reseted()
{
    if (state == PRESSED)
    {
        setEnabled(true);
        state = NOTPRESSED;
    }
}
