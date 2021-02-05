#ifndef BASEDRAWER_H
#define BASEDRAWER_H

class BaseDrawer
{
public:
    BaseDrawer();
    virtual ~BaseDrawer() = 0;

    virtual void drawLine(double x1, double y1, double x2, double y2) = 0;
    virtual void drawPoint(double x, double y) = 0;
    virtual void clear() = 0;
};

#endif // BASEDRAWER_H
