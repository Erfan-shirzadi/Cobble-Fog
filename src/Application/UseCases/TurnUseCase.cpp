#include "Application/UseCases/TurnUseCase.h"

void TurnUseCase::execute(GameState & gamestate){
    Hero* Current=gamestate.currnetPlayer->GetHero();
    Current->SetRemainingAction(2);

    while (Current->GetRemainingAction()>0){

        
    }

    std::swap(gamestate.currnetPlayer,gamestate.opponentPlayre);
    
}
