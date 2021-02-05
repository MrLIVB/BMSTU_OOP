#include "compositeobject.h"

CompositeObject::CompositeObject() : objects(0) {}

bool CompositeObject::isComposite()
{
    return true;
}

size_t CompositeObject::getSize()
{
    return objects.size();
}

void CompositeObject::addObject(shared_ptr<BaseObject> obj) // изменить позже
{
    objects.push_back(obj);
}

void CompositeObject::removeObject(ObjIter it)
{
    objects.erase(it);
}

ObjIter CompositeObject::begin()
{
    return objects.begin();
}

ObjIter CompositeObject::end()
{
    return objects.end();
}

void CompositeObject::accept(ObjectVisitor *vis)
{
    for (auto obj: this->objects)
    {
        obj->accept(vis);
    }
}
