#include "presentation/console/SetUpView.h"
#include <raylib.h>
#include <iostream>

void SetUpView::Update(){
    switch (state)
    {
    case SetUpState::INPUT_AGE:
        UpdateInPutAge();
        break;
    case SetUpState::SHOW_STARTING_PLAYER:
        UpdateStartingPlayer();

    case SetUpState::HERO_SELECTION:
        UpdateHeroSelection();
        break;
    }
}
void SetUpView::Draw(){

    switch (state)
    {
    case SetUpState::INPUT_AGE:
        DrawInputAge();
        break;
    case SetUpState::SHOW_STARTING_PLAYER:
        DrawStartingPlayer();
        break;

    case SetUpState::HERO_SELECTION:
        DrawHeroSelection();
        break;
    default:
        break;
    }
   
}

void SetUpView::UpdateInPutAge(){
int key = GetCharPressed();

    while (key > 0)
    {
        if (key >= '0' && key <= '9')
        {
            if(editingPlayer1)
            player1Age.push_back((char)key);
            else player2Age.push_back((char)key);
        }

        key = GetCharPressed();
    }
    if (IsKeyPressed(KEY_BACKSPACE))
    {
        if (editingPlayer1)
        {
            if(!player1Age.empty())
                player1Age.pop_back();
        }
        else
        {
            if(!player2Age.empty())
                player2Age.pop_back();
        }
    }

    Vector2 mouse = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        if (CheckCollisionPointRec(mouse, player1box))
        {
            editingPlayer1 = true;
        }
        else if (CheckCollisionPointRec(mouse, player2box))
        {

            editingPlayer1 = false;
        }
    }

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mouse, continueButton)){
        if(player1Age.empty()||player2Age.empty())
            return;
        int age1=std::stoi(player1Age);
        
        int age2=std::stoi(player2Age);
        if(age1>age2)
            firstPlayer=0;
        else firstPlayer=1;

        state=SetUpState::SHOW_STARTING_PLAYER;
    }
}
void SetUpView::UpdateStartingPlayer(){
    Vector2 mouse = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
    CheckCollisionPointRec(mouse, AdvanceToHeroSelectionButton))
    {
        state = SetUpState::HERO_SELECTION;
    }    
}
void SetUpView::UpdateHeroSelection(){

}
void SetUpView::DrawInputAge(){
    DrawText("Players Age", 480, 120, 40, WHITE);

    DrawText("Player 1 :", 400, 250, 30, WHITE);

    DrawText("Player 2 :", 400, 350, 30, WHITE);

  
    DrawRectangle(650,240,120,50,DARKGRAY);
    DrawText(player1Age.c_str(),665,255,30,WHITE);
    DrawRectangle(650,340,120,50,DARKGRAY);
    DrawText(player2Age.c_str(),665,355,30,WHITE);

      DrawRectangleLinesEx(
    editingPlayer1 ? player1box : player2box,
    3,
    YELLOW
    );
    DrawRectangle(520,500,220,60,GRAY);
    DrawText("Continue",560,515,30,BLACK);
}
void SetUpView::DrawStartingPlayer(){
    DrawText(
    firstPlayer == 0 ?
    "Player 1 chooses hero first." :
    "Player 2 chooses hero first.",
    350,
    420,
    30,
    GREEN
    );
    Rectangle advanceButton = {430, 520, 420, 60};

    DrawRectangleRec(advanceButton, GRAY);

    DrawText(
        "Advance To Hero Selection",
        455,
        535,
        25,
        BLACK
    );
}
void SetUpView::DrawHeroSelection(){

}
