#ifndef _FILE_SCENES_
#define _FILE_SCENES_

#include "screen.h"
#include "fonts.h"
#include "scene.h"

#include <string>
#include <map>

using namespace std;

// --------------------------- Scenes ---------------------------

map <string, Scene*> scene;

// Set
void initScenes()
{
    // --------------------------- Screensaver ---------------------------

    scene["screensaver"] = new Scene( { new Label("CoolONE", screenWidthDefault/8, screenHeightDefault/8, screenWidthDefault/4*3-screenWidthDefault/8, screenHeightDefault/2-screenHeightDefault/8, fontOld),
                                        new Label("presents", screenWidthDefault/4, screenHeightDefault/2, screenWidthDefault/8*7 - screenWidthDefault/4, screenHeightDefault/2-screenHeightDefault/8, fontFuture) } );

    // --------------------------- Main ---------------------------

    scene["main"] = new Scene( { new Label("Character", 0, 0, screenWidthDefault, screenHeightDefault/3, fontFuture),
                                 new Label("Quest", 0, screenHeightDefault/3, screenWidthDefault, screenHeightDefault/3, fontOld) },

                               { new Button("Play"),
                                 new Button("Continue") },
                               true, screenHeightDefault/6*5 );

    // --------------------------- Exit ---------------------------

    scene["mainExit"] = new Scene( { new Label("Really?", 0, 0, screenWidthDefault, screenHeightDefault/3*2, fontFuture) },

                                   { new Button("No", screenWidthDefault/3, screenHeightDefault/6*5),
                                     new Button("Yes", screenWidthDefault/3*2, screenHeightDefault/6*5) },
                                   true, screenHeightDefault/6*5 );

    // --------------------------- Saves ---------------------------

    scene["saves"] = new Scene( { new Label("Saves", screenWidthDefault/6, screenHeightDefault/3*2/6, screenWidthDefault/3*2, screenHeightDefault/3+screenHeightDefault/3/3, fontFuture) },

                                { new Button("Slot 1", screenWidthDefault/6, screenHeightDefault/6*5),
                                  new Button("Slot 2", screenWidthDefault/6*2, screenHeightDefault/6*5),
                                  new Button("Slot 3", screenWidthDefault/6*3, screenHeightDefault/6*5),
                                  new Button("Slot 4", screenWidthDefault/6*4, screenHeightDefault/6*5),
                                  new Button("Delete", screenWidthDefault/6*5, screenHeightDefault/6*5) },
                                true, screenHeightDefault/6*5 );

    // --------------------------- New Game ---------------------------

    scene["savesNew"] = new Scene( { new Label("Your name?", 0, 0, screenWidthDefault, screenHeightDefault/2, fontFuture),
                                     new Label("", 0, screenHeightDefault/2, screenWidthDefault, screenHeightDefault/2, fontOld, false) } );

    // --------------------------- Game ---------------------------

    scene["game"] = new Scene();

    // --------------------------- Game Pause ---------------------------

    scene["gamePause"] = new Scene( { new Label("Pause", 0, 1, screenWidthDefault, screenHeightDefault/3-2, fontFuture) },

                                    { new Button("Save", screenWidthDefault/3, screenHeightDefault/6*5),
                                      new Button("Main", screenWidthDefault/3*2, screenHeightDefault/6*5) },
                                    true, screenHeightDefault/6*5 );

    // --------------------------- Game Pause Exit ---------------------------

    scene["gamePauseExit"] = new Scene( { new Label("You not saved!", 0, 1, screenWidthDefault, screenHeightDefault/3-2, fontFuture) },

                                        { new Button("Save and exit", screenWidthDefault/3, screenHeightDefault/6*5),
                                          new Button("Exit unsaved", screenWidthDefault/3*2, screenHeightDefault/6*5) },
                                        true, screenHeightDefault/6*5 );
}

#endif // _FILE_SCENES_
