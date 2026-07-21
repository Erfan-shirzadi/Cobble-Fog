#include "Application/UseCases/TurnUseCase.h"
#include "Application/UseCases/SchemeUseCase.h"
#include "Application/UseCases/ManeverUseCase.h"
#include "Application/UseCases/AttackUseCase.h"
#include "Application/Ability/HeroAbilityFactory.h"
#include <iostream>



ContinueResult TurnUseCase::Continue(EffectContext& context){

    switch (step)
    {
    // case TurnStep::START:
    //     return Start(context);
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

ContinueResult TurnUseCase::Start(EffectContext& context){

     ContinueResult result;
    // result.status=ContinueStatus::CONTINUE;
    // if(!ability){
    //     ability=HeroAbilityFactory::CeateAbility(context.context.Gamestate->currnetPlayer->GetHero()->GetFighterType());
    // }
    // if(ability->CanUseAbility())
    //     result=Ability(context);
    // if(result.status==ContinueStatus::FINISHED){
    //     step=TurnStep::CHOOSE_ACTION;
    //     context.context.Gamestate->currnetPlayer->GetHero()->SetRemainingAction(2);
    //     result.status=ContinueStatus::CONTINUE;
    // }
    context.context.Gamestate->currnetPlayer->GetHero()->SetRemainingAction(2);
    step=TurnStep::CHOOSE_ACTION;
    return result;
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
        this->currentaction=possibleAction[context.context.Selected];
        SetUseCase();
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

void TurnUseCase::SetUseCase(){
    switch (currentaction)
    {
    case ActoinType::SCHEME:
        this->CurrentUseCase= &scheme;
        break;
    case ActoinType::MANEVER:
         this->CurrentUseCase=& manever;
        break;
    case ActoinType::ATTACK:
        this->CurrentUseCase=& attack;
        break;
    }
}   

MenuRequest TurnUseCase::BuildActionMenu(EffectContext & context){
    MenuRequest temp;
    possibleAction.clear();

    temp.title="Action";
    temp.options.push_back("Manever");
    possibleAction.push_back(ActoinType::MANEVER);

    if(scheme.CanDoAction(context.context.Gamestate)){
        temp.options.push_back("Scheme");
        possibleAction.push_back(ActoinType::SCHEME);
    }
    if(attack.CanAttack(context.context.Gamestate)){
    temp.options.push_back("Attack");
    possibleAction.push_back(ActoinType::ATTACK);
    }
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
