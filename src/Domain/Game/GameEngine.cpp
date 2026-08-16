#include "Domain/Game/GameEngine.h"
#include "Application/UseCases/SetUpGameUseCase.h"
#include "Application/UseCases/TurnUseCase.h"
#include "Application/interaction/EffectContext.h"
#include "Domain/Game/DataContext.h"
#include <iostream>

GameEngine::GameEngine():view(gamestate){
}


void GameEngine::run(){
    // gamestate.currnetPlayer=player1;
    // gamestate.player1=player1;
    // gamestate.opponentPlayre=&player2;
    // gamestate.player2=player2;
    gamestate.board=board;
    context.context.Gamestate=&gamestate;
    context.context.Selected=-1;

   
    view.SetOnSelection([&](int value){this->OnSelection(value);});
    view.Run();    

}


void GameEngine::GameResult(GameState & gamestate){
    Hero* current=gamestate.currnetPlayer->GetHero();
    Hero* opponent=gamestate.opponentPlayre->GetHero();

    if(current->IsAlive()){
        std::cout<< current->GetName()<< " Won The Game "<<std::endl;
    }
    else {
        std::cout<< opponent->GetName()<< "Won The Game"<<std::endl;
    }
}

void GameEngine::Start(){
     this->TURNUSECASE->Start(context);
    Process();
}

void GameEngine::InitialObjects(){
    this->TURNUSECASE=new TurnUseCase;
    state=GameEngineState::HERO_SELECTION;
    player1=new Player;
    player2= new Player;
    gamestate.player1=player1;
    gamestate.player2=player2;
}


void GameEngine::Process(){

    while (true){

        ContinueResult result=TURNUSECASE->Continue(context);

        if(GameOver()){
            state=GameEngineState::GAMEOVER;
            Hero* current=gamestate.currnetPlayer->GetHero();
            if(current->IsAlive()){
                if(current->GetFighterType()==FighterType::SHERLOCK){
                    gamestate.gameresult=GameResult::SHERLOCK_WON;
                }
                else gamestate.gameresult=GameResult::DRACULA_WON;
            }
            else{
                if(current->GetFighterType()==FighterType::SHERLOCK){
                    gamestate.gameresult=GameResult::DRACULA_WON;
                }
                else gamestate.gameresult=GameResult::SHERLOCK_WON;
            }
            view.SetState(ViewState::GAMEOVER);
            DeleteObjects();
            return;
        }
       
        if(result.status==ContinueStatus::NEEDMENU){
            view.SetInputRequest(result.menu_request);
            return;
        }

        if(result.status==ContinueStatus::FINISHED){
            std::swap(this->gamestate.currnetPlayer,gamestate.opponentPlayre);
            TURNUSECASE->Start(context);
            continue;
        }
    }
    

}
void GameEngine::OnSelection(int selection){

    context.context.Selected=selection;

    if(selection==-2){
        DeleteObjects();
        return;
    }
    switch (state)
    {
    case GameEngineState::START_GAME:
        InitialObjects();
        break;
    case GameEngineState::HERO_SELECTION:
        gamestate.currnetPlayer->SetHero(selection);
        std::swap(gamestate.currnetPlayer,gamestate.opponentPlayre);
        if(gamestate.player1->GetHero()&&gamestate.player2->GetHero()){
            state=GameEngineState::SETUP;
            std::cout<<" Both player Seteed Heroes";
        }
        break;
    case GameEngineState::GAME:
        Process();
        break;
    
    case GameEngineState::SETUP:
        SetUp();
        break;
    case GameEngineState::GAMEOVER:
        state=GameEngineState::START_GAME;
        break;
    }
}

void GameEngine::SetUp(){

    while (true)
    {
        ContinueResult result= setup.Continue(context);
        if(result.status==ContinueStatus::NEEDMENU){
            view.SetInputRequest(result.menu_request);
            return;
        }

        if(result.status==ContinueStatus::FINISHED){
            state=GameEngineState::GAME;
            view.SetState(ViewState::GAME);
            
            TURNUSECASE->Start(context);
               
            return;
        }

    }
    
}


bool GameEngine::GameOver( ){
    Hero* current=gamestate.currnetPlayer->GetHero();
    Hero* opponent=gamestate.opponentPlayre->GetHero();

    if(!current->IsAlive() || !opponent->IsAlive())
        return true;
    return false;

}

void GameEngine::DeleteObjects(){
    state=GameEngineState::START_GAME;
    std::cout<<"OBjects deleted"<<std::endl;
    delete TURNUSECASE;
    gamestate.board.ResetBoard();
    delete player1;
    delete player2;
    gamestate.combatsatat=nullptr;
    

}

void GameEngine::SaveGame()const{

    DataContext data;
    data.gamestate=this->gamestate;
    data.gameviewstate=view.GetState();
    data.context=this->context;
    
}
