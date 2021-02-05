#ifndef TRANSFORMVISITOR_H
#define TRANSFORMVISITOR_H

#include <memory>
#include "objectvisitor.h"

using namespace std;

class TransformVisitor : public ObjectVisitor
{
public:
    TransformVisitor(const double x, const double y, const double z);

protected:
    double p1;
    double p2;
    double p3;
};

class MoveVisitor : public TransformVisitor
{
public:
    MoveVisitor(const double x, const double y, const double z);

    void visit(shared_ptr<CompositeObject> obj) override;
    void visit(shared_ptr<FrameModel> model) override;
    void visit(shared_ptr<Camera> camera) override;
    void visit(Point& point) override;
};


class ScaleVisitor: public TransformVisitor
{
public:
    ScaleVisitor(const double x, const double y, const double z);

    void visit(shared_ptr<CompositeObject> obj) override;
    void visit(shared_ptr<FrameModel> model) override;
    void visit(shared_ptr<Camera> camera) override;
    void visit(Point& point) override;
};

class RotateVisitor: public TransformVisitor
{
public:
    RotateVisitor(const double x, const double y, const double z);

    void visit(shared_ptr<CompositeObject> obj) override;
    void visit(shared_ptr<FrameModel> model) override;
    void visit(shared_ptr<Camera> camera) override;
    void visit(Point& point) override;
protected:
    void rotateX(double& y, double& z, double a);
    void rotateY(double& x, double& z, double a);
    void rotateZ(double& x, double& y, double a);
};

#endif // TRANSFORMVISITOR_H
