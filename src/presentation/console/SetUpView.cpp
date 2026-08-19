#include "presentation/console/SetUpView.h"
#include "Domain/Game/GameState.h"
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
    case SetUpState::PLACEMENT:
        UpdateSidekickPlacement();
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
    case SetUpState::PLACEMENT:
        DrawSidekickPlacement();
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
        if(age1>age2){
            firstPlayer=0;
            gamestate.currnetPlayer=gamestate.player1;
            gamestate.opponentPlayre=gamestate.player2;

        }
        else {
            firstPlayer=1;
            gamestate.currnetPlayer=gamestate.player2;
            gamestate.opponentPlayre=gamestate.player1;

        }

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
   
    Vector2 mouse = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        for (int i = 0; i < 3; i++)
        {
            if (CheckCollisionPointRec(mouse, heroRects[i]))
            {
                HeroSelected = i;
                if(!selectedHeroes[i]){
                std::cout<< i<<" Selected "<<mouse.x<<" "<<mouse.y<<std::endl;
                selectedHeroes[i]=true;
                onSelection(i);

                    if(gamestate.player1->GetHero() &&gamestate.player2->GetHero()){
                        state=SetUpState::PLACEMENT;
                        std::cout<<" State Must change com on man\n";
                    }
                }
            }
        }
    
    }
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
    std::string text=gamestate.currnetPlayer==gamestate.player1?"Player 1 Choose your hero":"Player 2 Choose your hero";
    DrawText(text.c_str(),40,40,30,WHITE);

    for(int i{};i<3;i++){
        
        Color tint=selectedHeroes[i]?GRAY:WHITE;
        DrawTexturePro(
            herotextures[i],
            Rectangle{
                0,
                0,
                (float)herotextures[i].width,
                (float)herotextures[i].height
            },
            heroRects[i],  
            Vector2{0, 0},
            0.0f,
            tint
        );
        // if(HeroSelected==i ){
        //     DrawRectangleLinesEx(heroRects[i],3,YELLOW);
        // }
    }

}

void SetUpView::LoadTextures(){
    this->herotextures[0]=LoadTexture("../include/Infrastructure/Assets/images/dracula/dracula.png");
    this->herotextures[1]=LoadTexture("../include/Infrastructure/Assets/images/sherlock/sherlockTran.png");
    this->herotextures[2]=LoadTexture("../include/Infrastructure/Assets/images/invisibleMan/invArt.png");
    this->watsontoken=LoadTexture("../include/Infrastructure/Assets/images/sherlock/drwatson.png");
    this->sisters[0]=LoadTexture("../include/Infrastructure/Assets/images/dracula/sis1.png");
    this->sisters[1]=LoadTexture("../include/Infrastructure/Assets/images/dracula/sis2.png");
    this->sisters[2]=LoadTexture("../include/Infrastructure/Assets/images/dracula/sis3.png");
    this->boardtexture=LoadTexture("../include/Infrastructure/Assets/images/board.png");
    this->fog=LoadTexture("../include/Infrastructure/Assets/images/invisibleMan/fog.png");
    
}
void SetUpView::SetOnSelection(std::function<void(int)>callback){
    this->onSelection=callback;
}
SetUpView::SetUpView(GameState & gamestate):gamestate(gamestate){}


void SetUpView::UpdateHeroPlacement(){
    Vector2 mouse = GetMousePosition();


    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        if(CheckCollisionPointCircle(GetMousePosition(),nodeCenters[0],40.f)){
            onSelection(0);
            menurequest->nodes.clear();
            
        }
        else if(CheckCollisionPointCircle(GetMousePosition(),nodeCenters[25],40.f)){
            menurequest->nodes.clear();
            onSelection(1);
            

        }
    }
    
}
void SetUpView::UpdateSidekickPlacement(){

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        for(int i{};i<menurequest->nodes.size();i++){
            if(CheckCollisionPointCircle(GetMousePosition(),nodeCenters[menurequest->nodes[i]-1],40.f)){
            onSelection(i);
            menurequest->nodes.clear();
            break;
            }
        }
    }
}
void SetUpView::DrawHeroPlacement(){
    Vector2 mouse=GetMousePosition();
    
    
    DrawBoard();
    if(menurequest->nodes.empty())
        onSelection(-1);

    for(int node: menurequest->nodes)
        DrawCircleLines(nodeCenters[node-1].x,nodeCenters[node-1].y,40.f,YELLOW);
        // DrawCircleLines(nodeCenters[25].x,nodeCenters[25].y,40.f,YELLOW);
        // DrawCircleLines(nodeCenters[0].x,nodeCenters[0].y,40.f,YELLOW);

            
}
void SetUpView::DrawSidekickPlacement(){

    
    if(menurequest->nodes.empty())
        onSelection(-1);
    DrawBoard();
    for(int node: menurequest->nodes)
        DrawCircleLines(nodeCenters[node-1].x,nodeCenters[node-1].y,40.f,YELLOW);

    


}
void SetUpView::DrawBoard(){
        Vector2 mouse=GetMousePosition();
    // std::cout<<"Befor Draw Board"<<std::endl;
    GetNodeCenters();
    DrawTexturePro(boardtexture,
        Rectangle{
        0,
        0,
        (float)boardtexture.width,
        (float)boardtexture.height},
        mapRect,
        Vector2{0,0},
        0,
        WHITE);
        DrawFightersOnBoard();
    DrawText(TextFormat("X: %.0f Y: %.0f",mouse.x,mouse.y),20,20,24,RED);
    // std::cout<<"After Draw Board"<<std::endl;

    // DrawTextPro()
        // for(const auto & center : nodeCenters){
        //     if(CheckCollisionPointCircle(GetMousePosition(),center,40.f))
        //     DrawCircleLines(center.x,center.y,40.f,YELLOW);
            
        // }
}
void SetUpView::SetInputRequest(MenuRequest &req){
    this->menurequest=&req;
}


std::vector<Vector2> SetUpView::GetNodeCenters(){
    nodeCenters.push_back({1169,436});
    nodeCenters.push_back({1279,417});
    nodeCenters.push_back({1209,333});
    nodeCenters.push_back({1068,402});
    nodeCenters.push_back({1291,543});
    nodeCenters.push_back({1071,221});
    nodeCenters.push_back({952,358});
    nodeCenters.push_back({862,411});
    nodeCenters.push_back({898,527});
    nodeCenters.push_back({740,479});
    nodeCenters.push_back({589,532});
    nodeCenters.push_back({536,406});
    nodeCenters.push_back({637,380});
    nodeCenters.push_back({743,336});
    nodeCenters.push_back({639,615});
    nodeCenters.push_back({736,590});
    nodeCenters.push_back({834,612});
    nodeCenters.push_back({941,616});
    nodeCenters.push_back({1018,551});
    nodeCenters.push_back({1136,552});
    nodeCenters.push_back({1223,616});
    nodeCenters.push_back({613,266});
    nodeCenters.push_back({507,252});
    nodeCenters.push_back({520,150});
    nodeCenters.push_back({637,116});
    nodeCenters.push_back({705,225});
    nodeCenters.push_back({800,142});
    nodeCenters.push_back({910,228});
    nodeCenters.push_back({971,144});
    nodeCenters.push_back({1167,149});
    nodeCenters.push_back({1222,229});
    nodeCenters.push_back({1285,152});

    return nodeCenters;
}
void SetUpView::DrawFightersOnBoard(){
    Board board=gamestate.board;
    // std::cout<<"Size"<<board.GetGraph().size()<<std::endl;
    for(auto token:board.GetGraph()){
        // FighterType type=token->GetFighterType();
        // std::cout<<"Sixe Graph "<<std::to_string(board.GetGraph().size())<<std::endl;
        Vector2 center=nodeCenters[token.second-1];
        Texture2D texture;
        switch (token.first)
        {
        case FighterType::INVISIBLEMAN:
            texture=herotextures[1];
            break;
        case FighterType::DRACULA:
            texture=herotextures[0];
            break;
        case FighterType::DR_WATSON:
            texture=watsontoken;
            break;
        case FighterType::SHERLOCK:
            texture=herotextures[1];
            break;
        case FighterType::SISTER_1:
            texture=this->sisters[0];
            break;
        case FighterType::SISTER_2:
            texture=this->sisters[0];
            break;
        case FighterType::SISTER_3:
            texture=this->sisters[0];
            break;
        case FighterType::FOG:
            texture=this->fog;
            break;
        }
        float w=texture.width *0.32f;
        float h=texture.height *0.32f;
        DrawTextureEx(
            texture,
            {
                center.x -w /2,
                center.y - h /2
            },
            0,
            0.32f,
            WHITE
        );

    }
}


void SetUpView::ResetSet(){
    selectedHeroes={false,false};
    state=SetUpState::INPUT_AGE;
    player1Age="";
    editingPlayer1=true;
    player2Age="";
    editingPlayer2=true;
    firstPlayer=-1;
    HeroSelected=-1;
}
