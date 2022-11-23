#include "saveslot.h"

SaveSlot::SaveSlot(GMapWorld *gMapWorld_, string playerName_)
{
    // GMap
    gMap = *gMapWorld_;

    // Player name
    playerName = playerName_;
}

bool SaveSlot::saved()
{
    // Saved

    return gMap.getSaved();
}

bool SaveSlot::is_empty()
{
    // Empty

    return gMap.is_empty();
}

// --------------------------- Encapsulation ---------------------------

// Player name

string SaveSlot::getPlayerName()
{
    // Get
    return playerName;
}

void SaveSlot::setPlayerName(string playerName_)
{
    // Set
    playerName = playerName_;
}
