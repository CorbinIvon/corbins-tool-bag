#ifndef _FILE_BOBJ_
#define _FILE_BOBJ_

#include <ncursesall.h>

// --------------------------- Biome Object ---------------------------

class BObj
{
public:
    explicit BObj(float luck_ = 20.0f, chtype type_ = ' ');

private:
    // Type
    chtype type;

    // Luck
    float luck;
public:

    // --------------------------- Encapsulation ---------------------------

    // Type
    chtype getType();
    void setType(chtype type_);

    // Luck
    float getLuck();
    void setLuck(float luck_);
};

#endif // _FILE_BOBJ_
