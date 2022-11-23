#ifndef _FILE_BUTTON_
#define _FILE_BUTTON_

#include "screen.h"
#include "rect.h"
#include "coord.h"

#include <string>
#include <ncursesall.h>

using namespace std;

// --------------------------- Button ---------------------------

class Button
{
public:
    explicit Button(string name_ = "button", float x_ = 0, float y_ = 0,
           float indent_ = 1, bool align_ = true);

private:
    // Name
    string name;

    // Coords
    float x, y;
public:

    // Size
    float width(int screenWidth_);
    float height(int screenHeight_);

    // Indent
private:
    float indent;
public:
    int indentW(int screenWidth_);
    int indentH(int screenHeight_);

    // Draw
    void draw(Rect* screen_);
    void drawHorizontalBorder(Rect* screen_);

private:
    // Selected
    bool selected;

    // Align
    bool align;
public:

    // --------------------------- Encapsulation ---------------------------

    // Name
    string getName();
    void setName(string name_);

    // Coords
    float getX();
    void setX(float x_);
    float getY();
    void setY(float y_);

    // Indent
    float getIndent();
    void setIndent(float indent_);

    // Setlected
    bool getSelected();
    void setSelected(bool selected_);

    // Align
    bool getAlign();
    void setAlign(bool align_);
};

#endif // _FILE_BUTTON_
