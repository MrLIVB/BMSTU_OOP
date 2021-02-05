#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "basebuilder.h"
#include <memory>

using namespace std;
class BuildDirector
{
public:
    BuildDirector(shared_ptr<BaseModelBuilder> builder) : builder(builder) {}

    virtual shared_ptr<BaseObject> create() = 0;
protected:
    shared_ptr<BaseModelBuilder> builder;
};

class ModelBuildDirector : public BuildDirector
{
public:
    ModelBuildDirector(shared_ptr<BaseModelBuilder> builder, char *name);

    shared_ptr<BaseObject> create();
private:
    char *filename;
};

#endif // DIRECTOR_H
