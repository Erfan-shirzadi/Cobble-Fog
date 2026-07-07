#include "Application/UseCases/TurnUseCase.h"
#include "Application/UseCases/SchemeUseCase.h"

void TurnUseCase::execute(GameState & gamestate){
    Hero* Current=gamestate.currnetPlayer->GetHero();
    Current->SetRemainingAction(2);

    // while (Current->GetRemainingAction()>0){
        
        SchemeUseCase a;
        a.execute(gamestate);
        
    // }

    std::swap(gamestate.currnetPlayer,gamestate.opponentPlayre);
    
}
