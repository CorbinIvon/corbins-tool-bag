#ifndef _FILE_FONT_
#define _FILE_FONT_

#include "savedelete.h"
#include "character.h"

#include <map>

using namespace std;

// --------------------------- Font ---------------------------

class Font
{
public:
    explicit Font(map <char, Character*> image_ = {});
    Font(const Font *&font_);
    ~Font();

    // Images
    map <char, Character*> image;
};

#endif // _FILE_FONT_
