#ifndef SIMPLEOBJECTS_H
#define SIMPLEOBJECTS_H

#include "baseobject.h"

class VisibleObject : public BaseObject
{
public:
    bool isVisible() override;
};

class InvisibleObject : public BaseObject
{
public:
    bool isVisible() override;
};

#endif // SIMPLEOBJECTS_H
