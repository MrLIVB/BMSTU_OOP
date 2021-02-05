#ifndef DRAWERFACTORY_H
#define DRAWERFACTORY_H

#include <memory>
#include "drawer.h"

using namespace std;
class BaseDrawerFactory
{
public:
    BaseDrawerFactory();
    virtual ~BaseDrawerFactory() = 0;

    virtual BaseDrawer* create() = 0;
};

class QDrawerFactory : public BaseDrawerFactory
{
public:
    QDrawerFactory(weak_ptr<QGraphicsScene> _scene, const QPen& _pointPen,\
                   const QPen& _linePen);
    ~QDrawerFactory();

    BaseDrawer* create();
private:
    weak_ptr<QGraphicsScene> scene;
    QPen pointPen, linePen;
};

#endif // DRAWERFACTORY_H
