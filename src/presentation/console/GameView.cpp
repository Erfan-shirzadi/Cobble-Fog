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
    DrawHand();
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
    
    for(int i=400 ;i<405;i++){
        for(int j=700;j<705;j++)
            DrawRectangleLines(i,j,1000,250,WHITE);

    }
    float x=415;
    float y=715;
    for(auto card:hero->GetHand()){
        // DrawTexture(cardsTextures[card->GetCardId()],x,715,WHITE);
        Texture2D texture=cardsTextures[card->GetCardId()];
        DrawTextureEx(texture,Vector2{x,y},
        0.0f,0.65f,WHITE);
       
        x+=170;
    }

}
void GameView::UpdateHand(){

}





void GameView::LoadCardsTexture(){
cardsTextures[CardId::AMBUSH]={LoadTexture("../include/Infrastructure/Assets/images/cards/dracula/ambush.png")};
cardsTextures[CardId::BAPISM_OF_BLOOD]={LoadTexture("../include/Infrastructure/Assets/images/cards/dracula/bapism-of-blood.png")};
cardsTextures[CardId::BEASTFORM]={LoadTexture("../include/Infrastructure/Assets/images/cards/dracula/beastform.png")};
cardsTextures[CardId::DASH]={LoadTexture("../include/Infrastructure/Assets/images/cards/dracula/dash.png")};
cardsTextures[CardId::LOOK_INTO_MY_EYES]={LoadTexture("../include/Infrastructure/Assets/images/cards/dracula/look-into-my-eyes.png")};
cardsTextures[CardId::EXPLOIT]={LoadTexture("../include/Infrastructure/Assets/images/cards/dracula/exploit.png")};
cardsTextures[CardId::FEEDINGFRENZY]={LoadTexture("../include/Infrastructure/Assets/images/cards/dracula/feeding-frenzy.png")};
cardsTextures[CardId::FEINT]={LoadTexture("../include/Infrastructure/Assets/images/cards/dracula/feint(1).png")};
cardsTextures[CardId::MISTFORM]={LoadTexture("../include/Infrastructure/Assets/images/cards/dracula/mistform.png")};
cardsTextures[CardId::PERYUPON]={LoadTexture("../include/Infrastructure/Assets/images/cards/dracula/prey-upon.png")};
cardsTextures[CardId::RAVENING_SEDUCTION]={LoadTexture("../include/Infrastructure/Assets/images/cards/dracula/ravening-seduction.png")};
cardsTextures[CardId::THIRST_FOR_SUSTENANCE]={LoadTexture("../include/Infrastructure/Assets/images/cards/dracula/thirst-for-sustenance.png")};
cardsTextures[CardId::ADMINISTER_AID]={LoadTexture("../include/Infrastructure/Assets/images/cards/holms/administer-aid.png")};
cardsTextures[CardId::COUNTER_PUNCH]={LoadTexture("../include/Infrastructure/Assets/images/cards/holms/counterpunch.png")};
cardsTextures[CardId::DEDUCE_STRATEGY]={LoadTexture("../include/Infrastructure/Assets/images/cards/holms/deduce-strategy.png")};
cardsTextures[CardId::EDUCATION_NEVER_ENDS]={LoadTexture("../include/Infrastructure/Assets/images/cards/holms/education-never-ends.png")};
cardsTextures[CardId::ELIMINATE_THE_IMPOSSIBLE]={LoadTexture("../include/Infrastructure/Assets/images/cards/holms/eliminate-the-impossible.png")};
cardsTextures[CardId::FIXED_POINT_IN_A_CHANGING_AGE]={LoadTexture("../include/Infrastructure/Assets/images/cards/holms/fixed-point-in-a-changing-age.png")};
cardsTextures[CardId::MASTER_OF_DISGUISE]={LoadTexture("../include/Infrastructure/Assets/images/cards/holms/master-of-disguise.png")};
cardsTextures[CardId::SERVICE_REVOLVER]={LoadTexture("../include/Infrastructure/Assets/images/cards/holms/service-revolver.png")};
cardsTextures[CardId::STUDY_METHODS]={LoadTexture("../include/Infrastructure/Assets/images/cards/holms/study-methods.png")};
cardsTextures[CardId::THE_GAME_IS_AFOOT]={LoadTexture("../include/Infrastructure/Assets/images/cards/holms/the-game-is-afoot.png")};


}
