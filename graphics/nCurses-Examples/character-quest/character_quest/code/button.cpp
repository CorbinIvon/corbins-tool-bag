#include "button.h"

Button::Button(string name_, float x_, float y_,
               float indent_, bool align_)
{
    // Name
    setName(name_);

    // Coords
    setX(x_);
    setY(y_);

    // Deselect
    setSelected(false);

    // Indent
    setIndent(indent_);

    // Align
    setAlign(align_);
}

void Button::draw(Rect *screen_)
{
    // Draw

    // Set draw coords

    Coord drawCoord(x - width(screen_->getWidth())/2, y - height(screen_->getHeight())/2);

    if(align)
    {
        drawCoord.setX(alignX(drawCoord.getX(), screen_->getWidth()));
        drawCoord.setY(alignY(drawCoord.getY(), screen_->getHeight()));
    }

    // Borders

    // Up

    // Angle
    move(drawCoord.getY(), drawCoord.getX());
    printw("/");

    // Border
    drawHorizontalBorder(screen_);

    // Angle
    move(drawCoord.getY(), drawCoord.getX() + width(screen_->getWidth())-1);
    printw("\\");

    // Middle

    if(selected)
    {
        for(int f = 0; f<1 + indentH(screen_->getHeight())*2; f++)
        {
            // Left
            move(drawCoord.getY()+1 + f, drawCoord.getX());
            printw("|");

            // Right
            move(drawCoord.getY()+1 + f, drawCoord.getX() + width(screen_->getWidth())-1);
            printw("|");
        }
    }

    // Down

    // Angle
    move(drawCoord.getY() + height(screen_->getHeight())-1, drawCoord.getX());
    printw("\\");

    // Border
    drawHorizontalBorder(screen_);

    // Angle
    move(drawCoord.getY() + height(screen_->getHeight())-1, drawCoord.getX() + width(screen_->getWidth())-1);
    printw("/");

    // Name
    move(drawCoord.getY()+1 + indentH(screen_->getHeight()), drawCoord.getX()+1 + indentW(screen_->getWidth()));
    printw("%s", name.c_str());
}

void Button::drawHorizontalBorder(Rect *screen_)
{
    // Draw up/down border
    if(selected)
    {
        for(unsigned int f = 0; f < width(screen_->getWidth())-2; f++)
        {
            printw("-");
        }
    }
}

float Button::width(int screenWidth_)
{
    // Width

    return 2 + name.size() + indentW(screenWidth_)*2.0;
}

float Button::height(int screenHeight_)
{
    // Height

    return 2 + indentH(screenHeight_)*2 + 1;
}

int Button::indentW(int screenWidth_)
{
    // Width indent

    return alignX(indent * 2.0, screenWidth_);
}

int Button::indentH(int screenHeight_)
{
    // Height indent

    return alignY(indent * (screenHeight_ / 24.0), screenHeight_);
}

// --------------------------- Values ---------------------------

// Name

string Button::getName()
{
    // Get
    return name;
}
void Button::setName(string name_)
{
    // Set
    name = name_;
}

// X

float Button::getX()
{
    // Get
    return x;
}
void Button::setX(float x_)
{
    // Set
    x = x_;
}

// Y

float Button::getY()
{
    // Get
    return y;
}
void Button::setY(float y_)
{
    // Set
    y = y_;
}

// Indent

float Button::getIndent()
{
    // Get
    return indent;
}
void Button::setIndent(float indent_)
{
    // Set
    indent = indent_;
}

// Selected

bool Button::getSelected()
{
    // Get
    return selected;
}
void Button::setSelected(bool selected_)
{
    // Set
    selected = selected_;
}

// Align

bool Button::getAlign()
{
    // Get
    return align;
}
void Button::setAlign(bool align_)
{
    // Set
    align = align_;
}
