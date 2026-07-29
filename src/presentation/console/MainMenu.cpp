#include "presentation/console/MainMenu.h"
#include <raylib.h>

MainMenu::MainMenu() {
    buttons = {
        {{450,250,380,60},"Start"},
        {{450,330,380,60},"Load Game"},
        {{450,410,380,60},"Exit"}
    };
}

void MainMenu::Update() {
    Vector2 mouse=GetMousePosition();
        for(int i{};i<buttons.size();i++){
            if(CheckCollisionPointRec(mouse,buttons[i].bounds)){
                selected=i;
        
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    switch (i) {
                    case 0:
                        result = MenuResult::START;
                        break;

                    case 1:
                        result = MenuResult::LOAD;
                        break;

                    case 2:
                        result = MenuResult::EXIT;
                        break;
                    }
                }
        }
    }   
    if (IsKeyPressed(KEY_UP)) {
        selected--;

        if (selected < 0)
            selected = buttons.size() - 1;
    }

    if (IsKeyPressed(KEY_DOWN)) {
        selected++;

        if (selected >= buttons.size())
            selected = 0;
    }

    if (IsKeyPressed(KEY_ENTER)) {

        switch (selected) {
        case 0:
            result = MenuResult::START;
            break;

        case 1:
            result = MenuResult::LOAD;
            break;

        case 2:
            result = MenuResult::EXIT;
            break;
        }
    }
}

void MainMenu::Draw() {

    DrawText("COBBLE AND FOG", 420, 120, 40, WHITE);

    int y = 250;

    for (int i = 0; i < buttons.size(); i++) {

        Color color = (i == selected) ? RED : LIGHTGRAY;

        DrawText(buttons[i].text.c_str(), 520, y, 30, color);

        y += 60;
    }
}

MenuResult MainMenu::GetResult() {
    return result;
}

void MainMenu::ResetResult() {
    result = MenuResult::NONE;
}