#include "character.h"

Character::Character(char imageNatural_, int widthSmall_, int heightSmall_, vector<string> imageSmall_,
                     int widthNormal_, int heightNormal_, vector<string> imageNormal_,
                     int widthBig_, int heightBig_, vector<string> imageBig_)
{
    // Set sizes

    // Small
    setWidthSmall(widthSmall_);
    setHeightSmall(heightSmall_);

    // Normal
    setWidthNormal(widthNormal_);
    setHeightNormal(heightNormal_);

    // Big
    setWidthBig(widthBig_);
    setHeightBig(heightBig_);

    // Images
    imageSmall = imageSmall_;
    imageNormal = imageNormal_;
    imageBig = imageBig_;
    imageNatural = imageNatural_;
}

int Character::width(string cSize)
{
    // Width

    if(cSize == "small")
    {
        return getWidthSmall();
    }
    else if(cSize == "normal")
    {
        return getWidthNormal();
    }
    else if(cSize == "big")
    {
        return getWidthBig();
    }
    else if(cSize == "natural")
    {
        return 1;
    }

    assert(false && "Wrong width size");

    exit(EXIT_FAILURE);
}

int Character::height(string cSize)
{
    // Height

    if(cSize == "small")
    {
        return getHeightSmall();
    }
    else if(cSize == "normal")
    {
        return getHeightNormal();
    }
    else if(cSize == "big")
    {
        return getHeightBig();
    }
    else if(cSize == "natural")
    {
        return 1;
    }

    assert(false && "Wrong height size");

    exit(EXIT_FAILURE);
}

void Character::draw(int dX, int dY, string size)
{
    // Draw char

    if(size != "natural")
    {
        // Draw image

        // Create
        vector <string> dImage;

        // Set
        if(size == "small")
        {
            dImage = imageSmall;
        }
        else if(size == "normal")
        {
            dImage = imageNormal;
        }
        else if(size == "big")
        {
            dImage = imageBig;
        }

        // Draw
        for(size_t mY = 0; mY < dImage.size(); mY++)
        {
            for(size_t f = 0; f < dImage[mY].size(); f++)
            {
                if(dImage[mY][f] != ' ')
                {
                    // Move
                    move(dY + mY, dX + f);

                    // Draw char
                    printw("%c",dImage[mY].c_str()[f]);
                }
            }
        }
    }
    else
    {
        // Draw natural size
        move(dY, dX);
        printw("%c", getImageNatural());
    }
}

// --------------------------- Encapsulation ---------------------------

// Natural image

char Character::getImageNatural()
{
    // Get
    return imageNatural;
}
void Character::setImageNatural(char imageNatural_)
{
    // Set
    imageNatural = imageNatural_;
}

// -------------------------- Sizes --------------------------

// ------------------------- Small -------------------------

// Width

int Character::getWidthSmall()
{
    // Get
    return widthSmall;
}
void Character::setWidthSmall(int widthSmall_)
{
    // Set
    widthSmall = widthSmall_;
}

// Height

int Character::getHeightSmall()
{
    // Get
    return heightSmall;
}
void Character::setHeightSmall(int heightSmall_)
{
    // Set
    heightSmall = heightSmall_;
}

// ------------------------- Normal -------------------------

// Width

int Character::getWidthNormal()
{
    // Get
    return widthNormal;
}
void Character::setWidthNormal(int widthNormal_)
{
    // Set
    widthNormal = widthNormal_;
}

// Height

int Character::getHeightNormal()
{
    // Get
    return heightNormal;
}
void Character::setHeightNormal(int heightNormal_)
{
    // Set
    heightNormal = heightNormal_;
}

// ------------------------- Big -------------------------

// Width

int Character::getWidthBig()
{
    // Get
    return widthBig;
}
void Character::setWidthBig(int widthBig_)
{
    // Set
    widthBig = widthBig_;
}

// Height

int Character::getHeightBig()
{
    // Get
    return heightBig;
}
void Character::setHeightBig(int heightBig_)
{
    // Set
    heightBig = heightBig_;
}
