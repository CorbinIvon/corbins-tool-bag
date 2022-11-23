#ifndef _FILE_TEXT_
#define _FILE_TEXT_

#include "screen.h"
#include "font.h"

#include <string>

using namespace std;

// --------------------------- Text ---------------------------

// Draw
bool drawText(int x_, int y_, string text_, string size_, Font *font_,
              int sX_ = 0, int sY_ = 0, int sWidth_ = screenWidth(), int sHeight_ = screenHeight(), int indent_ = 2);

// Width / Height
int textWidth(string text_, string size_, Font *font_, int indent_ = 2);
int textHeight(string text_, string size_, Font *font_);

#endif // _FILE_TEXT_

