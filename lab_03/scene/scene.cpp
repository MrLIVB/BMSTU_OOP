#include "scene.h"
#include "manager/controlmanager.h"
#include "builder/director.h"

Scene::Scene()
{
    shared_ptr<Camera> cam = shared_ptr<Camera>(new Camera(0, 0, 1000));
    this->addObject(cam);
    ObjIter b = objects.begin();
    ObjIter e = objects.end();
    for (ObjIter it = b; it != e; it++)
        if (it->get()->isViewer())
            setCamera(it);
}

size_t Scene::getSize()
{
    return objects.size();
}

ObjIter Scene::begin()
{
    return objects.begin();
}


ObjIter Scene::end()
{
    return objects.end();
}

std::shared_ptr<BaseCamera> Scene::getCamera()
{
    shared_ptr<BaseCamera> cam = static_pointer_cast<BaseCamera>(objects[currentCameraIndex]);
    return cam;
}

void Scene::setCamera(ObjIter it)
{
    int i = 0;
    for (ObjIter runing = objects.begin(); runing != it; runing++)
        i++;
    currentCameraIndex = i;
}

void Scene::addObject(const std::shared_ptr<BaseObject>& obj)
{
    objects.push_back(obj);
}

void Scene::removeObject(ObjIter it)
{
    objects.erase(it);
}
