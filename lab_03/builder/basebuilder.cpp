#include "basebuilder.h"

TxtModelBuilder::TxtModelBuilder(shared_ptr<BuilderImp> _imp) : BaseModelBuilder(_imp)
{

}

void TxtModelBuilder::loadNodes(std::ifstream &f)
{
    imp->loadNodes(f);
}

void TxtModelBuilder::loadEdges(std::ifstream &f)
{
    imp->loadEdges(f);
}

shared_ptr<BaseObject> TxtModelBuilder::getProduct()
{
    return imp->returnProduct();
}
