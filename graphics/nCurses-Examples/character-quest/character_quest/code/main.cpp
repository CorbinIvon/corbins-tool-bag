#include "main.h"

int main(int argc, char *argv[])
{
#ifdef DEBUG
    // Debugger
    QCoreApplication a(argc, argv);
#endif

    // Init
    initAll();

    // Shake Random
    srand(time(0));

#ifdef WINDOWS
    // Change lang
    PostMessage(GetForegroundWindow(), WM_INPUTLANGCHANGEREQUEST, 2, 0);
#endif

    // Set time of out screensaver
    timerScreensaver = timer(5000);

    // Off deleting saves mode
    deleteSave = false;

    // Clear selectedGMap
    selectedSaveSlot = -1;

    // Read save
    loadSaves();

    // Set Scene
    setScene(scene["screensaver"]);

    // Start Game

    cpu = clock();
    do
    {
        // Enum CPU
        cpu = clock() - cpu;

        if(selectedScene == scene["screensaver"])
        {
            if(clock() > timerScreensaver)
            {
                setScene(scene["main"]);
            }
        }

        // Set old Width / Height
        scrOldWidth = screenWidth();
        scrOldHeight = screenHeight();

        // Draw
        update();

        // Set CPU
        cpu = clock();

        // Get char
        keyStroke = getch();
        keyChar = char(keyStroke);

        // Keys Commands
        if(selectedScene != scene["savesNew"])
        {
            keysCommand(keyStroke);
        }
        else
        {
            if(keyStroke != -1)
            {
                if(keyBackspace(keyStroke))
                {
                    if(!selectedScene->label[1]->getText().empty())
                    {
                        // Backspace
                        string newText = selectedScene->label[1]->getText();
                        newText.pop_back();

                        selectedScene->label[1]->setText(newText);
                    }
                }
                else if(keyEnter(keyStroke))
                {
                    // Create save
                    saveSlot[selectedSaveSlot] = new SaveSlot(new GMapWorld(biome["forest"]), selectedScene->label[1]->getText());
                    saveSlot[selectedSaveSlot]->gMap.emptyGMapHome = new GMapHome(biome["home"]);

                    // To game

                    setScene(scene["game"]);
                }
                else
                {
                    // Valid keyChar?
                    if(selectedScene->label[1]->font->image.find(keyChar) !=
                       selectedScene->label[1]->font->image.end())
                    {
                        // Add keyChar
                        string newText = selectedScene->label[1]->getText();
                        newText.push_back(keyChar);

                        selectedScene->label[1]->setText(newText);
                    }
                }
            }
        }
    }
    while(true);

    endwin();

    // Delete all

    // GMaps
    SAVE_DEL_MAS(saveSlot);

    // Messages
    SAVE_DEL_MAS(message);

    return 0;
}

void keysCommand(int keyStroke_)
{
    // --------------------------- Keys Command ---------------------------

    // Game
    if(selectedScene == scene["game"])
    {
        // Up
        if(keyEng('w', keyStroke_))
        {
           if(!saveSlot[selectedSaveSlot]->gMap.movePlayerUp().first)
           {
               message.push_back(new PushMessage("You don't move up"));
           }
        }

        // Down
        else if(keyEng('s', keyStroke_))
        {
            if(!saveSlot[selectedSaveSlot]->gMap.movePlayerDown().first)
            {
                message.push_back(new PushMessage("You don't move down"));
            }
        }

        // Left
        else if(keyEng('a', keyStroke_))
        {
            if(!saveSlot[selectedSaveSlot]->gMap.movePlayerLeft().first)
            {
                message.push_back(new PushMessage("You don't move left"));
            }
        }

        // Right
        else if(keyEng('d', keyStroke_))
        {
            if(!saveSlot[selectedSaveSlot]->gMap.movePlayerRight().first)
            {
                message.push_back(new PushMessage("You don't move right"));
            }
        }

        // Pause
        else if(keyEsc(keyStroke_))
        {
            setScene(scene["gamePause"]);
        }
    }

    // Main
    else if(selectedScene == scene["main"])
    {
        // Escape
        if(keyEsc(keyStroke_))
        {
            setScene(scene["mainExit"]);
        }
    }

    // Main
    else if(selectedScene == scene["gamePause"])
    {
        // Escape
        if(keyEsc(keyStroke_))
        {
            setScene(scene["game"]);
        }
    }

    // Main
    else if(selectedScene == scene["gameExit"])
    {
        // Escape
        if(keyEsc(keyStroke_))
        {
            setScene(scene["pause"]);
        }
    }

    // Saves
    else if(selectedScene == scene["saves"])
    {
        // Escape
        if(keyEsc(keyStroke_))
        {
            setScene(scene["main"]);
        }
    }

    // Saves
    else if(selectedScene == scene["exit"])
    {
        // Escape
        if(keyEsc(keyStroke_))
        {
            setScene(scene["main"]);
        }
    }

    // Buttons
    if(!selectedScene->button.empty())
    {
        // Select left button
        if(keyEng('a', keyStroke_))
        {
            if(selectedButton > 0)
            {
                selectedButton--;
            }
        }

        // Select right button
        else if(keyEng('d',  keyStroke_))
        {
            if(selectedButton < selectedScene->button.size()-1)
            {
                selectedButton++;
            }
        }

        // Click select button
        else if(keyEnter(keyStroke_))
        {
            buttonClick();
        }
    }
}

void update()
{
    // Tact animations texts
    if(!selectedScene->label.empty())
    {
        for(auto mLabel: selectedScene->label)
        {
            mLabel->animationTact();
        }
    }

    // Clear screen
    erase();

    // Draw

    // Scene
    drawScene(selectedScene);

    // Messages
    drawMessages();

    // Debug texts
#ifdef DEBUG
    move(0,0);
    if(selectedSaveSlot != -1)
    printw("x:%i y:%i", saveSlot[selectedSaveSlot]->gMap.getPlayerX(), saveSlot[selectedSaveSlot]->gMap.getPlayerY());
#endif

    refresh();
}

void cls(int x_, int y_, int width_, int height_)
{
    // Clear screen

    for(int mY = y_; mY < y_ + height_; mY++)
    {
        for(int mX = x_; mX < x_ + width_; mX++)
        {
            move(mY, mX);
            printw(" ");
        }
    }
}

void drawScene(Scene *scene_)
{
    // Draw Scene

    // Main

    if(scene_ == scene["main"])
    {

    }

    // Main Exit

    else if(scene_ == scene["mainExit"])
    {

    }

    // Saves

    else if(scene_ == scene["saves"])
    {

    }

    // First game

    else if(scene_ == scene["savesNew"])
    {

    }

    // Game

    else if(scene_ == scene["game"])
    {
        // Draw
        saveSlot[selectedSaveSlot]->gMap.draw(Rect(Coord(gameRectX, gameRectY), gameRectWidth, gameRectHeight));
    }

    // Pause

    else if(scene_ == scene["gamePause"])
    {
        // Draw game (background)
        drawScene(scene["game"]);

        // Label "Pause"
        cls(0, 0, screenWidth(), screenHeight() / 3.0);
        cls(0, screenHeight() / 3.0 * 2.0, screenWidth(), screenHeight());
    }

    // Exit Pause

    else if(scene_ == scene["gamePauseExit"])
    {
        drawScene(scene["gamePause"]);
    }

    // Draw other scene
    if(scene_ == selectedScene)
    {
        scene_->draw(selectedButton, screen());
    }
}

void initCharPairs()
{
    // Set pairs
    for(int mPair = 1; mPair <= COLORS; mPair++)
    {
        init_pair(mPair, mPair, COLOR_BLACK);
    }
}

void setScene(Scene *scene_)
{
    // Text animation
    if(!scene_->label.empty())
    {
        // Stop all texts animations
        for(auto &mLabel: scene_->label)
        {
            mLabel->animationStop();
        }

        // Start first text animation
        scene_->label[0]->animationStart();
    }

    // Select button
    selectedButton = 0;

    // Set
    selectedScene = scene_;
}

void drawMessages()
{
    // Messages

    for(size_t mMsg = 0; mMsg < message.size(); mMsg++)
    {
        if(!message[mMsg]->deleteTimer.finished())
        {
            move(screenHeight() - 1 - mMsg, 0);
            printw("%s",message[mMsg]->getText().c_str());
        }
        else
        {
            message.pop_back();
        }
    }
}

void buttonClick()
{
    // Button click

    // --------------------------- Main ---------------------------

    if(selectedScene == scene["main"])
    {
        // Play
        if(selectedScene->button[selectedButton]->getName() == "Play")
        {
            setScene(scene["saves"]);
            loadSaves();
        }

        // Continue
        else if(selectedScene->button[selectedButton]->getName() == "Continue")
        {
            if(selectedSaveSlot != -1 &&
                    !saveSlot[selectedSaveSlot]->is_empty())
            {
                // Continue game
                loadSaves();
                setScene(scene["game"]);
            }
            else
            {
                message.push_back(new PushMessage("No saves!"));
            }
        }
    }

    // --------------------------- Pause ---------------------------

    else if(selectedScene == scene["gamePause"])
    {
        // Exit to main
        if(selectedScene->button[selectedButton]->getName() == "Main")
        {
            // To main
            if(saveSlot[selectedSaveSlot]->saved())
            {
                setScene(scene["main"]);
            }
            else
            {
                setScene(scene["gamePauseExit"]);
            }
        }

        // Save
        else if(selectedScene->button[selectedButton]->getName() == "Save")
        {
            saveSaves("save.txt");
        }
    }

    // --------------------------- Exit ---------------------------

    else if(selectedScene == scene["mainExit"])
    {
        // No
        if(selectedScene->button[selectedButton]->getName() == "No")
        {
            setScene(scene["main"]);
        }

        // Yes
        else if(selectedScene->button[selectedButton]->getName() == "Yes")
        {
            exit(EXIT_SUCCESS);
        }
    }

    // --------------------------- Game exit ---------------------------

    else if(selectedScene == scene["gamePauseExit"])
    {
        // Save and exit
        if(selectedScene->button[selectedButton]->getName() == "Save and exit")
        {
            saveSaves("save.txt");
            setScene(scene["main"]);
        }

        // Exit unsaved
        else if(selectedScene->button[selectedButton]->getName() == "Exit unsaved")
        {
            setScene(scene["main"]);
        }
    }

    // --------------------------- Maps ---------------------------

    else if(selectedScene == scene["saves"])
    {
        if(selectedScene->button[selectedButton]->getName() == "Delete" ||
                selectedScene->button[selectedButton]->getName() == "Cancel")
        {
            // To delete/load save
            deleteSave = !deleteSave;

            // Rename button

            // New button
            Button* newButton =  selectedScene->button[selectedButton];

            if(deleteSave)
            {
                // Set name "Cancel"
                newButton->setName("Cancel");
            }
            else
            {
                // Set name "Delete"
                newButton->setName("Cancel");
            }

            // Set
            selectedScene->button[selectedButton] = newButton;
        }
        else
        {
            // Select GMap
            selectedSaveSlot = selectedButton;

            if(!saveSlot[selectedButton]->is_empty())
            {
                if(deleteSave)
                {
                    // Delete
                    saveSlot[selectedButton] = new SaveSlot(new GMapWorld(biome["forest"], new GMapHome(biome["home"])));

                    // Message
                    message.push_back(new PushMessage("Deleted"));

                    // Button Cancel
                    selectedButton = selectedScene->buttonId["Delete"];
                    buttonClick();

                    // Update saves/buttons
                    saveSaves();
                    loadSaves();
                }
                else
                {
                    // To game
                    setScene(scene["game"]);
                    saveSlot[selectedSaveSlot]->gMap.setSaved(true);
                }
            }
            else
            {
                if(deleteSave)
                {
                    // Message "This is empty slot"
                    message.push_back(new PushMessage("This is empty slot"));
                }
                else
                {
                    // First game

                    // Clear label
                    Label *newLabel = scene["savesNew"]->label[1];
                    newLabel->setText(string());

                    scene["savesNew"]->label[1] = newLabel;

                    // Set scene
                    setScene(scene["savesNew"]);
                }
            }
        }
    }
}

void saveSaves(string fileName_)
{
    // Save

    ofstream file(fileName_.c_str());

    // Old selected gMap
    file<<"oldSaveSlot "<<selectedSaveSlot<<endl;

    // GMaps
    for(int mSave = 0; mSave < saveSlotNum; mSave++)
    {
        // SaveSlot number
        file<<"saveSlot "<<mSave<<endl;

            // Player name
            file<<" playerName "<<saveSlot[mSave]->getPlayerName()<<endl;

            file<<" gMapWorld"<<endl;

                // Biome name
                for(auto &mBiome: biome)
                {
                    if(saveSlot[mSave]->gMap.biome == mBiome.second)
                    {
                        file<<"  biome "<<mBiome.first<<endl;
                        break;
                    }
                }

                // Player coords
                file<<"  player"<<endl;

                    file<<"   x "<<saveSlot[mSave]->gMap.getPlayerX()<<endl;
                    file<<"   y "<<saveSlot[mSave]->gMap.getPlayerY()<<endl;

                file<<"  /player"<<endl;

                // GMap slots
                for(auto mX: saveSlot[mSave]->gMap.slot)
                {
                    for(auto mY: mX.second)
                    {
                        file<<"  gMapSlot"<<endl;

                            file<<"   x "<<mX.first<<endl;
                            file<<"   y "<<mY.first<<endl;

                            file<<"   sType "<<mY.second->getStaticType()<<endl;
                            file<<"   dType "<<mY.second->getDynamicType()<<endl;

                        file<<"  /gMapSlot"<<endl;
                    }
                }

                // Home
                for(auto mHomeX: saveSlot[mSave]->gMap.gMapHome)
                {
                    for(auto mHomeY: mHomeX.second)
                    {
                        file<<"  gMapHome"<<endl;

                            // Biome name
                            for(auto &mBiome: biome)
                            {
                                if(mHomeY.second->biome == mBiome.second)
                                {
                                    file<<"  biome "<<mBiome.first<<endl;
                                    break;
                                }
                            }

                            // Coords
                            file<<"   x "<<mHomeX.first<<endl;
                            file<<"   y "<<mHomeY.first<<endl;

                            // Wall type
                            file<<"   wallType "<<mHomeY.second->gMapSlotWall.getDynamicType()<<endl;

                            // Slots
                            for(auto mX: mHomeY.second->slot)
                            {
                                for(auto mY: mX.second)
                                {
                                    file<<"   gMapSlot"<<endl;

                                        file<<"    x "<<mX.first<<endl;
                                        file<<"    y "<<mY.first<<endl;

                                        file<<"    sType "<<mY.second->getStaticType()<<endl;
                                        file<<"    dType "<<mY.second->getDynamicType()<<endl;

                                    file<<"   /gMapSlot"<<endl;
                                }
                            }

                        file<<"  /gMapHome"<<endl;
                    }
                }

            file<<" /gMapWorld"<<endl;

        file<<"/saveSlot"<<endl;

        // Saved bool
        saveSlot[mSave]->gMap.setSaved(true);
    }

    file.close();

    // Message
    message.push_back(new PushMessage("Saved"));
}

void loadSaves(string fileName_)
{
    // Read Saves

    ifstream file(fileName_.c_str());

    if(file.is_open())
    {
        // Command
        string command;

        while(!file.fail())
        {
            // Get command
            file>>command;

            // Old SaveSlot Num
            if(command == "oldSaveSlot")
            {
                // Select old save
                file>>selectedSaveSlot;
            }

            // SaveSlot

            if(command == "saveSlot")
            {
                // Clear
                SaveSlot* rSaveSlot = new SaveSlot(new GMapWorld(biome["forest"], new GMapHome(biome["home"])));
                int rSaveSlotNum = 0;

                // Read num
                file>>rSaveSlotNum;

                // Read
                do
                {
                    file>>command;

                    // Player Name
                    if(command == "playerName")
                    {
                        // Get
                        string name_;
                        file>>name_;

                        // Set
                        rSaveSlot->setPlayerName(name_);
                    }

                    // GMapWorld

                    else if(command == "gMapWorld")
                    {
                        // Clear
                        GMapWorld rGMapWorld = GMapWorld();

                        do
                        {
                            file>>command;

                            // Biome name
                            if(command == "biome")
                            {
                                string biomeName;
                                file>>biomeName;

                                rGMapWorld.biome = biome[biomeName];
                            }

                            // Game Home

                            if(command == "gHome")
                            {
                                // Clear
                                GMapHome *rGMapHome = new GMapHome();
                                int rGMapHomeX;
                                bool rGMapHomeXB = false;
                                int rGMapHomeY;
                                bool rGMapHomeYB = false;

                                // Read
                                do
                                {
                                    file>>command;

                                    // Biome
                                    if(command == "biome")
                                    {
                                        string biomeName;
                                        file>>biomeName;

                                        rGMapHome->biome = biome[biomeName];
                                    }

                                    // X
                                    else if(command == "x")
                                    {
                                        file>>rGMapHomeX;
                                        rGMapHomeXB = true;
                                    }

                                    // Y
                                    else if(command == "y")
                                    {
                                        file>>rGMapHomeY;
                                        rGMapHomeYB = true;
                                    }

                                    // Wall type
                                    else if(command == "wallType")
                                    {
                                        // Get
                                        chtype wallType_;
                                        file>>wallType_;

                                        // Set
                                        rGMapHome->gMapSlotWall = GMapSlot(' ', wallType_);
                                    }

                                    // Slot

                                    else if(command == "gMapSlot")
                                    {
                                        // Clear
                                        GMapSlot *rGMapSlot = new GMapSlot();
                                        int rGMapSlotX;
                                        bool rGMapSlotXB = false;
                                        int rGMapSlotY;
                                        bool rGMapSlotYB = false;

                                        // Read
                                        do
                                        {
                                            file>>command;

                                            // X
                                            if(command == "x")
                                            {
                                                file>>rGMapSlotX;
                                                rGMapSlotXB = true;
                                            }

                                            // Y
                                            else if(command == "Y")
                                            {
                                                file>>rGMapSlotY;
                                                rGMapSlotYB = true;
                                            }

                                            // Static type
                                            else if(command == "sType")
                                            {
                                                chtype staticType_;
                                                file>>staticType_;
                                                rGMapSlot->setStaticType(staticType_);
                                            }

                                            // Dynamic type
                                            else if(command == "dType")
                                            {
                                                chtype dynamicType_;
                                                file>>dynamicType_;
                                                rGMapSlot->setDynamicType(dynamicType_);
                                            }

                                        } while(command != "/gMapSlot");

                                        // X and Y initialized?
                                        assert(rGMapSlotXB && rGMapSlotYB && ("X or Y in gMapSlot uninitialized" || true));

                                        // Set
                                        rGMapHome->slot[rGMapSlotX][rGMapSlotY] = rGMapSlot;
                                    }

                                } while(command != "/gHome");

                                // X and Y initialized?
                                assert(rGMapHomeXB && rGMapHomeYB && ("X or Y in GMapHome uninitialized" || true));

                                // Set
                                rGMapWorld.gMapHome[rGMapHomeX][rGMapHomeY] = rGMapHome;
                            }

                            // Player

                            else if(command == "player")
                            {
                                // Clear
                                bool rGMapWorldPlayerXB = false;
                                bool rGMapWorldPlayerYB = false;

                                // Read
                                do
                                {
                                    file>>command;

                                    // X
                                    if(command == "x")
                                    {
                                        int x_;
                                        file>>x_;
                                        rGMapWorld.setPlayerX(x_);
                                        rGMapWorldPlayerXB = true;
                                    }

                                    // Y
                                    else if(command == "y")
                                    {
                                        int y_;
                                        file>>y_;
                                        rGMapWorld.setPlayerY(y_);
                                        rGMapWorldPlayerYB = true;
                                    }

                                } while(command != "/player");

                                // X and Y initialized?
                                assert(rGMapWorldPlayerXB && rGMapWorldPlayerYB && ("X or Y in GMapWorld in player uninitialized" || true));
                            }

                            // Slot

                            else if(command == "gMapSlot")
                            {
                                // Clear
                                GMapSlot *rGMapSlot = new GMapSlot();
                                int rGMapSlotX;
                                bool rGMapSlotXB = false;
                                int rGMapSlotY;
                                bool rGMapSlotYB = false;

                                // Read
                                do
                                {
                                    file>>command;

                                    // X
                                    if(command == "x")
                                    {
                                        file>>rGMapSlotX;
                                        rGMapSlotXB = true;
                                    }

                                    // Y
                                    else if(command == "y")
                                    {
                                        file>>rGMapSlotY;
                                        rGMapSlotYB = true;
                                    }

                                    // Static type
                                    else if(command == "sType")
                                    {
                                        chtype staticType_;
                                        file>>staticType_;
                                        rGMapSlot->setStaticType(staticType_);
                                    }

                                    // Dynamic type
                                    else if(command == "dType")
                                    {
                                        chtype dynamicType_;
                                        file>>dynamicType_;
                                        rGMapSlot->setDynamicType(dynamicType_);
                                    }

                                } while(command != "/gMapSlot");

                                // X and Y initialized?
                                assert(rGMapSlotXB && rGMapSlotYB && ("X or Y uninitialized" || true));

                                // Set
                                rGMapWorld.slot[rGMapSlotX][rGMapSlotY] = rGMapSlot;
                            }

                        } while(command != "/gMapWorld");

                        // Set
                        rSaveSlot->gMap = rGMapWorld;
                    }

                } while(command != "/saveSlot");

                // Set

                // SaveSlot
                saveSlot[rSaveSlotNum] = rSaveSlot;

                // Rename Button

                // New Button
                Button* newButton = scene["saves"]->button[rSaveSlotNum];

                // Edit
                newButton->setName(rSaveSlot->getPlayerName());

                // Set
                scene["saves"]->button[rSaveSlotNum] = newButton;
            }
        }
    }

    file.close();
}

void initAll()
{
    // --------------------------- Init All ---------------------------

    // Init screen
    initscr();

    // Get keyboard control
    raw();

    // Active all keys
    keypad(stdscr, TRUE);

    // Off cursor
    curs_set(0);

    // Off echos
    noecho();

    // No delay getch
    nodelay(stdscr, TRUE);

    // Colors
    start_color();

    // Character pairs
    initCharPairs();

    // Scenes
    initScenes();

    // Biomes
    initBiomes();

    // GMaps
    for(auto &mSave: saveSlot)
    {
        mSave = new SaveSlot(new GMapWorld(biome["forest"], new GMapHome(biome["home"])));
    }
}
