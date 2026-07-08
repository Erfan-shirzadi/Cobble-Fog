#include "Application/UseCases/TurnUseCase.h"
#include "Application/UseCases/SchemeUseCase.h"
#include "Application/UseCases/ManeverUseCase.h"
#include <iostream>
void TurnUseCase::execute(GameState & gamestate){
    Hero* Current=gamestate.currnetPlayer->GetHero();
    Current->SetRemainingAction(2);
    int action;
    while (Current->GetRemainingAction()>0){
        std::cout<<" Turn " <<Current->GetName()<<std::endl;
        std::cout<< " Choose A Action : "<<std::endl;
        std::cout<<R"(0. scheme 
1. Manever )";
        std::cin>>action;
        switch(action)
        {
            case 0:{
                    SchemeUseCase a;
            if(a.execute(gamestate)){
               std::cout<< " Succesfull "<<std::endl;
               Current->reduceRemainingAction();
             }
             else std::cout<<" can not do scheme "<<std::endl;
             break;
            }
            case 1:{
                ManeverUseCase b;
                b.execute(gamestate);
               Current->reduceRemainingAction();

            }
            


        }
        
     }

    std::swap(gamestate.currnetPlayer,gamestate.opponentPlayre);
    
}
