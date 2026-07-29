#include "Domain/Game/GameState.h"
#include "presentation/console/GameView.h"
#include <raylib.h>


void GameView::Run(){

    InitWindow(1280, 720, "Cobble And Fog");

    while (mainmenu.GetResult()!=MenuResult::EXIT) {
    this->mainmenu.Update();

    BeginDrawing();

    ClearBackground(BLACK);

    this->mainmenu.Draw();

    EndDrawing();
    }

    CloseWindow();
}

