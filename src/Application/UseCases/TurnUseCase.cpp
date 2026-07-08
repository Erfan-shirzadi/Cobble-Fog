#include "Application/UseCases/TurnUseCase.h"
#include "Application/UseCases/SchemeUseCase.h"
#include <iostream>
void TurnUseCase::execute(GameState & gamestate){
    Hero* Current=gamestate.currnetPlayer->GetHero();
    Current->SetRemainingAction(2);

    // while (Current->GetRemainingAction()>0){
        
        SchemeUseCase a;

        if(a.execute(gamestate)){
            std::cout<< " Succesfull "<<std::endl;
        }
        else std::cout<<" can not do scheme "<<std::endl;
        
    // }

    std::swap(gamestate.currnetPlayer,gamestate.opponentPlayre);
    
}
