#ifndef BASECOMMAND_H
#define BASECOMMAND_H

#include <memory>

#include "scene/scene.h"
#include "manager/controlmanager.h"
#include "builder/director.h"

class BaseCommand
{
public:
    BaseCommand();
    virtual ~BaseCommand() = default;

    virtual void execute(weak_ptr<BaseScene> scene) = 0;
};

class LoadCommand : public BaseCommand
{
public:
    LoadCommand(char *filename);

    void execute(weak_ptr<BaseScene> scene) override;
private:
    char *filename;
};

class DrawCommand : public BaseCommand
{
public:
    DrawCommand();
    virtual ~DrawCommand() = 0;

    void execute(weak_ptr<BaseScene> scene) override;
protected:
    shared_ptr<BaseDrawerFactory> factory;
};

class QDrawCommand : public DrawCommand
{
public :
    QDrawCommand(weak_ptr<QGraphicsScene> scene, const QPen& point, \
                 const QPen& line);
    ~QDrawCommand();
};

#endif // BASECOMMAND_H
