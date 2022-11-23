#include "bobj.h"

BObj::BObj(float luck_, chtype type_)
{
    // Type
    setType(type_);

    // Luck
    setLuck(luck_);
}

// --------------------------- Values ---------------------------

// Type

chtype BObj::getType()
{
    // Get
    return type;
}
void BObj::setType(chtype type_)
{
    // Set
    type = type_;
}

// Luck

float BObj::getLuck()
{
    // Get
    return luck;
}
void BObj::setLuck(float luck_)
{
    // Set
    luck = luck_;
}
