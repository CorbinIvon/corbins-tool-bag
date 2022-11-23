#ifndef _FILE_BIOME_
#define _FILE_BIOME_

#include "savedelete.h"
#include "rands.h"
#include "bobjcat.h"

#include <map>
#include <string>
#include <cassert>

using namespace std;

// --------------------------- Biome ---------------------------

class Biome
{
public:
    explicit Biome(float dynamiclLuck_ = 20.0f,
                          map <string, BObjCat*> catStatic_ = {},
                          map <string, BObjCat*> catDynamic_ = {});

    // Categories

    // Static
    map<string,BObjCat*> catStatic;

    // Dynamic
    map<string,BObjCat*> catDynamic;

    // Generate category
    BObjCat *genCat(map<string, BObjCat *> mapCats);
    BObjCat *genCatStatic();
    BObjCat *genCatDynamic();

    // Categories luck
    float catsLuck(map<string, BObjCat *> mapCats);

private:
    // Dynamic luck
    float dynamicLuck;
public:

    // Emty
    bool is_empty();

    // --------------------------- Encapsulation ---------------------------

    // Dynamic luck
    float getDynamicLuck();
    void setDynamicLuck(float dynamicLuck_);
};

#endif // _FILE_BIOME_
