#include "drawer.h"
#include "error.h"

QDrawer::QDrawer(weak_ptr<QGraphicsScene> _scene, const QPen &_pointPen, const QPen &_linePen):
    scene(_scene), pointPen(_pointPen), linePen(_linePen)
{
    pointBrush = QBrush(linePen.color());
}

QDrawer::~QDrawer() {}

void QDrawer::drawLine(double x1, double y1, double x2, double y2)
{
    if (scene.expired())
        throw SceneExpiredError("Draw line", __FILE__, __LINE__);
    shared_ptr<QGraphicsScene> proc = scene.lock();
    proc->addLine(x1, y1, x2, y2, linePen);
}

void QDrawer::drawPoint(double x, double y)
{
    if (scene.expired())
        throw SceneExpiredError("Draw line", __FILE__, __LINE__);
    shared_ptr<QGraphicsScene> proc = scene.lock();
    proc->addEllipse(x-2, y-2, 4, 4, pointPen, pointBrush);
}

void QDrawer::clear()
{
    if (scene.expired())
        throw SceneExpiredError("Draw line", __FILE__, __LINE__);
    shared_ptr<QGraphicsScene> proc = scene.lock();
    proc->clear();
}
