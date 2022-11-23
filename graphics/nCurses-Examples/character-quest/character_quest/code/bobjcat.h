#ifndef _FILE_BOBJCAT_
#define _FILE_BOBJCAT_

#include "savedelete.h"
#include "rands.h"
#include "bobj.h"

#include <map>
#include <string>
#include <cassert>

using namespace std;

// --------------------------- Biome Object Category ---------------------------

class BObjCat
{
public:
    explicit BObjCat(float luck_ = 20.0f, map <string, BObj*> object_ = {});

    // Object
    map <string, BObj*> object;

    // Generate object
    BObj *genObject();

    // Objects luck
    float objectsLuck();

private:
    // Luck
    float luck;
public:

    // --------------------------- Encapsulation ---------------------------

    // Luck
    float getLuck();
    void setLuck(float luck_);
};

#endif // _FILE_BOBJCAT_
