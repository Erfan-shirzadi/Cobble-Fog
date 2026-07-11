#include "Application/UseCases/TurnUseCase.h"
#include "Application/UseCases/SchemeUseCase.h"
#include "Application/UseCases/ManeverUseCase.h"
#include "Application/UseCases/AttackUseCase.h"
#include <iostream>
void TurnUseCase::execute(GameState & gamestate){
    Hero* Current=gamestate.currnetPlayer->GetHero();
    Current->SetRemainingAction(2);
    int action;
    while (Current->GetRemainingAction()>0){
        std::cout<<" Turn " <<Current->GetName()<<std::endl;
        std::cout<< " Choose A Action : "<<std::endl;
        std::cout<<R"(0. scheme 
1. Manever
2. Attack )";
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
                break;
            }
            case 2:
            {
                AttackUseCase c;
                if(c.execute(gamestate)){
                    Current->reduceRemainingAction();
                    std::cout<<" succesfull "<<std::endl;
                }else {
                    std::cout<< "Can not do attack "<<std::endl;
                }
                break;
            }
            
            

        }
        std::cout<<  " After action "<<std::endl;
        gamestate.board.GetGraph();
        
     }

    //std::swap(gamestate.currnetPlayer,gamestate.opponentPlayre);
    
}
