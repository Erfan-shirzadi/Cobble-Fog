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
        // switch(action)
        // {
        //     case 0:{
        //             // SchemeUseCase a(gamestate);
        //     if(a.CanDoAction(gamestate)){
        //        std::cout<< " Succesfull "<<std::endl;
        //        Current->reduceRemainingAction();
        //      }
        //      else std::cout<<" can not do scheme "<<std::endl;
        //      break;
        //     }
        //     case 1:{
        //         // ManeverUseCase b;
        //         b.execute(gamestate);
        //        Current->reduceRemainingAction();
        //         break;
        //     }
        //     case 2:
        //     {
        //         // AttackUseCase c;
        //         if(c.execute(gamestate)){
        //             Current->reduceRemainingAction();
        //             std::cout<<" succesfull "<<std::endl;
        //         }else {
        //             std::cout<< "Can not do attack "<<std::endl;
        //         }
        //         break;
        //     }
            
            

        // }
        // gamestate.board.GetGraph();
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
    case TurnStep::CHOOSE_ACTION:
        return ChooseAction(context);
        break;
    case TurnStep::EXECUTE_USECASE:
        return ExecuteAction(context);
        break;
    case TurnStep::FINISHED:
        return FinishedResult(context);
        break;
    default :{
        ContinueResult a;
        return a;
    }
    }
}

void TurnUseCase::Start(ActionContext& context){
    context.Gamestate->currnetPlayer->GetHero()->SetRemainingAction(2);
    step=TurnStep::CHOOSE_ACTION;
}

ContinueResult TurnUseCase::ExecuteAction(ActionContext& context){

    ContinueResult result=CurrentUseCase->Continue(context);
    
    if(result.status ==ContinueStatus::FINISHED){
        Hero * current=context.Gamestate->currnetPlayer->GetHero();
        current->reduceRemainingAction();

        if(current->GetRemainingAction()==0)
            step=TurnStep::FINISHED;
        else{
            step=TurnStep::CHOOSE_ACTION;
            result.status=ContinueStatus::CONTINUE;
        }
    }
    return result;

}
ContinueResult TurnUseCase::ChooseAction(ActionContext &context){

    if(context.Selected!=-1){
            
        SetUseCase(context.Selected);
        CurrentUseCase->Start(context);
        step=TurnStep::EXECUTE_USECASE;
        ContinueResult a;
        a.status=ContinueStatus::CONTINUE;
        return a;

    }

    ContinueResult result;
    result.status=ContinueStatus::NEEDMENU;
    result.menu_request=BuildActionMenu();
    return result;
}
ContinueResult TurnUseCase::FinishedResult(ActionContext & context){
    this->CurrentUseCase=nullptr;
    Hero * CurrentHero=context.Gamestate->currnetPlayer->GetHero();
    ContinueResult result;
    if(CurrentHero->GetRemainingAction()==0){
        result.status=ContinueStatus::FINISHED;
    }
    else{
        step=TurnStep::CHOOSE_ACTION;
        result.status=ContinueStatus::CONTINUE;
    }
    return result;
}

void TurnUseCase::SetUseCase(int index){
    switch (index)
    {
    case 0:
        this->CurrentUseCase= &scheme;
        break;
    case 1:
         this->CurrentUseCase=& manever;
        break;
    case 2:
        this->CurrentUseCase=& attack;
        break;
    }
}   

MenuRequest TurnUseCase::BuildActionMenu(){
    MenuRequest temp;
    temp.title="Action";
    temp.options.push_back("Scheme");
    temp.options.push_back("Manever");
    temp.options.push_back("Attack");
    return temp;
}
