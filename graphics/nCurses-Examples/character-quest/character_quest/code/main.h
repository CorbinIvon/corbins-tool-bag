#ifndef _FILE_MAIN_
#define _FILE_MAIN_

#include "savedelete.h"
#include "rands.h"
#include "screen.h"
#include "keycodes.h"
#include "timer.h"
#include "gmapslot.h"
#include "saveslot.h"
#include "biome.h"
#include "bobj.h"
#include "bobjcat.h"
#include "font.h"
#include "scene.h"
#include "pushmessage.h"
#include "ncursesall.h"
#include "rect.h"

#ifdef WINDOWS
    #include "windows.h"
#endif

#ifdef DEBUG
    #include <qcoreapplication.h>
#endif
#include <time.h>
#include <fstream>
#include <map>
#include <string>
#include <thread>

using namespace std;

// --------------------------- Main ---------------------------

// Inits
void initAll();

// Update screen
void update();

// Clocks per update
float cpu;

// Clear screen
void cls(int x_, int y_, int width_, int height_);

// Old Width / Height
int scrOldWidth;
int scrOldHeight;

// Key stroke / char
int keyStroke;
char keyChar;

// Commands
void keysCommand(int keyStroke_);

// --------------------------- Scenes ---------------------------

#include "scenes.h"

Scene *selectedScene;

// Set
void setScene(Scene *scene_);

// Draw
void drawScene(Scene *scene_);

// --------------------------- Scenes values / voids ---------------------------

// Timer screensaver (screensaver)
int timerScreensaver;

// Delete save mode (saves)
bool deleteSave;

// Move player (game)
void movePlayer(int direction);

// Save / Read saves (saves, game)
void saveSaves(string fileName_ = "save.txt");
void loadSaves(string fileName_ = "save.txt");

// --------------------------- Messages ---------------------------

vector <PushMessage*> message;

// Draw
void drawMessages();

// --------------------------- Buttons ---------------------------

// Click
void buttonClick();

// Selected button
size_t selectedButton;

// --------------------------- Fonts ---------------------------

#include "fonts.h"

// --------------------------- Characters ---------------------------

// Set pairs
void initCharPairs();

// --------------------------- Save ---------------------------

const int saveSlotNum = 4;
SaveSlot *saveSlot[saveSlotNum];

// Selected
int selectedSaveSlot;

// View size

// Game

// Coords
const int gameRectX = 0;
const int gameRectY = 0;

// Size
const int gameRectWidth = 80;
const int gameRectHeight = 24;

// Rect
const Rect gameRect = Rect(Coord(gameRectX, gameRectY), gameRectWidth, gameRectHeight);

// --------------------------- Biomes ---------------------------

#include "biomes.h"

#endif // _FILE_MAIN_

