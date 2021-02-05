#ifndef TRANSFORMMANAGER_H
#define TRANSFORMMANAGER_H

#include <memory>
#include "basescenemanager.h"
#include "visitor/transformvisitor.h"
#include "manager/transformmanager.h"

using namespace std;

class TransformManager : public BaseSceneManager
{
public:
    TransformManager(weak_ptr<BaseScene> _scene, double a, double b, double c);

    virtual void execute() = 0;
protected:
    double a, b, c;
};

class MoveManager : public TransformManager
{
public:
    MoveManager(weak_ptr<BaseScene> _scene, double a, double b, double c);
    void execute();
};

class ScaleManager : public TransformManager
{
public:
    ScaleManager(weak_ptr<BaseScene> _scene, double a, double b, double c);
    void execute();
};

class RotateManager : public TransformManager
{
public:
    RotateManager(weak_ptr<BaseScene> _scene, double a, double b, double c);
    void execute();
};

#endif // TRANSFORMMANAGER_H
