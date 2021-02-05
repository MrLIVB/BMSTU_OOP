#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QObject>
#include <QPushButton>

enum buttonStates{
    PRESSED,
    NOTPRESSED
};

class MyButton : public QPushButton
{
    Q_OBJECT

public:
    MyButton();
    void setFloor(int floor);
    buttonStates getState();

public slots:
    void pressed();
    void reseted();

signals:
    void resetButton();
    void floorRequest(int floor);

private:
    buttonStates state;
    int floorNumber;
};

#endif // MYBUTTON_H
