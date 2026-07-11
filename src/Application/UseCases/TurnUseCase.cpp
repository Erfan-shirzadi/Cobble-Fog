#include "Application/UseCases/TurnUseCase.h"
#include "Application/UseCases/SchemeUseCase.h"
#include "Application/UseCases/ManeverUseCase.h"
#include "Application/UseCases/AttackUseCase.h"
#include <iostream>
void TurnUseCase::execute(GameState & gamestate){
    Hero* Current=gamestate.currnetPlayer->GetHero();
    Current->SetRemainingAction(2);
    int action;
<<<<<<< HEAD

    if(Current->CanUseCability(gamestate)){
        std::string temp;
        std::cout<<"Do you want use Ability? (Y/N)";
        std::cin>>temp;
        if(temp=="Y")
            Current->Ability(gamestate);
    }

    while (Current->GetRemainingAction()>0){
=======
    while (Current->GetRemainingAction()>0 && (!GameOver(gamestate))){
>>>>>>> bugfix/cards
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
        gamestate.board.GetGraph();
     }
     ManageHandSize(Current);
<<<<<<< HEAD
=======
    
}


void TurnUseCase::ManageHandSize(Hero * hero){

    int choice;
    while (hero->GetSizeHand()>7)
    {
        std::cout<< " You most Discard Card From your Hand "<<std::endl;
        std::cout<< hero->GetHandCards()<<std::endl;
        std::cout<< " Enter A number :";
        std::cin>> choice;

        if(choice<0 || choice> hero->GetSizeHand())
            std::cout<< "Enter Correct please "<<std::endl;
        else{
            hero->RemoveCardHand(choice);
        }

    }
>>>>>>> ba986fe (fix : manager Hand Size)
    
}


void TurnUseCase::ManageHandSize(Hero * hero){

    int choice;
    while (hero->GetSizeHand()>7)
    {
        std::cout<< " You most Discard Card From your Hand "<<std::endl;
        std::cout<< hero->GetHandCards()<<std::endl;
        std::cout<< " Enter A number :";
        std::cin>> choice;

        if(choice<0 || choice> hero->GetSizeHand())
            std::cout<< "Enter Correct please "<<std::endl;
        else{
            hero->RemoveCardHand(choice);
        }

    }
    
}

bool TurnUseCase::GameOver(GameState &GameState ){
    Hero* current=GameState.currnetPlayer->GetHero();
    Hero* opponent=GameState.opponentPlayre->GetHero();

    if(!current->IsAlive() || !opponent->IsAlive())
        return true;
    return false;

}
