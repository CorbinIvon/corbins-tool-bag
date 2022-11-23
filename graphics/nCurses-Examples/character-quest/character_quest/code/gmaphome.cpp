#include "gmaphome.h"

GMapHome::GMapHome(Biome *biome_, GMapSlot wall_, GMapSlot door_)
    : GMap(biome_)
{
    // Biome
    biome = biome_;

    // Wall type
    gMapSlotWall = wall_;

    // Door type
    gMapSlotDoor = door_;

    // Not Generated
    setGenerated(false);

    // Entered
    setEntered(true);
}

void GMapHome::generate(int dW, int dH)
{
    // Generate home

    // Set

    // Width
    int hWidth = 10 + randi(10);

    // Height
    int hHeight = hWidth/2;

    // Create clear slots
    for(int mX = -hWidth; mX < alignX(dW) + hWidth*2; mX++)
    {
        // X
        int x = cameraX(alignX(dW)) + mX;

        for(int mY = -hHeight; mY < alignY(dH) + hHeight*2; mY++)
        {
            // Y
            int y = cameraY(alignY(dH)) + mY;

            // Create

            slot[x][y] = new GMapSlot();
        }
    }

    // Home coords
    const int homeX = -hWidth/2;
    const int homeY = -hHeight/2;

    // Generate

    // Home
    for(int mX = -hWidth/2; mX < hWidth/2; mX++)
    {
        for(int mY = -hHeight/2; mY < hHeight/2; mY++)
        {
            slot[mX][mY] = generateSlot();
        }
    }

    // Walls

    // Up / Down
    for(int mX = -hWidth/2; mX <= hWidth/2; mX++)
    {
        // Wall

        slot[mX][-hHeight/2] = &gMapSlotWall;
        slot[mX][hHeight/2] = &gMapSlotWall;
    }

    // Left / Right
    for(int mY = -hHeight/2; mY <= hHeight/2; mY++)
    {
        // Wall

        slot[-hWidth/2][mY] = &gMapSlotWall;
        slot[hWidth/2][mY] = &gMapSlotWall;
    }

    // Door

    // Select angle (left up / right down)

    // Left Up
    int angleX = homeX;
    int angleY = homeY;

    bool leftUp = true;

    // Right down
    if(luck(50.0f))
    {
        angleX *= -1;
        angleY *= -1;

        leftUp = false;
    }

    // Get indent
    int indentX = 1+randi(hWidth-2);
    int indentY = 1+randi(hHeight-2);

    if(!leftUp)
    {
        indentX *= -1;
        indentY *= -1;
    }

    // Set
    int doorX = angleX + indentX;
    int doorY = angleY + indentY;

    if(luck(50.0f))
    {
        slot[homeX][doorY] = &gMapSlotDoor;
        doorX = angleX;
    }
    else
    {
        slot[doorX][homeY] = &gMapSlotDoor;
        doorY = angleY;
    }

    // Set player coords

    // Get
    int playerX_ = getPlayerX();
    int playerY_ = getPlayerY();

    if(leftUp)
    {
        if(angleX == doorX)
        {
            playerX_ = doorX+1;
            playerY_ = doorY;
        }
        else if(angleY == doorY)
        {
            playerY_ = doorY+1;
            playerX_ = doorX;
        }
    }
    else
    {
        if(angleX == doorX)
        {
            playerX_ = doorX-1;
            playerY_ = doorY;
        }
        else if(angleY == doorY)
        {
            playerY_ = doorY-1;
            playerX_ = doorX;
        }
    }

    // Set
    setPlayerX(playerX_);
    setPlayerY(playerY_);

    // Set free generated slot of player coords
    GMapSlot *slot_;
    while(!slot[getPlayerX()][getPlayerY()]->is_free())
    {
        // Generate
        slot_ = generateSlot();

        // Set
        slot[playerX_][playerY_] = slot_;
    }

    // Generated
    setGenerated(true);
}

void GMapHome::draw(Rect drawRect_, bool generate_)
{
    // Draw

    GMap::draw(drawRect_, generate_ && !getGenerated());
}

pair<bool, GMapSlot *> GMapHome::movePlayer(int changeX_, int changeY_)
{
    // Move player

    pair<bool, GMapSlot*> returnPair = GMap::movePlayer(changeX_, changeY_);

    if(returnPair.second->getDynamicType() == gMapSlotDoor.getDynamicType())
    {
        // Exit home
        setEntered(false);

        // Not solid slot
        returnPair.first = true;
    }

    return returnPair;
}

bool GMapHome::is_empty()
{
    // Empty

    return biome->is_empty();
}

// --------------------------- Encapsulation ---------------------------

// Generated

bool GMapHome::getGenerated()
{
    // Get
    return generated;
}
void GMapHome::setGenerated(bool generated_)
{
    // Set
    generated = generated_;
}

// Entered

bool GMapHome::getEntered()
{
    // Get
    return entered;
}
void GMapHome::setEntered(bool entered_)
{
    // Set
    entered = entered_;
}
