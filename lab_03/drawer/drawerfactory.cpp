#include "drawerfactory.h"

BaseDrawerFactory::BaseDrawerFactory() {}
BaseDrawerFactory::~BaseDrawerFactory() {}

QDrawerFactory::QDrawerFactory(weak_ptr<QGraphicsScene> _scene, const QPen &_pointPen, const QPen &_linePen):
    scene(_scene), pointPen(_pointPen), linePen(_linePen)
{

}

QDrawerFactory::~QDrawerFactory() {}

BaseDrawer* QDrawerFactory::create()
{
    return new QDrawer(scene, pointPen, linePen);
}
