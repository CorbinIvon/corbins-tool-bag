#include "text.h"

bool drawText(int x_, int y_, string text_, string size_, Font *font_, int sX_, int sY_, int sWidth_, int sHeight_, int indent_)
{
    // Draw text

    if(x_ >= sX_ &&
       y_ >= sY_ &&
       x_ + textWidth(text_, size_, font_, indent_) <= sX_ + sWidth_ &&
       y_ + textHeight(text_, size_, font_) <= sY_ + sHeight_)
    {
        // Draw
        int charX = x_;
        for(size_t f = 0; f < text_.size(); f++)
        {
            // Draw
            font_->image[text_[f]]->draw(charX, y_, size_);

            // Add character X
            charX += font_->image[text_[f]]->width(size_) + indent_;
        }
    }
    else
    {
        return false;
    }

    return true;
}

int textWidth(string text_, string size_, Font *font_, int indent_)
{
    // Get text width

    int tWidth = 0;
    for(size_t mChar = 0; mChar < text_.size(); mChar++)
    {
        // Current character width
        int charWidth = font_->image[text_[mChar]]->width(size_);

        // Add character width
        tWidth += charWidth;
    }
    // Add all indents
    tWidth += indent_ * (text_.size()-1);

    return tWidth;
}

int textHeight(string text_, string size_, Font *font_)
{
    // Get text height

    int tHeight = 0;
    for(size_t mChar = 0; mChar < text_.size(); mChar++)
    {
        // Current character height
        int charHeight = font_->image[text_[mChar]]->height(size_);

        // Set text height
        if(charHeight > tHeight)
        {
            tHeight = charHeight;
        }
    }

    return tHeight;
}
