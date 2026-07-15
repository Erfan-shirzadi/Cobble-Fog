#include "Application/UseCases/TurnUseCase.h"
#include "Application/UseCases/SchemeUseCase.h"
#include "Application/UseCases/ManeverUseCase.h"
#include "Application/UseCases/AttackUseCase.h"
#include <iostream>
void TurnUseCase::execute(GameState & gamestate){
    Hero* Current=gamestate.currnetPlayer->GetHero();
    Current->SetRemainingAction(2);
    int action;

    if(Current->CanUseCability(gamestate)){
        std::string temp;
        std::cout<<"Do you want use Ability? (Y/N)";
        std::cin>>temp;
        if(temp=="Y")
            Current->Ability(gamestate);
    }


    while (Current->GetRemainingAction()>0 && (!GameOver(gamestate))){
        std::cout<<" Turn " <<Current->GetName()<<std::endl;
        std::cout<< Current->GetHandCards()<<std::endl;
        std::cout<< " Choose A Action : "<<std::endl;
        std::cout<<R"(0. scheme 
1. Manever
2. Attack )";
        std::cin>>action;
        switch(action)
        {
            case 0:{
                    SchemeUseCase a(gamestate);
            if(a.CanDoAction(gamestate)){
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

ContinueResult TurnUseCase::Continue(ActionContext& context){

    switch (step)
    {
    case 0:
        return ChooseAction(context);
        break;
    case 1:
        return ExecuteAction(context);
        break;
    case 2:
        return FinishedResult();
        break;
    }
}

void TurnUseCase::Start(ActionContext& context){
    context.Gamestate->currnetPlayer->GetHero()->SetRemainingAction(2);
    step=0;
}

ContinueResult TurnUseCase::ExecuteAction(ActionContext& context){

    ContinueResult result;
    
    if(result.status ==ContinueStatus::FINISHED){
        Hero * current=context.Gamestate->currnetPlayer->GetHero();
        current->reduceRemainingAction();

        if(current->GetRemainingAction()==0)
            step=2;
        else
            step=0;
    }

}
ContinueResult TurnUseCase::ChooseAction(ActionContext &context){

}
ContinueResult TurnUseCase::FinishedResult(){

}
