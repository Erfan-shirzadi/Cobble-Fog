#include "Domain/Game/GameEngine.h"
#include "Application/UseCases/SetUpGameUseCase.h"
#include "Application/UseCases/TurnUseCase.h"
#include "Application/interaction/EffectContext.h"
#include <iostream>



void GameEngine::run(){
    gamestate.currnetPlayer=&player1;
    gamestate.player1=&player1;
    gamestate.opponentPlayre=&player2;
    gamestate.player2=&player2;
    gamestate.board=board;
    context.context.Gamestate=&gamestate;
    context.context.Selected=-1;

   

    
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
     this->turnusecase.Start(context);
    Process();
}
void GameEngine::Process(){

    while (true){
        if(GameOver()){
            this->state=GameEngineState::GAMEOVER;
            Hero* current=context.context.Gamestate->currnetPlayer->GetHero();
            Hero* opponent=context.context.Gamestate->currnetPlayer->GetHero();

            if(current->IsAlive())
                context.context.Gamestate->log.Add( current->GetName()+" WOn The Game");
            else {
                context.context.Gamestate->log.Add( opponent->GetName()+" WOn The Game");

            }
            //view.Refresh();

            return ;
        }
        //view.Refresh();
        ContinueResult result=turnusecase.Continue(context);
        if(GameOver()){
            this->state=GameEngineState::GAMEOVER;
            Hero* current=context.context.Gamestate->currnetPlayer->GetHero();
            Hero* opponent=context.context.Gamestate->currnetPlayer->GetHero();

            if(current->IsAlive())
                context.context.Gamestate->log.Add( current->GetName()+" WOn The Game");
            else {
                context.context.Gamestate->log.Add( opponent->GetName()+" WOn The Game");

            }
            //view.Refresh();
            return ;
        }
        if(result.status==ContinueStatus::NEEDMENU){
            //view.SetMenu(result.menu_request);
            //view.Refresh();
            return;
        }

        if(result.status==ContinueStatus::FINISHED){
            std::swap(this->gamestate.currnetPlayer,gamestate.opponentPlayre);
            turnusecase.Start(context);
            continue;
        }
    }
    

}
void GameEngine::OnSelection(int selection){
    context.context.Selected=selection;
    if(state==GameEngineState::GAME){
        Process();
    }
    else {SetUp();}
}

void GameEngine::SetUp(){

    while (true)
    {
        ContinueResult result= setup.Continue(context);
        if(result.status==ContinueStatus::NEEDMENU){
            //view.SetMenu(result.menu_request);
            return;
        }

        if(result.status==ContinueStatus::FINISHED){

             if(state==GameEngineState::SETUP_PLAYER2){
                std::swap(gamestate.currnetPlayer,gamestate.opponentPlayre);
                state=GameEngineState::GAME;
                Start();
                return;
            }

            if(state==GameEngineState::SETUP_PLAYER1){
                std::swap(gamestate.currnetPlayer,gamestate.opponentPlayre);
                state=GameEngineState::SETUP_PLAYER2;
                continue;
            }

           
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
