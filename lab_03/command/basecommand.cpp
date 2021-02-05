#include "basecommand.h"

BaseCommand::BaseCommand()
{

}

LoadCommand::LoadCommand(char *filename)
{
    this->filename = filename;
}

void LoadCommand::execute(weak_ptr<BaseScene> scene)
{
    shared_ptr<BuilderImp> imp(new TxtBuilderImp());
    shared_ptr<BaseModelBuilder> builder(new TxtModelBuilder(imp));
    shared_ptr<BuildDirector> dir(new ModelBuildDirector(builder, this->filename));
    LoadManager(scene, dir).execute();
}


DrawCommand::DrawCommand() {}
DrawCommand::~DrawCommand() {}

void DrawCommand::execute(weak_ptr<BaseScene> scene)
{
    DrawManager(scene, factory).execute();
}

QDrawCommand::QDrawCommand(weak_ptr<QGraphicsScene> scene, const QPen &point, const QPen &line)
{
    factory = shared_ptr<BaseDrawerFactory>(new QDrawerFactory(scene, point, line));
}

QDrawCommand::~QDrawCommand() {}
