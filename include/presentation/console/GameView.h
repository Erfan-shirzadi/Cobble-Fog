#ifndef GAME_VIEW
#define GAME_VIEW
#include <vector>
#include "Application/interaction/MenuRequest.h"
#include <raylib.h>
#include "presentation/console/MainMenu.h"
#include "presentation/console/SetUpView.h"
#include "presentation/console/MenuButton.h"
#include <functional>

struct GameState;
enum class ViewState{
    MAINMENU,
    SETUP,
    GAME
};
class GameView{

    ViewState state=ViewState::MAINMENU;
    public:


    void Run();
    GameView( GameState&);
    void SetOnSelection(std::function<void(int)>callback);
    void SetInputRequest(MenuRequest);
    void SetState(ViewState);


    void Update();
    void Draw();


    void DrawAction();
    void UpdateAction();
    void DrawHand();
    void UpdateHand();





    void LoadTextures();
    void LoadCardsTexture();
    private:
    GameState & gamestate;

    MenuRequest menurequest;

    
    MainMenu mainmenu;
    SetUpView setup;

    std::vector<std::string> menuOptions;
    int selected=0;

    std::function<void(int)>Onselection;


    std::vector<MenuBotton> Actions;
    std::unordered_map<CardId,Texture2D> cardsTextures;
};

#endif /* GAME_VIEW */
