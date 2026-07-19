#include "Application/UseCases/TurnUseCase.h"
#include "Application/UseCases/SchemeUseCase.h"
#include "Application/UseCases/ManeverUseCase.h"
#include "Application/UseCases/AttackUseCase.h"
#include <iostream>


bool TurnUseCase::GameOver(GameState &GameState ){
    Hero* current=GameState.currnetPlayer->GetHero();
    Hero* opponent=GameState.opponentPlayre->GetHero();

    if(!current->IsAlive() || !opponent->IsAlive())
        return true;
    return false;

}

ContinueResult TurnUseCase::Continue(EffectContext& context){

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
    case TurnStep::MANAGE_HAND_SIZE:

        break;
    }
    ContinueResult a;
    a.status=ContinueStatus::FINISHED;
        return a;
}

void TurnUseCase::Start(EffectContext& context){
    context.context.Gamestate->currnetPlayer->GetHero()->SetRemainingAction(2);
    step=TurnStep::CHOOSE_ACTION;
}

ContinueResult TurnUseCase::ExecuteAction(EffectContext& context){

    ContinueResult result=CurrentUseCase->Continue(context);
    
    if(result.status ==ContinueStatus::FINISHED){
        Hero * current=context.context.Gamestate->currnetPlayer->GetHero();
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
ContinueResult TurnUseCase::ChooseAction(EffectContext &context){

    if(context.context.Selected!=-1){
            
        SetUseCase(context.context.Selected);
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
ContinueResult TurnUseCase::FinishedResult(EffectContext & context){
    this->CurrentUseCase=nullptr;
    Hero * CurrentHero=context.context.Gamestate->currnetPlayer->GetHero();
    ContinueResult result;
    if(CurrentHero->GetRemainingAction()==0){

        if(CurrentHero->GetSizeHand()>7){
            result.status=ContinueStatus::CONTINUE;
            step=TurnStep::MANAGE_HAND_SIZE;
        }
        else {
            result.status=ContinueStatus::FINISHED;
            step=TurnStep::CHOOSE_ACTION;
        }
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

ContinueResult TurnUseCase::ManageHandSize(EffectContext & context){
    Hero * hero=context.context.Gamestate->currnetPlayer->GetHero();
    if(context.context.Selected==-1) return BuildHandMenu(hero);

    hero->RemoveCardHand(context.context.Selected);

    ContinueResult result;
    result.status=ContinueStatus::CONTINUE;
    return result;
}

ContinueResult TurnUseCase::BuildHandMenu(Hero * hero){
    ContinueResult result;

    for(auto card: hero->GetHand()){
        result.menu_request.options.push_back(card->GetName());
    }
    result.status=ContinueStatus::NEEDMENU;

    return result;
}
