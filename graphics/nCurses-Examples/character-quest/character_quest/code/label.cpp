#include "label.h"

Label::Label(string lText, int x_, int y_, int width_, int height_, const Font *font_, bool animation_, float animationSpeed_, int indent_, bool align_)
{
    // Coords
    setX(x_);
    setY(y_);

    // Width / Height
    setWidth(width_);
    setHeight(height_);

    // Texts
    setText(lText);

    // Indent
    setIndent(indent_);

    // Animation
    setAnimation(animation_);

    // Invisible
    setAnimatonValue(0.0f);

    if(animation_)
    {
        // Speed
        setAnimationSpeed(animationSpeed_);
    }
    else
    {
        // Speed
        setAnimationSpeed(0.0f);
    }

    // Align
    setAlign(align_);

    // Font Id
    font = (Font*)font_;

    // Timer
    animationTimer = new Timer(animationSpeed_);
}

string Label::animationText()
{
    // Animation text

    if(animation)
    {
        string aText;
        for(size_t mChar = 0; mChar < text.size() && mChar < getAnimationValue(); mChar++)
        {
            aText.push_back(text[mChar]);
        }
        return aText;
    }
    return text;
}

bool Label::animationFinished()
{
    // Animaton finished

    if(getAnimationValue() > text.size())
    {
        return true;
    }
    return false;
}

bool Label::animationStarted()
{
    // Animation started

    return getAnimationValue() > 0.0f;
}

void Label::animationTact()
{
    // Animation tact

    if(getAnimation())
    {
        if(animationStarted())
        {
            if(animationTimer->finished())
            {
                // Tact
                animationValue += animationSpeed;

                if(!animationFinished())
                {
                    // Restart
                    animationTimer->restart();
                }
            }
        }
    }
}

void Label::animationStart()
{
    // Animation start

    if(getAnimation())
    {
        // Stop
        animationStop();

        setAnimatonValue(getAnimationValue() + getAnimationSpeed());
    }
}

void Label::animationStop()
{
    // Animation stop

    if(animation)
    {
        setAnimatonValue(0);
    }
}

void Label::animationOn()
{
    // On animation

    setAnimation(true);
}

void Label::animationOff()
{
    // Off animation

    setAnimation(false);
}

bool Label::draw(int scrW, int scrH)
{
    // Draw label

    // Center coords
    int lCX = alignX(x + width/2, scrW);
    int lCY = alignY(y + height/2, scrH);

    // Try Big size
    if(!drawText(lCX - textWidth(text, "big", font) / 2,
                 lCY - textHeight(text, "big", font) / 2,
                 animationText(), "big", font,
                 alignX(x, scrW), alignY(y, scrH),
                 alignX(width, scrW), alignY(height, scrH), indent))
    {
        // Try Normal size
        if(!drawText(lCX - textWidth(text, "normal", font) / 2,
                     lCY - textHeight(text, "normal", font) / 2,
                     animationText(), "normal", font,
                     alignX(x, scrW), alignY(y, scrH),
                     alignX(width, scrW), alignY(height, scrH), indent))
        {
            // Try Small size
            if(!drawText(lCX - textWidth(text, "small", font) / 2,
                         lCY - textHeight(text, "small", font) / 2,
                         animationText(), "small", font,
                         alignX(x, scrW), alignY(y, scrH),
                         alignX(width, scrW), alignY(height, scrH), indent))
            {
                // Try Natural size
                return drawText(lCX - textWidth(text, "natural", font) / 2,
                                lCY - textHeight(text, "natural", font) / 2,
                                animationText(), "natural", font,
                                alignX(x, scrW), alignY(y, scrH),
                                alignX(width, scrW), alignY(height, scrH), indent);
            }
        }
    }

    return true;
}

// --------------------------- Encapsulation ---------------------------

// Coords

// X

int Label::getX()
{
    // Get
    return x;
}
void Label::setX(int x_)
{
    // Set
    x = x_;
}

// Y

int Label::getY()
{
    // Get
    return y;
}
void Label::setY(int y_)
{
    // Set
    y = y_;
}

// Size

// Width

int Label::getWidth()
{
    // Get
    return width;
}
void Label::setWidth(int width_)
{
    // Set
    width = width_;
}

// Height

int Label::getHeight()
{
    // Get
    return height;
}
void Label::setHeight(int height_)
{
    // Set
    height = height_;
}

// Text

string Label::getText()
{
    // Get
    return text;
}
void Label::setText(string text_)
{
    // Set
    text = text_;
}

// Indent

int Label::getIndent()
{
    // Get
    return indent;
}
void Label::setIndent(int indent_)
{
    // Set
    indent = indent_;
}

// Align

bool Label::getAlign()
{
    // Get
    return align;
}
void Label::setAlign(bool align_)
{
    // Set
    align = align_;
}

// Value

float Label::getAnimationValue()
{
    // Get
    return animationValue;
}
void Label::setAnimatonValue(float animationValue_)
{
    // Set
    animationValue = animationValue_;
}

// Speed

float Label::getAnimationSpeed()
{
    // Get
    return animationSpeed;
}
void Label::setAnimationSpeed(float animationSpeed_)
{
    // Set
    animationSpeed = animationSpeed_;
}

// Animation

bool Label::getAnimation()
{
    // Get
    return animation;
}
void Label::setAnimation(bool animation_)
{
    // Set
    animation = animation_;
}
