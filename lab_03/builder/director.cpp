#include "director.h"

#include <fstream>
#include "error.h"

ModelBuildDirector::ModelBuildDirector(shared_ptr<BaseModelBuilder> builder, char *name) : BuildDirector(builder)
{
    filename = name;
}

shared_ptr<BaseObject> ModelBuildDirector::create()
{
    std::ifstream f;

    if (filename == nullptr)
        throw FilenameError("Build director", __FILE__, __LINE__);
    f.open(filename);
    if (!f.is_open())
        throw FileError("Build director", __FILE__, __LINE__);

    builder->loadNodes(f);
    builder->loadEdges(f);

    f.close();
    return builder->getProduct();
}
