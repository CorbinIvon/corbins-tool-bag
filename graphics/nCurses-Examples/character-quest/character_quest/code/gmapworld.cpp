#include "gmapworld.h"

GMapWorld::GMapWorld(Biome *biome_, GMapHome *emptyGMapHome_)
    : GMap(biome_)
{
    // Emty home
    emptyGMapHome = emptyGMapHome_;
}

bool GMapWorld::findGMapHome(int x_, int y_)
{
    // Find

    return gMapHome.find(x_) != gMapHome.end() &&
            gMapHome[x_].find(y_) != gMapHome[x_].end();
}

void GMapWorld::draw(Rect rect_, bool generate_)
{
    // Draw

    if(findGMapHome(getPlayerX(), getPlayerY()) &&
            gMapHome[getPlayerX()][getPlayerY()]->getEntered())
    {
        // Home
        gMapHome[getPlayerX()][getPlayerY()]->draw(rect_, generate_);
    }
    else
    {
        // World
        GMap::draw(rect_, generate_);
    }
}

pair<bool, GMapSlot *> GMapWorld::movePlayer(int changeX_, int changeY_)
{
    // Move player

    pair<bool, GMapSlot*> returnPair;

    if(findGMapHome(getPlayerX(), getPlayerY()) &&
            gMapHome[getPlayerX()][getPlayerY()]->getEntered())
    {
        // In home

        returnPair = gMapHome[getPlayerX()][getPlayerY()]->movePlayer(changeX_, changeY_);
    }
    else
    {
        // In world

        returnPair = GMap::movePlayer(changeX_, changeY_);

        // Check home
        if(!returnPair.second->is_free())
        {
            // Check
            for(auto mHomeType: biome->catDynamic["homes"]->object)
            {
                if(returnPair.second->getDynamicType() == mHomeType.second->getType())
                {
                    if(!findGMapHome(getPlayerX() + changeX_, getPlayerY() + changeY_))
                    {
                        // Generate home
                        gMapHome[getPlayerX() + changeX_][getPlayerY() + changeY_] = emptyGMapHome;
                    }

                    // Set player coords to home
                    setPlayerX(getPlayerX() + changeX_);
                    setPlayerY(getPlayerY() + changeY_);

                    // Enter home
                    gMapHome[getPlayerX()][getPlayerY()]->setEntered(true);

                    // Not solid slot
                    returnPair.first = true;
                }
            }
        }
    }

    return returnPair;
}
