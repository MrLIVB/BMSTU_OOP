#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <memory>
#include "object/basecamera.h"
#include "object/point.h"
#include "drawerfactory.h"

using namespace std;

class Visualizer
{
public:
    Visualizer();
    ~Visualizer();

    void setDrawer(BaseDrawerFactory& factory);
    void setCamera(shared_ptr<BaseCamera> camera);

    void drawLine(const double x1, const double y1, const double z1,\
                  const double x2, const double y2, const double z2);
    void drawPoint(const double x, const double y, const double z);
    void clear();

protected:
    shared_ptr<Point> projectPoint(const double x, const double y, const double z);

private:
    shared_ptr<BaseDrawer> drawer;
    shared_ptr<BaseCamera> camera;
};

#endif // VISUALIZER_H
