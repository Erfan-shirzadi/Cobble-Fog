#include "Application/UseCases/CombatUseCase.h"
#include <iostream>
#include "Application/CardEffect/CardEffectFactory.h"

using namespace std;

ContinueResult CombatUseCase::Continue(EffectContext & context){
    switch (combatstep)
    {
    case CombatStep::START:{
        return start(context);
    }
    case CombatStep::BEFOR_COMBAT:
        return BeforCombat(context);
        break;
    case CombatStep::DURING_COMBAT:
        return DuringCombat(context);
        break;
    case CombatStep::AFTER_COMBAT:
        return AfterCombat(context);
        break;
    case CombatStep::FINISHED:
        return Finished(context);
        break;
    }

    ContinueResult result;
    result.status=ContinueStatus::FINISHED;

    return result;
}

ContinueResult CombatUseCase::BeforCombat(EffectContext & context){

    switch (cardStep)
    {
    case CardPlayStep::DEFFENDER_CARD:{
          return BeforCombatEffectDeffender(context);
    }
    case CardPlayStep::ATTACKER_CARD:{
        return BeforCombatEffectAttcker(context);
    }
    }
    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}
ContinueResult CombatUseCase::DuringCombat(EffectContext & context){

    switch (cardStep)
    {
    case CardPlayStep::DEFFENDER_CARD:{
        return DuringCombatEffectDeffender(context);
    }
    case CardPlayStep::ATTACKER_CARD:{
        return DuringCombatEffectAttacker(context);
    }
    }
    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;

}
ContinueResult CombatUseCase::AfterCombat(EffectContext  & context){

    switch (cardStep)
    {
    case CardPlayStep::DEFFENDER_CARD:{
        return AfterCombatEffectDeffender(context);
    }
    case CardPlayStep::ATTACKER_CARD:{
        return AfterCombatEffectAttacker(context);
    }
    }
    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;

}
ContinueResult CombatUseCase::Finished(EffectContext & context){
     ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}


ContinueResult CombatUseCase::start(EffectContext &context){
    context.combatcontext->Opponent->effect=
        CardEffectFactory::CreatCardEffect(context.combatcontext->Opponent->card->GetCardId());
        context.combatcontext->Current->effect=
    CardEffectFactory::CreatCardEffect(context.combatcontext->Current->card->GetCardId());
    std::swap(context.combatcontext->Current,context.combatcontext->Opponent);

    combatstep=CombatStep::BEFOR_COMBAT;
    this->cardStep=CardPlayStep::DEFFENDER_CARD;
    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}




ContinueResult CombatUseCase::BeforCombatEffectDeffender(EffectContext&context){
     ContinueResult res;
        res.status=ContinueStatus::FINISHED;
        if(context.combatcontext->Current->card->GetCardPlayTiming()==PlayTiming::IMMEDIATE)
          res = context.combatcontext->Current->effect->Continue(context); 
        if(res.status==ContinueStatus::FINISHED){
            std::swap(context.combatcontext->Current,context.combatcontext->Opponent);
            res.status=ContinueStatus::CONTINUE;
            this->cardStep=CardPlayStep::ATTACKER_CARD;

        }
        return res; 
}
ContinueResult CombatUseCase::BeforCombatEffectAttcker(EffectContext &context){

            ContinueResult res;
        res.status=ContinueStatus::FINISHED;
        if(context.combatcontext->Current->card->GetCardPlayTiming()==PlayTiming::IMMEDIATE)
            res= context.combatcontext->Current->effect->Continue(context);  
        if(res.status==ContinueStatus::FINISHED){
            std::swap(context.combatcontext->Current,context.combatcontext->Opponent);
            res.status=ContinueStatus::CONTINUE;
            combatstep=CombatStep::DURING_COMBAT;
            this->cardStep=CardPlayStep::DEFFENDER_CARD;


        }
         return res;      

}
ContinueResult CombatUseCase::DuringCombatEffectDeffender(EffectContext &context){
        ContinueResult res;
        res.status=ContinueStatus::FINISHED;

        if(context.combatcontext->Current->card->GetCardPlayTiming()==PlayTiming::DURING_COMBAT)
            res= context.combatcontext->Current->effect->Continue(context);     
        if(res.status==ContinueStatus::FINISHED){
            std::swap(context.combatcontext->Current,context.combatcontext->Opponent);
            res.status=ContinueStatus::CONTINUE;
            this->cardStep=CardPlayStep::ATTACKER_CARD;


        }
         return res;      

}
ContinueResult CombatUseCase::DuringCombatEffectAttacker(EffectContext &context){

        ContinueResult res;
        res.status=ContinueStatus::FINISHED;

        if(context.combatcontext->Current->card->GetCardPlayTiming()==PlayTiming::DURING_COMBAT)
            res= context.combatcontext->Current->effect->Continue(context);        
        if(res.status==ContinueStatus::FINISHED){
            std::swap(context.combatcontext->Current,context.combatcontext->Opponent);
            res.status=ContinueStatus::CONTINUE;
            combatstep=CombatStep::AFTER_COMBAT;
            this->cardStep=CardPlayStep::DEFFENDER_CARD;



        }
         return res;  

}
ContinueResult CombatUseCase::AfterCombatEffectDeffender(EffectContext &context){
        ContinueResult res;
        res.status=ContinueStatus::FINISHED;

        if(context.combatcontext->Current->card->GetCardPlayTiming()==PlayTiming::ATFER_COMBAT)
            res= context.combatcontext->Current->effect->Continue(context);        
        if(res.status==ContinueStatus::FINISHED){
            std::swap(context.combatcontext->Current,context.combatcontext->Opponent);
            res.status=ContinueStatus::CONTINUE;
                this->cardStep=CardPlayStep::ATTACKER_CARD;

        }
         return res;  

}
ContinueResult CombatUseCase::AfterCombatEffectAttacker(EffectContext &context){
        ContinueResult res;
        res.status=ContinueStatus::FINISHED;

        if(context.combatcontext->Current->card->GetCardPlayTiming()==PlayTiming::ATFER_COMBAT)
            res= context.combatcontext->Current->effect->Continue(context);        
        if(res.status==ContinueStatus::FINISHED){
            res.status=ContinueStatus::CONTINUE;
            combatstep=CombatStep::FINISHED;
                this->cardStep=CardPlayStep::DEFFENDER_CARD;

        }
         return res;  

}
