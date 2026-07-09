#include "Domain/Game/GameEngine.h"
#include "Application/UseCases/SetUpGameUseCase.h"
#include "Application/UseCases/TurnUseCase.h"
#include <iostream>
void GameEngine::run(){
    SetUpGameUseCase setup;
    gamestate.currnetPlayer=&player1;
    gamestate.opponentPlayre=&player2;
    gamestate.board=board;

    TurnUseCase turnusecase;
    setup.execute(gamestate);
    
    gamestate.board.GetGraph();
    
    while (true)
    {   
        turnusecase.execute(gamestate);
        std::swap(gamestate.currnetPlayer,gamestate.opponentPlayre);
    }
    

}