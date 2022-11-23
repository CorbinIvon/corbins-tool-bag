#include "screen.h"

float screenWidth()
{
    // Screen width

    return getmaxx(stdscr);
}

float screenHeight()
{
    // Screen height

    return getmaxy(stdscr);
}

int alignX(int val_, int scrWidt_)
{
    // Align X

    return (val_ * scrWidt_) / screenWidthDefault;
}

int alignY(int val_, int scrHeight_)
{
    // Align Y

    return (val_ * scrHeight_) / screenHeightDefault;
}

Rect *screen()
{
    return new Rect(Coord(), screenWidth(), screenHeight());
}
