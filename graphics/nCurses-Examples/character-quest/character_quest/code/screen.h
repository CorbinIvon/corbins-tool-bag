#ifndef _FILE_SCREEN_
#define _FILE_SCREEN_

#include "rect.h"
#include "coord.h"

#include <ncursesall.h>

// --------------------------- Screen ---------------------------

// Width / Height
float screenWidth();
float screenHeight();

// Screen
Rect *screen();

// Default

// Width / Height
const int screenWidthDefault = 80;
const int screenHeightDefault = 24;

// Screen
const Rect screenDefault = Rect(Coord(), screenWidthDefault, screenHeightDefault);

// Align
int alignX(int val_, int scrWidth_ = screenWidth());
int alignY(int val_, int scrHeight_ = screenHeight());

#endif // _FILE_SCREEN_

