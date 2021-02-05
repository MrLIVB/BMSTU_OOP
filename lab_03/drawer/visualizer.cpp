#include <math.h>
#include "visualizer.h"
#include "error.h"

Visualizer::Visualizer() {}
Visualizer::~Visualizer() {}

void Visualizer::setDrawer(BaseDrawerFactory &factory)
{
    drawer = shared_ptr<BaseDrawer>(factory.create());
}

void Visualizer::setCamera(shared_ptr<BaseCamera> camera)
{
    if (camera.get())
        this->camera = camera;
    else
        throw NocameraError("Set camera", __FILE__, __LINE__);
}

void Visualizer::drawLine(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2)
{
    Point p1(*projectPoint(x1, y1, z1));
    Point p2(*projectPoint(x2, y2, z2));

    drawer->drawLine(p1.getX(), p1.getY(), p2.getX(), p2.getY());
}

void Visualizer::drawPoint(const double x, const double y, const double z)
{
    Point p(*projectPoint(x, y, z));
    drawer->drawPoint(p.getX(), p.getY());
}

void Visualizer::clear()
{
    drawer->clear();
}

shared_ptr<Point> Visualizer::projectPoint(const double x, const double y, const double z)
{
    double k;
    if (fabs(camera->getZ() - z) < 1e-5)
            k = 1e20;
        else
            k = camera->getZ() / (camera->getZ() - z);

    double _x = camera->getX() + (x - camera->getX()) * k;
    double _y = camera->getY() + (y - camera->getY()) * k;
    return shared_ptr<Point>(new Point(_x, _y, 0));
}

//shared_ptr<Point> Visualizer::projectPoint(const double x, const double y, const double z)
//{
//    double _x = x - camera->getX();
//    double _y = y - camera->getY();
//    double _z = z - camera->getZ();

//    const int xSize = 840;
//    const int ySize = 720;
//    const double distance = camera->getZ();
//    double resultX = xSize / 2. + _x * distance / (_z + distance);
//    double resultY = ySize / 2. - _y * distance / (_z + distance);
//    return shared_ptr<Point>(new Point(resultX, resultY, 0));
//}
