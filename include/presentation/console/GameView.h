#ifndef GAME_VIEW
#define GAME_VIEW
#include <vector>
#include "Application/interaction/MenuRequest.h"
#include <raylib.h>
#include "presentation/console/MainMenu.h"
#include "presentation/console/SetUpView.h"
#include <functional>

struct GameState;
enum class ViewState{
    MAINMENU,
    SETUP
};
class GameView{

    ViewState state=ViewState::MAINMENU;
    public:


    void Run();
    GameView( GameState&);
    void SetOnSelection(std::function<void(int)>callback);


    private:
    GameState & gamestate;

    MenuRequest menurequest;
    MainMenu mainmenu;
    SetUpView setup;

    std::vector<std::string> menuOptions;
    int selected=0;

    std::function<void(int)>Onselection;

};

#endif /* GAME_VIEW */
