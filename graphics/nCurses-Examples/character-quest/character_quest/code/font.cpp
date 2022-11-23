#include "font.h"

Font::Font(map<char, Character *> image_)
{
    // Image
    image = image_;
}

Font::Font(const Font *&font_)
{
    // Image
    image = font_->image;
}

Font::~Font()
{
    // Image
    SAVE_DEL_MAP(image);
}
