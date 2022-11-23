#ifndef _FILE_GMAPHOME_
#define _FILE_GMAPHOME_

#include "rect.h"
#include "coord.h"
#include "rands.h"
#include "gmap.h"
#include "gmapslot.h"

// --------------------------- Game Map Home ---------------------------

class GMapHome : public GMap
{
public:
    explicit GMapHome(Biome* biome_ = new Biome(), GMapSlot wall_ = GMapSlot(' ', ACS_BLOCK), GMapSlot door_ = GMapSlot(' ', 'N'));

    // Wall type
    GMapSlot gMapSlotWall;

    // Door type
    GMapSlot gMapSlotDoor;

private:
    // Generated
    bool generated;

    // Entered
    bool entered;
public:

    // Draw
    void draw(Rect drawRect_, bool generate_ = true);

    // Generate home
    void generate(int width_, int height_);

    // Move player
    pair<bool, GMapSlot*> movePlayer(int changeX_, int changeY_);

    // Empty
    bool is_empty();

    // --------------------------- Encapsulation ---------------------------

    // Generated
    bool getGenerated();
    void setGenerated(bool generated_);

    // Entered
    bool getEntered();
    void setEntered(bool entered_);
};

#endif // _FILE_GMAPHOME_
