#ifndef _FILE_LABEL_
#define _FILE_LABEL_

#include "screen.h"
#include "text.h"
#include "timer.h"
#include "font.h"
#include "character.h"

#include <ncursesall.h>
#include <string>

using namespace std;

// --------------------------- Label ---------------------------

class Label
{
public:
    explicit Label(string lText, int x_, int y_, int width_, int height_, const Font *font_,
                       bool animation_ = true, float animationSpeed_ = 0.01f, int indent_ = 2, bool align_ = true);

private:
    // Coords
    int x;
    int y;

    // Width / Height
    int width;
    int height;

    // Text
    string text;

    // Indent
    int indent;

    // Align
    bool align;
public:

    // Font
    Font* font;

    // Draw
    bool draw(int scrW, int scrH);

    // --------------------------- Animation ---------------------------

    // Timer
    Timer* animationTimer;

private:
    // View size
    float animationValue;

    // Speed
    float animationSpeed;

    // Bool
    bool animation;
public:

    // Text
    string animationText();

    // Started / Finished bool
    bool animationFinished();
    bool animationStarted();

    // Tact
    void animationTact();

    // Control
    void animationStart();
    void animationStop();
    void animationOn();
    void animationOff();

    // --------------------------- Encapsulation ---------------------------

    // Coords

    // X
    int getX();
    void setX(int x_);

    // Y
    int getY();
    void setY(int y_);

    // Size

    // Width
    int getWidth();
    void setWidth(int width_);

    // Height
    int getHeight();
    void setHeight(int height_);

    // Text
    string getText();
    void setText(string text_);

    // Indent
    int getIndent();
    void setIndent(int indent_);

    // Align
    bool getAlign();
    void setAlign(bool align_);

    // --------------------------- Animation values ---------------------------

    // View size
    float getAnimationValue();
    void setAnimatonValue(float animationValue_);

    // Speed
    float getAnimationSpeed();
    void setAnimationSpeed(float animationSpeed_);

    // Bool
    bool getAnimation();
    void setAnimation(bool animation_);
};

#endif // _FILE_LABEL_
