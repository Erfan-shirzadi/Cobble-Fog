#include "Domain/Game/GameEngine.h"
#include "Application/UseCases/SetUpGameUseCase.h"
#include "Application/UseCases/TurnUseCase.h"
#include "Application/interaction/EffectContext.h"
#include <iostream>
void GameEngine::run(){
    SetUpGameUseCase setup;
    gamestate.currnetPlayer=&player1;
    gamestate.opponentPlayre=&player2;
    gamestate.board=board;
    context.context.Gamestate=&gamestate;
    context.context.Selected=-1;

     setup.execute(gamestate);
    view.SetOnSelection([this](int selected){
        this->OnSelection(selected);
    });

    Start();
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
        ContinueResult result=turnusecase.Continue(context);
        if(result.status==ContinueStatus::NEEDMENU){
            view.SetMenu(result.menu_request);
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
    Process();
}
