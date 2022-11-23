#include "gmap.h"

GMap::GMap(Biome *biome_)
{
    // Player

    // Coords
    setPlayerX(0);
    setPlayerY(0);

    // Map

    // Biome
    biome = biome_;

    // Saved
    setSaved(true);
}

GMap::~GMap()
{
    // Slots
    for(auto &mMapSlots: slot)
    {
        SAVE_DEL_MAP(mMapSlots.second)
    }
}

// Camera coords

int GMap::cameraX(int gameWidth_)
{
    return playerX - gameWidth_/2;
}

int GMap::cameraY(int gameHeight_)
{
    return playerY - gameHeight_/2;
}

// From map to screen coords

int GMap::toScrX(int mX, int viewW, int indentX)
{
    return indentX - cameraX(viewW) + mX;
}
int GMap::toScrY(int mY, int viewH, int indentY)
{
    return indentY - cameraY(viewH) + mY;
}

// From screen to map coord

Coord GMap::toMapCoord(Coord coord_, Rect gameRect_ )
{
    return Coord(toMapX(coord_.getX(), gameRect_.coord.getX(), gameRect_.getWidth()),
                        toMapY(coord_.getY(), gameRect_.coord.getY(), gameRect_.getHeight()));
}

int GMap::toMapX(int x_, int gameX_, int gameWidth_)
{
    // X

    return x_ - gameX_ + cameraX(gameWidth_);
}
int GMap::toMapY(int y_, int gameY_, int gameHeight_)
{
    // Y

    return y_ - gameY_ + cameraY(gameHeight_);
}

bool GMap::is_empty()
{
    // Empty

    return slot.empty();
}

GMapSlot *GMap::generateSlot()
{
    // Generate slot

    GMapSlot *gSlot = new GMapSlot();

    // Set dynamic
    if(luck(biome->getDynamicLuck()))
    {
        gSlot->setDynamicType(biome->genCatDynamic()->genObject()->getType());
    }

    // Set static
    gSlot->setStaticType(biome->genCatStatic()->genObject()->getType());

    return gSlot;
}

void GMap::draw(Rect drawRect_, bool generate_)
{
    // Draw

    // Generate
    if(generate_)
        generate(drawRect_.getWidth(), drawRect_.getHeight());

    // Draw

    // Map
    for(int mX = 0; mX < alignX(drawRect_.getWidth()); mX++)
    {
        // X
        int x = cameraX(alignX(drawRect_.getWidth())) + mX;

        for(int mY = 0; mY < alignY(drawRect_.getHeight()); mY++)
        {
            // Y
            int y = cameraY(alignY(drawRect_.getHeight())) + mY;

            // Draw
            move(alignY(drawRect_.coord.getY()) + mY, alignX(drawRect_.coord.getY()) + mX);
            if(slot[x][y]->getDynamicType() == ' ')
            {
                addch(slot[x][y]->getStaticType());
            }
            else
            {
                addch(slot[x][y]->getDynamicType());
            }
        }
    }

    // Player
    move(toScrY(playerY, alignY(drawRect_.getHeight()), alignY(drawRect_.coord.getY())),
         toScrX(playerX, alignX(drawRect_.getWidth()), alignX(drawRect_.coord.getX())));
    printw("T");
}

void GMap::generate(int dW, int dH)
{
    // Generate slots

    for(int mX = 0; mX < alignX(dW); mX++)
    {
        // X
        int gX = cameraX(alignX(dW)) + mX;

        for(int mY = 0; mY < alignY(dH); mY++)
        {
            // Y
            int gY = cameraY(alignY(dH)) + mY;

            // Generate
            if( slot.find(gX) == slot.end() ||
                    slot[gX].find(gY) == slot[gX].end() )
            {
                slot[gX][gY] = generateSlot();
            }
        }
    }
}

pair<bool, GMapSlot *> GMap::movePlayer(int changeX_, int changeY_)
{
    // Move player

    GMapSlot *gotoSlot = slot[playerX + changeX_][playerY + changeY_];

    pair<bool, GMapSlot *> returnPair = { gotoSlot->is_free(), gotoSlot };

    if(gotoSlot->is_free())
    {
        // Move
        playerX += changeX_;
        playerY += changeY_;

        saved = false;
    }

    return returnPair;
}

pair<bool, GMapSlot *> GMap::movePlayerUp()
{
    // Move Player Up

    return movePlayer(0, -1);
}

pair<bool, GMapSlot *> GMap::movePlayerDown()
{
    // Move player down

    return movePlayer(0, 1);
}

pair<bool, GMapSlot *> GMap::movePlayerLeft()
{
    // Move player left

    return movePlayer(-1, 0);
}

pair<bool, GMapSlot *> GMap::movePlayerRight()
{
    // Move player right

    return movePlayer(1, 0);
}

// --------------------------- Encapsulation ---------------------------

// Player

// X

int GMap::getPlayerX()
{
    // Get
    return playerX;
}
void GMap::setPlayerX(int playerX_)
{
    // Set
    playerX = playerX_;
}

// Y

int GMap::getPlayerY()
{
    // Get
    return playerY;
}
void GMap::setPlayerY(int playerY_)
{
    // Set
    playerY = playerY_;
}

// Saved

bool GMap::getSaved()
{
    // Get
    return saved;
}
void GMap::setSaved(bool saved_)
{
    // Set
    saved = saved_;
}
