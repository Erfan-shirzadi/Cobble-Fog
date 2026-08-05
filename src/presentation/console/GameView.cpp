#include "Domain/Game/GameState.h"
#include "presentation/console/GameView.h"
#include <raylib.h>
#include <iostream>
GameView::GameView( GameState& gamestate):gamestate(gamestate),setup(gamestate){
    setup.SetInputRequest(this->menurequest);
    Actions={
        {{223,780,380,60},"MANEVER"},
        {{223,840,380,60},"SCHEME"},
        {{223,900,380,60},"ATTACK"}
    };
}


void GameView::LoadTextures(){
    setup.LoadTextures();
    LoadCardsTexture();
}

void GameView::SetInputRequest(MenuRequest req){
    this->menurequest=req;
}
void GameView::SetState(ViewState state){
    this->state=state;
}


void GameView::Run(){

    this->setup.SetOnSelection(Onselection);

    InitWindow(/*12808*/1800, /*720*/1000, "Cobble And Fog");
    LoadTextures();
    while (mainmenu.GetResult()!=MenuResult::EXIT) {
    if(state==ViewState::MAINMENU)
        switch (mainmenu.GetResult())
        {
        case MenuResult::START:
            this->state=ViewState::SETUP;
            break;
        case MenuResult::LOAD:
       
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
    case ViewState::GAME:
       
        Draw();
         Update();
        break;

    }
    EndDrawing();
    }

    CloseWindow();
}

void GameView::SetOnSelection(std::function<void(int)>callback){
    this->Onselection=callback;
}


void GameView::Update(){
    // std::cout<<(int)menurequest.type<<std::endl;
    switch (menurequest.type)
    {
    case InputType::ACTION:
        UpdateAction();
        break;
    case InputType::CARD:
        
        break;

    case InputType::NODE:
        break;

    case InputType::HERO:

        break;
    default:
        break;
    }
}

void GameView::Draw(){
    setup.DrawBoard();
    DrawAction();
}

void GameView::DrawAction(){
    DrawText("Actions", 223, 730, 30, WHITE);
    if(menurequest.options.empty())
        Onselection(-1);
    
    int y = 780;
    

    for (int i = 0; i < Actions.size(); i++) {
        bool flag=false;
        for(auto action: menurequest.options){
            if(Actions[i].text==action)
                flag=true;
        }

        Color color ;
        if(flag)
            color = (i == selected) ? RED : LIGHTGRAY;
        else color=DARKGRAY;


        DrawText(Actions[i].text.c_str(), 223, y, 20, color);

        y += 60;
    }
}
void GameView::UpdateAction(){
        Vector2 mouse=GetMousePosition();
        for(int i{};i<Actions.size();i++){
            if(CheckCollisionPointRec(mouse,Actions[i].bounds)){
                
                selected=i;
               
        
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    bool flag=false;
                    for(auto action: menurequest.options){
                        if(Actions[i].text==action)
                            flag=true;
                    }
                    if(flag)Onselection(i);
                }
        }
    }   
}


void GameView::DrawHand(){
    Hero * hero=gamestate.currnetPlayer->GetHero();

}
void GameView::UpdateHand(){

}





void GameView::LoadCardsTexture(){
cardsTextures[CardId::AMBUSH]={LoadTexture("../inlude/Infrastructure/Assests/images/cards/dracula/ambush.png")};
cardsTextures[CardId::BAPISM_OF_BLOOD]={LoadTexture("../inlude/Infrastructure/Assests/images/cards/dracula/bapism-of-blood.png")};
cardsTextures[CardId::BEASTFORM]={LoadTexture("../inlude/Infrastructure/Assests/images/cards/dracula/beastform.png")};
cardsTextures[CardId::DASH]={LoadTexture("../inlude/Infrastructure/Assests/images/cards/dracula/dash.png")};
cardsTextures[CardId::LOOK_INTO_MY_EYES]={LoadTexture("../inlude/Infrastructure/Assests/images/cards/dracula/look-into-my-eyes.png")};
cardsTextures[CardId::EXPLOIT]={LoadTexture("../inlude/Infrastructure/Assests/images/cards/dracula/expliot.png")};
cardsTextures[CardId::FEEDINGFRENZY]={LoadTexture("../inlude/Infrastructure/Assests/images/cards/dracula/feeding-frenzy.png")};
cardsTextures[CardId::FEINT]={LoadTexture("../inlude/Infrastructure/Assests/images/cards/dracula/feint(1).png")};
cardsTextures[CardId::MISTFORM]={LoadTexture("../inlude/Infrastructure/Assests/images/cards/dracula/mistform.png")};
cardsTextures[CardId::PERYUPON]={LoadTexture("../inlude/Infrastructure/Assests/images/cards/dracula/prey-upon.png")};
cardsTextures[CardId::RAVENING_SEDUCTION]={LoadTexture("../inlude/Infrastructure/Assests/images/cards/dracula/revening-seduction.png")};
cardsTextures[CardId::THIRST_FOR_SUSTENANCE]={LoadTexture("../inlude/Infrastructure/Assests/images/cards/dracula/thirst-for-sustenance.png")};
// cardsTextures[CardId::AMBUSH]={LoadTexture("../inlude/Infrastructure/Assests/images/cards/dracula/ambush.png")};
// cardsTextures[CardId::AMBUSH]={LoadTexture("../inlude/Infrastructure/Assests/images/cards/dracula/ambush.png")};

}
