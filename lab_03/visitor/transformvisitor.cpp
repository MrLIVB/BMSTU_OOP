#include "transformvisitor.h"
#include <math.h>

TransformVisitor::TransformVisitor(const double x, const double y, const double z)
{
    this->p1 = x;
    this->p2 = y;
    this->p3 = z;
}

MoveVisitor::MoveVisitor(const double x, const double y, const double z) : TransformVisitor(x, y, z)
{}

void MoveVisitor::visit(shared_ptr<CompositeObject> obj)
{
    for (auto cur: *(obj.get()))
        cur->accept(this);
}

void MoveVisitor::visit(shared_ptr<FrameModel> model)
{
    model->accept(this);
}

void MoveVisitor::visit(shared_ptr<Camera> camera)
{
    double x = camera->getX();
    double y = camera->getY();
    double z = camera->getZ();

    x += p1;
    y += p2;
    z += p3;

    camera->setX(x);
    camera->setY(y);
    camera->setZ(z);
}

void MoveVisitor::visit(Point &point)
{
    double x = point.getX();
    double y = point.getY();
    double z = point.getZ();

    x += p1;
    y += p2;
    z += p3;

    point.setX(x);
    point.setY(y);
    point.setZ(z);
}



ScaleVisitor::ScaleVisitor(const double x, const double y, const double z) : TransformVisitor(x, y, z)
{}

void ScaleVisitor::visit(shared_ptr<CompositeObject> obj)
{
    for (auto cur: *(obj.get()))
        cur->accept(this);
}

void ScaleVisitor::visit(shared_ptr<FrameModel> model)
{
    model->accept(this);
}

void ScaleVisitor::visit(shared_ptr<Camera> camera)
{
    double x = camera->getX();
    double y = camera->getY();
    double z = camera->getZ();

    x *= p1;
    y *= p2;
    z *= p3;

    camera->setX(x);
    camera->setY(y);
    camera->setZ(z);
}

void ScaleVisitor::visit(Point &point)
{
    double x = point.getX();
    double y = point.getY();
    double z = point.getZ();

    x *= p1;
    y *= p2;
    z *= p3;

    point.setX(x);
    point.setY(y);
    point.setZ(z);
}



RotateVisitor::RotateVisitor(const double x, const double y, const double z) : TransformVisitor(x, y, z)
{}

void RotateVisitor::visit(shared_ptr<CompositeObject> obj)
{
    for (auto cur: *(obj.get()))
        cur->accept(this);
}

void RotateVisitor::visit(shared_ptr<FrameModel> model)
{
    model->accept(this);
}

void RotateVisitor::visit(shared_ptr<Camera> camera)
{
    double x = camera->getX();
    double y = camera->getY();
    double z = camera->getZ();

    rotateX(y, z, p1);
    rotateY(x, z, p2);
    rotateZ(x, y, p3);

    camera->setX(x);
    camera->setY(y);
    camera->setZ(z);
}

void RotateVisitor::visit(Point &point)
{
    double x = point.getX();
    double y = point.getY();
    double z = point.getZ();

    rotateX(y, z, p1);
    rotateY(x, z, p2);
    rotateZ(x, y, p3);

    point.setX(x);
    point.setY(y);
    point.setZ(z);
}

void RotateVisitor::rotateX(double &y, double &z, double a)
{
    double _y = y * cos(a) - z * sin(a);
    double _z = y * sin(a) + z * cos(a);
    y = _y;
    z = _z;
}

void RotateVisitor::rotateY(double &x, double &z, double a)
{
    double _x = x * cos(a) + z * sin(a);
    double _z = -x * sin(a) + z * cos(a);
    x = _x;
    z = _z;
}

void RotateVisitor::rotateZ(double &x, double &y, double a)
{
    float _x = x * cos(a) - y * sin(a);
    float _y = x * sin(a) + y * cos(a);
    x = _x;
    y = _y;
}
