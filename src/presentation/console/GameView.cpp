#include "Domain/Game/GameState.h"
#include "presentation/console/GameView.h"
#include <raylib.h>

GameView::GameView( GameState& gamestate):gamestate(gamestate){

}

void GameView::Run(){

    InitWindow(1280, 720, "Cobble And Fog");
    setup.LoadTextures();
    while (mainmenu.GetResult()!=MenuResult::EXIT) {
   
    switch (mainmenu.GetResult())
    {
    case MenuResult::START:
        this->state=ViewState::SETUP;
        break;
    
    default:
        break;
    }
    BeginDrawing();

    ClearBackground(BLACK);

    switch (state)
    {
    case ViewState::MAINMENU:
       mainmenu.Update();
       mainmenu.Draw();
        break;
    case ViewState::SETUP:
       setup.Update();
       setup.Draw();
        break;

    }
    EndDrawing();
    }

    CloseWindow();
}

void GameView::SetOnSelection(std::function<void(int)>callback){
    this->Onselection=callback;
}
