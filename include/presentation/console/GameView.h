#ifndef GAME_VIEW
#define GAME_VIEW
#include <vector>
#include "Application/interaction/MenuRequest.h"
#include <raylib.h>
#include "presentation/console/MainMenu.h"

struct GameState;

class GameView{

    
    public:


    GameView( )=default;
    void Run();


    private:
    // GameState & gamestate;
    MenuRequest menurequest;
    MainMenu mainmenu;

    std::vector<std::string> menuOptions;
    int selected=0;

};

#endif /* GAME_VIEW */
