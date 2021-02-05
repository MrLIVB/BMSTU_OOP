#include "simpleobjects.h"

bool VisibleObject::isVisible()
{
    return true;
}

bool InvisibleObject::isVisible()
{
    return false;
}
