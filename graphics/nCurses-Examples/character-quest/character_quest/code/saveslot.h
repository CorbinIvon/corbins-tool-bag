#ifndef _FILE_SAVESLOT_
#define _FILE_SAVESLOT_

#include "gmapworld.h"
#include "gmaphome.h"

#include <map>
#include <string>

using namespace std;

// --------------------------- Save Slot ---------------------------

class SaveSlot
{
public:
    explicit SaveSlot(GMapWorld *gMapWorld_ = new GMapWorld(), string playerName_ = "Empty");

    // Game Map
    GMapWorld gMap;

    // Player name
private:
    string playerName;
public:

    // Saved
    bool saved();

    // Emty
    bool is_empty();

    // --------------------------- Encapsulation ---------------------------

    string getPlayerName();
    void setPlayerName(string playerName_);
};

#endif // _FILE_SAVESLOT_
