#ifndef _FILE_PUSHMESSAGE_
#define _FILE_PUSHMESSAGE_

#include "timer.h"

#include <string>

using namespace std;

// --------------------------- Message ---------------------------

class PushMessage
{
public:
    explicit PushMessage(string text_ = "Text...", Timer deleteTimer_ = Timer(2000));

    // Timer
    Timer deleteTimer;

    // --------------------------- Encapsulation ---------------------------

    // Text
    string getText();
    void setText(string text_);

    // Text
private:
    string text;
public:
};

#endif // _FILE_PUSHMESSAGE_
