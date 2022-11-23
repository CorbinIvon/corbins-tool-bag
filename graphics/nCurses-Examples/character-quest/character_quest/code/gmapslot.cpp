#include "gmapslot.h"

GMapSlot::GMapSlot(chtype staticType_, chtype dynamicType_)
{
    // Static type
    setStaticType(staticType_);

    // Dynamic type
    setDynamicType(dynamicType_);
}

bool GMapSlot::is_empty()
{
    return getDynamicType() == ' ' &&
            getDynamicType() == ' ';
}

bool GMapSlot::is_free()
{
    return getDynamicType() == ' ';
}

// --------------------------- Encapsulation ---------------------------

// Types

// Static

chtype GMapSlot::getStaticType()
{
    // Get
    return staticType;
}
void GMapSlot::setStaticType(chtype staticType_)
{
    // Set
    staticType = staticType_;
}

// Dynamic

chtype GMapSlot::getDynamicType()
{
    // Get
    return dynamicType;
}
void GMapSlot::setDynamicType(chtype dynamicType_)
{
    // Set
    dynamicType = dynamicType_;
}
