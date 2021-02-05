#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>
#include <QVBoxLayout>
#include "mybutton.h"

class Controller : public QWidget
{
    Q_OBJECT
    enum controllerStates{
        NOTARGET,
        BUSY
    };

public:
    Controller();
    ~Controller();

signals:
    void sendTarget(int floor);
public slots:
    void getTarget(int target);
    void achieveFloor();
private:
    MyButton* buttons[5];
    QVBoxLayout *layout;
    int target;
    controllerStates state;
};

#endif // CONTROLLER_H
