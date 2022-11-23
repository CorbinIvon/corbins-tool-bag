#include "scene.h"

Scene::Scene(vector<Label *> labels_, vector<Button *> buttons_, bool alignButtonX_, int buttonY_, int alignButtonsY_, int buttonX_)
{
    // Button
    for(auto mButton: buttons_)
    {
        addButton(mButton);
    }

    // Label
    label = labels_;

    if(alignButtonX_)
    {
        alignButtonsX(buttonY_);
    }
    else if(alignButtonsY_)
    {
        alignButtonsY(buttonX_);
    }
}

Scene::Scene(const Scene *&scene_)
{
    Scene(scene_->label, scene_->button);
}

Scene::~Scene()
{
    // Button
    SAVE_DEL_MAS(button)

    // Label
    SAVE_DEL_MAS(label)
}

void Scene::draw(int selectedButton_, Rect* screen_)
{
    // Draw

    // Labels
    drawLabels(screen_);

    // Buttons
    drawButtons(selectedButton_, screen_);
}

void Scene::addButton(Button *button_)
{
    // Add button

    // Map
    size_t buttonsSize = button.size();
    buttonId[button_->getName()] = buttonsSize;

    // Button
    button.push_back(button_);
}

void Scene::alignButtonsX(int y_)
{
    // Align buttons width

    for(size_t mButton = 0; mButton < button.size(); mButton++)
    {
        button[mButton]->setX(screenWidthDefault / (button.size()+1) * (mButton+1));
        button[mButton]->setY(y_);
    }
}

void Scene::alignButtonsY(int x_)
{
    // Align buttons height

    for(size_t mButton = 0; mButton < button.size(); mButton++)
    {
        button[mButton]->setX(x_);
        button[mButton]->setY(screenHeightDefault / (button.size()+1) * (mButton+1));
    }
}

void Scene::drawButtons(int selectedButton_, Rect* screen_)
{
    // Draw buttons

    if(!button.empty())
    {
        // Deselect all
        for(size_t mButton = 0; mButton < button.size(); mButton++)
        {
            button[mButton]->setSelected(false);
        }

        // Select selected
        button[selectedButton_]->setSelected(true);

        // Draw
        for(size_t mButton = 0; mButton < button.size(); mButton++)
        {
            button[mButton]->draw(screen_);
        }
    }
}

void Scene::drawLabels(Rect* screen_)
{
    // Draw labels

    if(!label.empty())
    {        
        // Draw
        for(auto mLabel: label)
        {
            mLabel->draw(screen_->getWidth(), screen_->getHeight());
        }

        // Start next if previous finished
        for(size_t mLabel = 0; mLabel < label.size()-1; mLabel++)
        {
            if(label[mLabel]->animationFinished() &&
               !label[mLabel+1]->animationStarted())
            {
                label[mLabel+1]->animationStart();
            }
        }
    }
}
