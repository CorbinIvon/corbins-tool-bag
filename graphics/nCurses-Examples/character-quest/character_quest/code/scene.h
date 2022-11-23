#ifndef _FILE_SCENE_
#define _FILE_SCENE_

#include "savedelete.h"
#include "screen.h"
#include "button.h"
#include "label.h"

#include <string>
#include <vector>

using namespace std;

// --------------------------- Scene ---------------------------

class Scene
{
public:
    explicit Scene(vector <Label*> labels_ = {}, vector <Button*> buttons_ = {},
                         bool alignButtonX_ = false, int buttonY_ = screenHeightDefault/2, int alignButtonsY_ = false, int buttonX_ = screenWidthDefault/2);
    Scene(const Scene *&scene_);
    ~Scene();

    // Buttons
    vector <Button*> button;
    map <string, int> buttonId;

    // Labels
    vector <Label*> label;

    // Draw
    void draw(int selectedButton_, Rect *screen_);

    // Buttons
    void drawButtons(int selectedButton_, Rect* screen_);

    // Labels
    void drawLabels(Rect *screen_);

    // Add button
    void addButton(Button *button_);

    // Align
    void alignButtonsX(int y_);
    void alignButtonsY(int x_);
};

#endif // _FILE_SCENE_
