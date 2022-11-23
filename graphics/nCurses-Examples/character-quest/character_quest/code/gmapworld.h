#ifndef _FILE_GMAPWORLD_
#define _FILE_GMAPWORLD_

#include "gmap.h"
#include "gmaphome.h"
#include "rect.h"
#include "coord.h"

// --------------------------- Game Map World ---------------------------

class GMapWorld : public GMap
{
public:
    explicit GMapWorld(Biome *biome_ = new Biome(), GMapHome *emptyGMapHome_ =  new GMapHome());

    // Move player
    pair<bool, GMapSlot*> movePlayer(int changeX_, int changeY_);

    // Map Homes
    map<int, map<int, GMapHome*>> gMapHome;

    // Empty Home
    GMapHome* emptyGMapHome;

    // Find home
    bool findGMapHome(int x_, int y_);

    // Draw
    void draw(Rect rect_, bool generate_ = true);
};

#endif // _FILE_GMAPWORLD_
