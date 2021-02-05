#include "controller.h"

#include <iostream>
#include <qdebug.h>

Controller::Controller()
{
    layout = new QVBoxLayout;
    state = NOTARGET;
    target = 0;
    this->setLayout(layout);
    for (int i = 0; i < 5; i++)
    {
        buttons[i] = new MyButton;
        layout->addWidget(dynamic_cast<QPushButton*>(buttons[i]));
        buttons[i]->setText(QString::number(i + 1));
        buttons[i]->setFloor(i);
        QObject::connect(buttons[i], SIGNAL(floorRequest(int)), this, SLOT(getTarget(int)));
    }
}

Controller::~Controller()
{
    for (int i = 0; i < 5; i++)
        delete buttons[i];
    delete layout;
}

void Controller::getTarget(int target)
{
    if (state == NOTARGET)
    {
        state = BUSY;
        emit sendTarget(target);
    }
}

void Controller::achieveFloor()
{
    if (state == BUSY)
    {
        state = NOTARGET;
        emit buttons[target]->resetButton();
    }
}
