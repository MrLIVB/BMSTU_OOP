#ifndef DRAWER_H
#define DRAWER_H

#include <QGraphicsScene>
#include <memory>
#include "basedrawer.h"

using namespace std;

class QDrawer: public BaseDrawer
{
public:
    QDrawer(weak_ptr<QGraphicsScene> _scene, const QPen& _pointPen,\
            const QPen& _linePen);
    ~QDrawer();

    void drawLine(double x1, double y1, double x2, double y2);
    void drawPoint(double x, double y);
    void clear();
private:
    weak_ptr<QGraphicsScene> scene;
    QPen pointPen, linePen;
    QBrush pointBrush;
};

#endif // DRAWER_H
