#include "transformcommand.h"

TransformCommand::TransformCommand(const double x, const double y, const double z)
{
    this->a = x;
    this->b = y;
    this->c = z;
}

TransformCommand::~TransformCommand() {}

MoveCommand::MoveCommand(const double x, const double y, const double z):
    TransformCommand(x, y, z) {}

MoveCommand::~MoveCommand() {}

void MoveCommand::execute(weak_ptr<BaseScene> scene)
{
    MoveManager(scene, a, b, c).execute();
}


ScaleCommand::ScaleCommand(const double x, const double y, const double z):
    TransformCommand(x, y, z) {}

ScaleCommand::~ScaleCommand() {}

void ScaleCommand::execute(weak_ptr<BaseScene> scene)
{
    ScaleManager(scene, a, b, c).execute();
}

RotateCommand::RotateCommand(const double x, const double y, const double z):
    TransformCommand(x, y, z) {}

RotateCommand::~RotateCommand() {}

void RotateCommand::execute(weak_ptr<BaseScene> scene)
{
    RotateManager(scene, a, b, c).execute();
}
