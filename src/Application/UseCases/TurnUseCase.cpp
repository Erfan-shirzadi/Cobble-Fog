#include "Application/UseCases/TurnUseCase.h"
#include "Application/UseCases/SchemeUseCase.h"
#include "Application/UseCases/ManeverUseCase.h"
#include "Application/UseCases/AttackUseCase.h"
#include "Application/Ability/HeroAbilityFactory.h"
#include <iostream>



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
        return ManageHandSize(context);
        break;
    case TurnStep::ASK_FOR_CONTINUE_REMOVE_CARD:
        return AskRemoveMoreCard(context);
        break;
    }
    ContinueResult a;
    a.status=ContinueStatus::FINISHED;
        return a;
}

ContinueResult TurnUseCase::Start(EffectContext& context){

    ContinueResult result;
    Hero * hero=context.context.Gamestate->currnetPlayer->GetHero();
    Board board=context.context.Gamestate->board;
    hero->SetStartTurnOnfog(board.IsFogHere(hero->GetNode()));
    hero->SetRemainingAction(2);
    step=TurnStep::CHOOSE_ACTION;
    return result;
}

ContinueResult TurnUseCase::ExecuteAction(EffectContext& context){

    ContinueResult result=CurrentUseCase->Continue(context);
    
    if(result.status ==ContinueStatus::FINISHED){
        Hero * current=context.context.Gamestate->currnetPlayer->GetHero();
        current->reduceRemainingAction();

        if(current->GetRemainingAction()==0){
            step=TurnStep::FINISHED;
            result.status=ContinueStatus::CONTINUE;
        }
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
        context.context.Selected=-1;

        step=TurnStep::EXECUTE_USECASE;
        ContinueResult a;
        a.status=ContinueStatus::CONTINUE;
        return a;

    }

    ContinueResult result;
    result.status=ContinueStatus::NEEDMENU;
    
    result.menu_request=BuildActionMenu(context);
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
            context.context.Selected=-1;
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

void TurnUseCase::SetUseCase(int selected){
    switch (selected)
    {
    case 0:
        std::cout<<" Set action Manever"<<std::endl;
        this->CurrentUseCase= &manever;
        break;
    case 1:
         this->CurrentUseCase=& scheme;
        std::cout<<" Set action scheme"<<std::endl;

        break;
    case 2:
        this->CurrentUseCase=& attack;
        std::cout<<" Set action Attack"<<std::endl;

        break;
    }
}   

MenuRequest TurnUseCase::BuildActionMenu(EffectContext & context){
    MenuRequest temp;
    possibleAction.clear();

    temp.title="Action";
    temp.options.push_back("MANEVER");
    possibleAction.push_back(ActoinType::MANEVER);

    if(scheme.CanDoAction(context.context.Gamestate)){
        temp.options.push_back("SCHEME");
        possibleAction.push_back(ActoinType::SCHEME);
    }
    if(attack.CanAttack(context.context.Gamestate)){
    temp.options.push_back("ATTACK");
    possibleAction.push_back(ActoinType::ATTACK);
    }
    temp.type=InputType::ACTION;
    return temp;
}

ContinueResult TurnUseCase::ManageHandSize(EffectContext & context){
     ContinueResult result;
    Hero * hero=context.context.Gamestate->currnetPlayer->GetHero();

   
    if(context.context.Selected==-1) return BuildHandMenu(hero);

    hero->RemoveCardHand(context.context.Selected);

     if(hero->GetSizeHand()<=7){
        step=TurnStep::ASK_FOR_CONTINUE_REMOVE_CARD;
        context.context.Selected=-1;
        result.status=ContinueStatus::CONTINUE;
        return result;
    }

    result.status=ContinueStatus::CONTINUE;
    context.context.Selected=-1;
    return result;
}


ContinueResult TurnUseCase::AskRemoveMoreCard(EffectContext & context){
    ContinueResult result;
    if(context.context.Selected==-1){
        result.menu_request.options.push_back("Yes");
        result.menu_request.options.push_back("No");
        result.status=ContinueStatus::NEEDMENU;
        result.menu_request.type=InputType::QUESTION;
        return result;
    }

    if(context.context.Selected==0){
        step=TurnStep::MANAGE_HAND_SIZE;
        context.context.Selected=-1;
        result.status=ContinueStatus::CONTINUE;
        return result;
    }

    result.status=ContinueStatus::FINISHED;
    context.context.Selected=-1;

    return result;
    

}


ContinueResult TurnUseCase::BuildHandMenu(Hero * hero){
    ContinueResult result;
    result.menu_request.title="Remove card please :";
    for(auto card: hero->GetHand()){
        result.menu_request.cards.push_back(card->GetCardId());
    }
    if(hero->GetSizeHand()<=7){
        result.menu_request.options.push_back("End turn");
        // result.menu_request.options.push_back("Continue");
        // result.menu_request.type=InputType::QUESTION;
        // return result; // result.menu_request.options.push_back("Continue");
        // result.menu_request.type=InputType::QUESTION;
        // retur
    }
    result.status=ContinueStatus::NEEDMENU;
    result.menu_request.type=InputType::CARD;

    return result;
}


ContinueResult TurnUseCase::AskAbility(EffectContext & context){
    if(context.context.Selected==-1){
        ContinueResult res;
        res.status=ContinueStatus::NEEDMENU;
        res.menu_request.options.push_back("no");
        res.menu_request.options.push_back("yes");
        res.menu_request.title="Do you want to use Ability ?";
        return res;
    }
    if(context.context.Selected==0){
        ContinueResult res;
        res.status=ContinueStatus::FINISHED;
        return res;
    }

    ContinueResult res;
    res.status=ContinueStatus::CONTINUE;
    abilitystep=AbilityStep::EXECUTE_ABILITY;
    return res;
}


ContinueResult TurnUseCase::ExecuteAbility(EffectContext &context){
    ContinueResult res;
    res=ability->Continue(context);

    if(res.status==ContinueStatus::FINISHED){
        abilitystep=AbilityStep::FINISHED;
    }
    return res;

}

ContinueResult TurnUseCase::Ability(EffectContext & context){

    switch (abilitystep)
    {
    case AbilityStep::ASK_USE_ABILITY:
        return AskAbility(context);
        break;
    case AbilityStep::EXECUTE_ABILITY:
        return ExecuteAbility(context);
        break;
    case AbilityStep::FINISHED:
        break;
    }

    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}

void TurnUseCase::Reset(EffectContext& context){
    this->manever.Finished(context);
    this->scheme.Finished(context);
    this->attack.Finished(context);
}


ManeverUseCase & TurnUseCase::GetManeverUseCase(){
    return this->manever;
}
SchemeUseCase & TurnUseCase::GetSchemeUseCase(){
    return this->scheme;
}
AttackUseCase & TurnUseCase::GetAttackUseCase(){
    return this->attack;
}
ActoinType TurnUseCase::CurrentAction(){
    return this->currentaction;
}

TurnStep TurnUseCase::GetTurnUseCaseStep(){
    return this->step;
}
