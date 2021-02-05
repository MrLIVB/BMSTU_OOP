#ifndef CONTROLMANAGER_H
#define CONTROLMANAGER_H

#include <memory>

#include "basescenemanager.h"
#include "builder/director.h"
#include "drawer/visualizer.h"

class LoadManager : public BaseSceneManager
{
public:
    LoadManager(weak_ptr<BaseScene> _scene, weak_ptr<BuildDirector> _dir);
    ~LoadManager();

    void execute();
private:
    weak_ptr<BuildDirector> dir;
};

class DrawManager : public BaseSceneManager
{
public:
    DrawManager(weak_ptr<BaseScene> scene, weak_ptr<BaseDrawerFactory> factory);
    ~DrawManager();

    void execute();
private:
    weak_ptr<BaseDrawerFactory> drawer;
};
#endif // CONTROLMANAGER_H
