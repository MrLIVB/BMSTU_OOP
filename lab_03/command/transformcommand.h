#ifndef TRANSFORMCOMMAND_H
#define TRANSFORMCOMMAND_H

#include "basecommand.h"
#include "manager/transformmanager.h"

class TransformCommand : public BaseCommand
{
public:
    TransformCommand(const double x, const double y, const double z);
    virtual ~TransformCommand() = 0;

protected:
    double a, b, c;
};

class MoveCommand : public TransformCommand
{
public:
    MoveCommand(const double x, const double y, const double z);
    ~MoveCommand();

    void execute(weak_ptr<BaseScene> scene);
};

class ScaleCommand : public TransformCommand
{
public:
    ScaleCommand(const double x, const double y, const double z);
    ~ScaleCommand();

    void execute(weak_ptr<BaseScene> scene);
};

class RotateCommand : public TransformCommand
{
public:
    RotateCommand(const double x, const double y, const double z);
    ~RotateCommand();

    void execute(weak_ptr<BaseScene> scene);
};

#endif // TRANSFORMCOMMAND_H
