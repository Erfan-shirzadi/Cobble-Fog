#include "Domain/Game/GameState.h"
#include "presentation/console/GameView.h"
#include <raylib.h>
#include <iostream>
GameView::GameView( GameState& gamestate):gamestate(gamestate),setup(gamestate){
    setup.SetInputRequest(this->menurequest);
    Actions={
        {{123,780,280,60},"MANEVER"},
        {{123,840,280,60},"SCHEME"},
        {{123,900,280,60},"ATTACK"}
    };

    cards={ {310+10,710,110,150},
            {440+10,710,110,150},
            {570+10,710,110,150},
            {700+10,710,110,150},
            {830+10,710,110,150},
            {960+10,710,110,150},
            {1090+10,710,110,150},
            {1220+10,710,110,150},
            {1350+10,710,110,150}
        };

    question={ {1565,725,70,30},
               {1565,765,70,30},
               {1565,805,70,30}
        
    };
    nodeCenters=setup.GetNodeCenters();std::vector<Vector2> nodeCenters;
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
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    if(IsKeyPressed(KEY_F11))
        ToggleFullscreen();
    InitWindow(/*128081800*/1800, /*720*/1100, "Cobble And Fog");
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
        UpdateHand();
        break;

    case InputType::NODE:
        UpdateNode();
        break;

    case InputType::HERO:

        break;
    case InputType::QUESTION:
        UpdateQuestion();
        break;
    default:
        break;
    }
    // UpdateQuestion();
}

void GameView::Draw(){
    setup.DrawBoard();
    DrawAction();
    DrawHand();
    DrawQuestion();
    DrawNode();
}

void GameView::DrawAction(){
    DrawText("Actions", 123, 730, 30, WHITE);
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


        DrawText(Actions[i].text.c_str(), 123, y, 20, color);

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

    if(menurequest.type==InputType::CARD){if(menurequest.cards.empty())
        Onselection(-1);
    // for(auto card:cards){
    //     DrawRectangleLines(card.x,card.y,card.width,card.height,YELLOW);
    // }

    for(int i{};i<menurequest.cards.size();i++ ){
        for(int j{};j<hero->GetHand().size();j++){
            if(menurequest.cards[i]==hero->GetHand()[j]->GetCardId()){
                DrawRectangleLines(cards[j].x,cards[j].y,cards[j].width,cards[j].height,YELLOW);

            }
        }
    }}
    
    for(int i=285 ;i<290;i++){
        for(int j=700;j<705;j++)
            DrawRectangleLines(i,j,1225,200,WHITE);

    }
    float x=300+25;
    float y=715;
    for(auto card:hero->GetHand()){
        // DrawTexture(cardsTextures[card->GetCardId()],x,715,WHITE);
        Texture2D texture=cardsTextures[card->GetCardId()];
        DrawTextureEx(texture,Vector2{x,y},
        0.0f,0.4f,WHITE);
       
        x+=130;
    }

}
void GameView::UpdateHand(){
    Vector2 mouse=GetMousePosition();
    Hero * hero=gamestate.currnetPlayer->GetHero();
    for(int i{};i<cards.size();i++){
            if(CheckCollisionPointRec(mouse,cards[i])){
                
                selected=i;
               
        
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    bool flag=false;
                    for(auto card: menurequest.cards){
                        if(hero->GetHand()[selected]->GetCardId()==card)
                            flag=true;
                    }
                    if(flag)Onselection(i);
                }
        }
    }   

}


void GameView::DrawQuestion(){
    
    for(int i=1550 ;i<1555;i++){
        for(int j=700;j<705;j++)
            DrawRectangleLines(i,j,200,200,WHITE);

        }
    if(menurequest.type==InputType::QUESTION){
        
        int y=725;
        for(int i{};i<menurequest.options.size();i++){

            Color color = (i == selected) ? RED : LIGHTGRAY;

            DrawText(menurequest.options[i].c_str(),1565,y,20,WHITE);
            y+=40;
        }
        
    }

}

void GameView::UpdateQuestion(){
    
    Vector2 mouse=GetMousePosition();
    for(int i{};i<question.size();i++){
            if(CheckCollisionPointRec(mouse,question[i])){
                
                selected=i;
               
        
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                   
                    if(i<menurequest.options.size())
                        Onselection(selected);
                }
        }
    }   

}

void GameView::UpdateNode(){

    // Vector2 mouse=GetMousePosition();
    // for(int i{};i<nodeCenters.size();i++){
    //         if(CheckCollisionPointCircle(GetMousePosition(),nodeCenters[menurequest.nodes[i]-1],40.f)){
            
    //             selected=i;
               
        
    //             if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                   
                    
    //             }
    //     }
    // }   
     if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        for(int i{};i<menurequest.nodes.size();i++){
            if(CheckCollisionPointCircle(GetMousePosition(),nodeCenters[menurequest.nodes[i]-1],40.f)){
            Onselection(i);
            break;
            }
        }
    }

}
void GameView::DrawNode(){

    for(int node: menurequest.nodes)
        DrawCircleLines(nodeCenters[node-1].x,nodeCenters[node-1].y,40.f,YELLOW);

}


void GameView::LoadCardsTexture(){
cardsTextures[CardId::AMBUSH]={LoadTexture("../include/Infrastructure/Assets/images/cards/dracula/ambush.png")};
cardsTextures[CardId::BAPISM_OF_BLOOD]={LoadTexture("../include/Infrastructure/Assets/images/cards/dracula/bapism-of-blood.png")};
cardsTextures[CardId::BEASTFORM]={LoadTexture("../include/Infrastructure/Assets/images/cards/dracula/beastform.png")};
cardsTextures[CardId::DASH]={LoadTexture("../include/Infrastructure/Assets/images/cards/dracula/dash.png")};
cardsTextures[CardId::LOOK_INTO_MY_EYES]={LoadTexture("../include/Infrastructure/Assets/images/cards/dracula/look-into-my-eyes.png")};
cardsTextures[CardId::EXPLOIT]={LoadTexture("../include/Infrastructure/Assets/images/cards/dracula/exploit.png")};
cardsTextures[CardId::FEEDINGFRENZY]={LoadTexture("../include/Infrastructure/Assets/images/cards/dracula/feeding-frenzy.png")};
cardsTextures[CardId::FEINT]={LoadTexture("../include/Infrastructure/Assets/images/cards/dracula/feint-dracula.png")};
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
