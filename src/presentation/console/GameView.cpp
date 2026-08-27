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

    cards={ {310+10,800,110,150},
            {440+10,800,110,150},
            {570+10,800,110,150},
            {700+10,800,110,150},
            {830+10,800,110,150},
            {960+10,800,110,150},
            {1090+10,800,110,150},
            {1220+10,800,110,150},
            {1350+10,800,110,150}
        };

    question={ {1565,725,70,30},
               {1565,765,70,30},
               {1565,805,70,30}
        
    };
    nodeCenters=setup.GetNodeCenters();std::vector<Vector2> nodeCenters;
    
    backtomainMenu={820,440,240,100};

    YesSaveView={720,440,160,40};
    NoSaveView={990,440,160,40};

    Exit={1650,10,150,80};


    sessions={  {450,240,1010,120},
                {450,460,1010,120},
                {450,680,1010,120}
    };
}


void GameView::LoadTextures(){
    setup.LoadTextures();
    LoadCardsTexture();
    DraculaTeam=LoadTexture("../include/Infrastructure/Assets/images/dracula/DraculaTeam.png");
    SherlockTeam=LoadTexture("../include/Infrastructure/Assets/images/sherlock/SherlockTeam.png");
    InvisibleManTeam=LoadTexture("../include/Infrastructure/Assets/images/invisibleMan/InvisibleManTeam.png");
    WinDracual=LoadTexture("../include/Infrastructure/Assets/images/DraculaWinGame.png");
    WinSherlock=LoadTexture("../include/Infrastructure/Assets/images/SherlockWinGame.png");
    WinInvisibleMan=LoadTexture("../include/Infrastructure/Assets/images/InvisibleManWinGame.png");
    exitbutton=LoadTexture("../include/Infrastructure/Assets/images/Exit.png");
    saveview=LoadTexture("../include/Infrastructure/Assets/images/SaveView.png");
    SessionView=LoadTexture("../include/Infrastructure/Assets/images/Session.png");
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
    InitWindow(1800, 1100, "Cobble And Fog");
    LoadTextures();
    while (mainmenu.GetResult()!=MenuResult::EXIT) {

   
    BeginDrawing();

    ClearBackground(BLACK);
     if(state==ViewState::MAINMENU){
        mainmenu.Draw();
        mainmenu.Update();
        switch (mainmenu.GetResult())
        {
        case MenuResult::START:
            this->state=ViewState::SETUP;
            mainmenu.ResetResult();
            setup.ResetSet();
            Onselection(-1);
            break;
        case MenuResult::LOAD:

            this->state=ViewState::SESSION;
            ignoreSessionClick=true;
            Onselection(-3);

            
            break;
        }
    }

    switch (state)
    {
    case ViewState::MAINMENU:
       
       break;
    case ViewState::SETUP:
       setup.Update();
       setup.Draw();
       break;
    case ViewState::GAME:
        Draw();
        Update();
        break;
    case ViewState::GAMEOVER:
        DrawGameResult();
        UpdateGameResult();
        break;
    case ViewState::SESSION:
        DrawSession();
        UpdateSession();
        break;
    }
    DrawDetail();
    EndDrawing();
    }

    CloseWindow();
}

void GameView::SetOnSelection(std::function<void(int)>callback){
    this->Onselection=callback;
}


void GameView::Update(){
    
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
    case InputType::QUESTION:
        UpdateQuestion();
        break;
    default:
        break;
    }
    UpdateExit();
   
}

void GameView::Draw(){
    

    if(!exitb)
        setup.DrawBoard();
    
   
    DrawAction();
   
    
    DrawHand();
   

    DrawQuestion();
        

    DrawNode();
            

    DrawPlayers();
            

    DrawCombat();
           

    DrawExit();
           

}


void GameView::DrawAction(){
    DrawText("Actions", 123, 730, 30, WHITE);

    if(menurequest.options.empty() || (menurequest.type==InputType::LOAD))
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
               
                DrawText(std::to_string(i).c_str(),300,20,20,PURPLE);

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
    Hero * hero;
    
    if(gamestate.handview==HandView::CURRENTPLAYER)
        hero=gamestate.currnetPlayer->GetHero();
    else hero=gamestate.opponentPlayre->GetHero();
   
    if(menurequest.type==InputType::CARD){
        for(int i{};i<menurequest.cards.size();i++ ){
            for(int j{};j<hero->GetHand().size();j++){
                if(menurequest.cards[i]==hero->GetHand()[j]->GetCardId()){
                    DrawRectangleLines(cards[j].x,cards[j].y,cards[j].width,cards[j].height,YELLOW);

                }
            }
        }
    }
    
    for(int i=285 ;i<290;i++){
        for(int j=780;j<785;j++)
            DrawRectangleLines(i,j,1225,200,WHITE);

    }
    float x=300+25;
    float y=805;
    for(auto card:hero->GetHand()){
        
        Texture2D texture=cardsTextures[card->GetCardId()];
        DrawTextureEx(texture,Vector2{x,y},
        0.0f,0.4f,WHITE);
       
        x+=130;
    }


}

void GameView::DrawCombat(){

    if(!gamestate.combatsatat)
    DrawText("NO Comabat",830,720,20,DARKGRAY);
    else {
        DrawText("Comabat",830,720,20,RED);
        if(gamestate.combatsatat->Current->card){
        DrawTextureEx(cardsTextures[gamestate.combatsatat->Current->card->GetCardId()],Vector2{280,500},
        0.0f,0.65f,WHITE);
        

        }
        if(gamestate.combatsatat->Opponent->card){
        DrawTextureEx(cardsTextures[gamestate.combatsatat->Opponent->card->GetCardId()],Vector2{1360,500},
        0.0f,0.65f,WHITE);
       
        }


        
    }
}
void GameView::UpdateHand(){
    Vector2 mouse=GetMousePosition();
    Hero * hero;
    if(gamestate.handview==HandView::CURRENTPLAYER)
         hero=gamestate.currnetPlayer->GetHero();
    else hero=gamestate.opponentPlayre->GetHero();
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


void GameView::DrawPlayers(){
    
    if(gamestate.player1->GetHero()->GetFighterType()==FighterType::DRACULA)
    {
        DrawTextureEx(DraculaTeam,Vector2{20,70},
        0.0f,0.43f,WHITE);
        

       
    }
    else if(gamestate.player1->GetHero()->GetFighterType()==FighterType::SHERLOCK){
        DrawTextureEx(SherlockTeam,Vector2{20,70},
        0.0f,0.43f,WHITE);
    }
    else {
        DrawTextureEx(InvisibleManTeam,Vector2{20,70},
        0.0f,0.43f,WHITE);
    }
    Hero * hero=gamestate.player1->GetHero();
    std::vector<Fighter*>sidekick=hero->GetSideKicks();
    DrawText(std::to_string(hero->GetHP()).c_str(),340,240,20,WHITE);
    DrawText(std::to_string(hero->GetRemainingAction()).c_str(),340,260,20,WHITE);
    
        
            for(auto fighter:sidekick)
            {
                switch (fighter->GetFighterType())
                {
                case FighterType::SISTER_1:
                    DrawText(std::to_string(fighter->GetHP()).c_str(),235,470,20,WHITE);
                    break;
                case FighterType::DR_WATSON:
                    DrawText(std::to_string(fighter->GetHP()).c_str(),235,470,20,WHITE);
                    break;
                case FighterType::SISTER_2:
                    DrawText(std::to_string(fighter->GetHP()).c_str(),120,470,20,WHITE);
                    break;
                case FighterType::SISTER_3:
                    DrawText(std::to_string(fighter->GetHP()).c_str(),350,470,20,WHITE);
                    break;
                default:    
                    break;
            }
            }
        

   

    if(gamestate.player2->GetHero()->GetFighterType()==FighterType::DRACULA)
    {
        DrawTextureEx(DraculaTeam,Vector2{1380,70},
        0.0f,0.43f,WHITE);
       

        
    }
    else if(gamestate.player2->GetHero()->GetFighterType()==FighterType::SHERLOCK){
        DrawTextureEx(SherlockTeam,Vector2{1380,70},
        0.0f,0.43f,WHITE);
    }
    else {
        DrawTextureEx(InvisibleManTeam,Vector2{1380,70},
        0.0f,0.43f,WHITE);
    }
    hero=gamestate.player2->GetHero();
    DrawText(std::to_string(hero->GetHP()).c_str(),1700,240,20,WHITE);
    DrawText(std::to_string(hero->GetRemainingAction()).c_str(),1700,260,20,WHITE);

    sidekick=hero->GetSideKicks();
     for(auto fighter:sidekick)
            {
                switch (fighter->GetFighterType())
                {
                case FighterType::SISTER_1:
                    DrawText(std::to_string(fighter->GetHP()).c_str(),1600,470,20,WHITE);
                    break;
                case FighterType::DR_WATSON:
                    DrawText(std::to_string(fighter->GetHP()).c_str(),1600,470,20,WHITE);
                    break;
                case FighterType::SISTER_2:
                    DrawText(std::to_string(fighter->GetHP()).c_str(),1485,470,20,WHITE);
                    break;
                case FighterType::SISTER_3:
                    DrawText(std::to_string(fighter->GetHP()).c_str(),1715,470,20,WHITE);
                    break;
                default:    
                    break;
            }
            }
        
    
}


void GameView::DrawGameResult(){

    if(gamestate.gameresult==GameResult::DRACULA_WON){
        DrawTextureEx(WinDracual,{250,100},0,1,WHITE);
    }
    else if(gamestate.gameresult==GameResult::SHERLOCK_WON){
        DrawTextureEx(WinSherlock,{250,100},0,1,WHITE);
    }
    else {
        DrawTextureEx(WinInvisibleMan,{250,100},0,1,WHITE);
    }
}

void GameView::UpdateGameResult(){
    Vector2 mouse=GetMousePosition();

    DrawText(TextFormat("X: %.0f Y: %.0f",mouse.x,mouse.y),20,20,24,RED);
    DrawRectangleLinesEx(backtomainMenu,3,YELLOW);
    if(CheckCollisionPointRec(mouse,backtomainMenu)){
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
           
                state=ViewState::MAINMENU;
                return;
        }
    }
}


void GameView::DrawExit(){

    DrawText(TextFormat("X: %.0f Y: %.0f",GetMousePosition().x,GetMousePosition().y),20,20,24,RED);

    DrawTextureEx(exitbutton,{1650,10},0,0.12f,WHITE);
    if(exitb){
        DrawTextureEx(saveview,{450,70},0,0.7f,WHITE);
        
    }

    
}
void GameView::UpdateExit(){

    if(CheckCollisionPointRec(GetMousePosition(),Exit)){
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            
            exitb=true;

            
        }

    }
    if(CheckCollisionPointRec(GetMousePosition(),NoSaveView) && exitb){
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            state=ViewState::MAINMENU;
            Onselection(-4);
        }
    }
    if(CheckCollisionPointRec(GetMousePosition(),YesSaveView) && exitb){
       if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){ 
            state=ViewState::SESSION;
            Onselection(-2);
       }

    }
}

void GameView::DrawSession(){

    std::cout<<"Session drawed"<<std::endl;
    DrawTextureEx(SessionView,{40,20},0,1.3,WHITE);
    int y=300;
    for(auto option:menurequest.options){
        DrawText(option.c_str(),880,y,40,WHITE);
        y+=220;
    }
    DrawText(TextFormat("X: %.0f Y: %.0f",GetMousePosition().x,GetMousePosition().y),20,20,24,RED);

}
void GameView::UpdateSession(){

    // auto mouse=GetMousePosition();
    if(ignoreSessionClick){
        ignoreSessionClick=false;
        return;
    }

    for(int i{};i<sessions.size();i++){
        if(CheckCollisionPointRec(GetMousePosition(),sessions[i])){
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){ 

                switch (menurequest.type)
                {
                case InputType::SAVE:
                    state=ViewState::MAINMENU;
                    Onselection(i);
                    break;
                case InputType::LOAD:
                
                    if(menurequest.options[i]!="Empty"){
                        std::cout<<"selected : i " <<i<<std::endl;
                        Onselection(i);
                        state=ViewState::GAME;


                    }
                    
                    break;
            
                }
                    
            }

        }
    }

}

ViewState GameView::GetState()const{
    return this->state;
}

void GameView::DrawDetail(){
    std::string tip="";

    if(!gamestate.log.GetLogs().empty()){
        tip="Tip : ";
        tip+=gamestate.log.GetLogs().back();
    }
    
     
    int textWidth=MeasureText(tip.c_str(),20);
    int x=(900-textWidth /2);
    DrawText(tip.c_str(),x,35,20,WHITE);

    // 1550 940
    if(state==ViewState::GAME ){
        FighterType type=gamestate.currnetPlayer->GetHero()->GetFighterType();

        switch (type)
        {
        case FighterType::DRACULA:
            DrawText("Turn : Dracula",1550,940,30,RED);
            break;
        case FighterType::SHERLOCK:
            DrawText("Turn : Sherlock",1550,940,30,YELLOW);
            break;
        case FighterType::INVISIBLEMAN:
            DrawText("Turn : InvisibleMan",1550,940,30,BLUE);
            break;
        default:
            break;
        }
    }
}


void GameView::LoadCardsTexture(){
cardsTextures[CardId::AMBUSH]={LoadTexture("../include/Infrastructure/Assets/images/cards/dracula/ambush.png")};
cardsTextures[CardId::BAPISM_OF_BLOOD]={LoadTexture("../include/Infrastructure/Assets/images/cards/dracula/bapism.png")};
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
cardsTextures[CardId::CODED_NOTES]={LoadTexture("../include/Infrastructure/Assets/images/cards/InvisibleMan/coded-notes.png")};
cardsTextures[CardId::DREAMIN_OF_REVENGE]={LoadTexture("../include/Infrastructure/Assets/images/cards/InvisibleMan/dreaming-of-revenge.png")};
cardsTextures[CardId::EMERGE_FROM_MIST]={LoadTexture("../include/Infrastructure/Assets/images/cards/InvisibleMan/emerge-from-mist.png")};
cardsTextures[CardId::IMPOSSIBLE_TO_SEE]={LoadTexture("../include/Infrastructure/Assets/images/cards/InvisibleMan/impossible-to-see.png")};
cardsTextures[CardId::INTO_THIN_AIR]={LoadTexture("../include/Infrastructure/Assets/images/cards/InvisibleMan/into-thin-air.png")};
cardsTextures[CardId::LURKING]={LoadTexture("../include/Infrastructure/Assets/images/cards/InvisibleMan/lurking.png")};
cardsTextures[CardId::REIGN_OF_TERROR]={LoadTexture("../include/Infrastructure/Assets/images/cards/InvisibleMan/reign-of-terror.png")};
cardsTextures[CardId::ROLLING_FOG]={LoadTexture("../include/Infrastructure/Assets/images/cards/InvisibleMan/rolling-fog.png")};
cardsTextures[CardId::SLIP_AWAY]={LoadTexture("../include/Infrastructure/Assets/images/cards/InvisibleMan/slip-away.png")};
cardsTextures[CardId::STEP_LIGHTLY]={LoadTexture("../include/Infrastructure/Assets/images/cards/InvisibleMan/step-lightly.png")};



}
