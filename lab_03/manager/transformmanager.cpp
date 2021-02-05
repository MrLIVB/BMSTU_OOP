#include "transformmanager.h"

TransformManager::TransformManager(weak_ptr<BaseScene> _scene, double a, double b, double c) : BaseSceneManager(_scene)
{
    this->a = a;
    this->b = b;
    this->c = c;
}


MoveManager::MoveManager(weak_ptr<BaseScene> _scene, double a, double b, double c) : TransformManager(_scene, a, b, c) {}

void MoveManager::execute()
{
    MoveVisitor mover(a, b, c);

    for (auto obj: *(scene.lock()))
    {
        if (obj->isVisible())
        {
            shared_ptr<FrameModel> model = static_pointer_cast<FrameModel>(obj);
            mover.visit(model);
        }
        else
        {
            shared_ptr<Camera> cam = static_pointer_cast<Camera>(obj);
            mover.visit(cam);
        }
    }
}


ScaleManager::ScaleManager(weak_ptr<BaseScene> _scene, double a, double b, double c) : TransformManager(_scene, a, b, c) {}

void ScaleManager::execute()
{
    ScaleVisitor scaler(a, b, c);

    for (auto obj: *(scene.lock()))
    {
        if (obj->isVisible())
        {
            shared_ptr<FrameModel> model = static_pointer_cast<FrameModel>(obj);
            scaler.visit(model);
        }
        else
        {
            shared_ptr<Camera> cam = static_pointer_cast<Camera>(obj);
            scaler.visit(cam);
        }
    }

}

RotateManager::RotateManager(weak_ptr<BaseScene> _scene, double a, double b, double c) : TransformManager(_scene, a, b, c) {}

void RotateManager::execute()
{
    RotateVisitor rotator(a, b, c);

    for (auto obj: *(scene.lock()))
    {
        if (obj->isVisible())
        {
            shared_ptr<FrameModel> model = static_pointer_cast<FrameModel>(obj);
            rotator.visit(model);
        }
        else
        {
            shared_ptr<Camera> cam = static_pointer_cast<Camera>(obj);
            rotator.visit(cam);
        }
    }
}
