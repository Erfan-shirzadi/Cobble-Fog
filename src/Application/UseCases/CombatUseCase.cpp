#include "Application/UseCases/CombatUseCase.h"
#include <iostream>
#include "Application/CardEffect/CardEffectFactory.h"

using namespace std;

ContinueResult CombatUseCase::Continue(EffectContext & context){
    switch (combatstep)
    {
    case CombatStep::START:{
        return start(context);
        break;
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
    this->combatstep=CombatStep::START;
    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}


ContinueResult CombatUseCase::start(EffectContext &context){
   context.context.Gamestate->log.Add("Start Combat ");
   CombatCard * deffendercard=context.combatcontext->Opponent->card;
   CombatCard * attackercard=context.combatcontext->Current->card;
    if(attackercard)
    context.context.Gamestate->log.Add("Attacker : "+attackercard->GetName()+ "  Damage : "+
    std::to_string(attackercard->GetDamgeOrDeffend()));
    if(deffendercard)
    context.context.Gamestate->log.Add("Deffender : "+deffendercard->GetName()+"  Deffense : "+
    std::to_string(deffendercard->GetDamgeOrDeffend()));
    else context.context.Gamestate->log.Add("Deffender :  None");



    if(deffendercard)
    context.combatcontext->Opponent->effect=
        CardEffectFactory::CreatCardEffect(context.combatcontext->Opponent->card->GetCardId());
    if(attackercard)
        context.combatcontext->Current->effect=
    CardEffectFactory::CreatCardEffect(context.combatcontext->Current->card->GetCardId());
    std::swap(context.combatcontext->Current,context.combatcontext->Opponent);





    combatstep=CombatStep::BEFOR_COMBAT;
    this->cardStep=CardPlayStep::DEFFENDER_CARD;
    ContinueResult res;
    res.status=ContinueStatus::CONTINUE;
    return res;
}




ContinueResult CombatUseCase::BeforCombatEffectDeffender(EffectContext&context){
     ContinueResult res;
    context.context.Gamestate->log.Add("Befor Combat ");
        res.status=ContinueStatus::FINISHED;
        if(context.combatcontext->Current->card!=nullptr)
            if(context.combatcontext->Current->IsActiveCardEffect ||
            context.combatcontext->Current->hero->GetFighterType()==FighterType::SHERLOCK){
                if(context.combatcontext->Current->card->GetCardPlayTiming()==PlayTiming::IMMEDIATE)
                    res = context.combatcontext->Current->effect->Continue(context);
            } 
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
        if(context.combatcontext->Current->card)
        if(context.combatcontext->Current->IsActiveCardEffect ||
            context.combatcontext->Current->hero->GetFighterType()==FighterType::SHERLOCK){
            if(context.combatcontext->Current->card->GetCardPlayTiming()==PlayTiming::IMMEDIATE)
                res= context.combatcontext->Current->effect->Continue(context);  
        }
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
        context.context.Gamestate->log.Add("During Combat ");

        res.status=ContinueStatus::FINISHED;
        if(context.combatcontext->Current->card)    
            if(context.combatcontext->Current->IsActiveCardEffect ||
            context.combatcontext->Current->hero->GetFighterType()==FighterType::SHERLOCK){
                if(context.combatcontext->Current->card->GetCardPlayTiming()==PlayTiming::DURING_COMBAT)
                    res= context.combatcontext->Current->effect->Continue(context); 
            }    
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
        if(context.combatcontext->Current->card)
        if(context.combatcontext->Current->IsActiveCardEffect ||
            context.combatcontext->Current->hero->GetFighterType()==FighterType::SHERLOCK){
            if(context.combatcontext->Current->card->GetCardPlayTiming()==PlayTiming::DURING_COMBAT)
                res= context.combatcontext->Current->effect->Continue(context);
        }        
        if(res.status==ContinueStatus::FINISHED){
            std::swap(context.combatcontext->Current,context.combatcontext->Opponent);
            res.status=ContinueStatus::CONTINUE;
            combatstep=CombatStep::AFTER_COMBAT;
            this->cardStep=CardPlayStep::DEFFENDER_CARD;
        }


        int ResultDamage=context.combatcontext->Opponent->card->GetDamgeOrDeffend();
        if(context.combatcontext->Current->card)
           ResultDamage-= context.combatcontext->Opponent->card->GetDamgeOrDeffend();

            if(ResultDamage<0) context.combatcontext->Current->Won=true;
            else {
                context.context.Gamestate->log.Add(context.combatcontext->Current->fighter->GetName()+" Toke "+
                std::to_string(ResultDamage)+" Damage");
                context.combatcontext->Current->fighter->TakeDamge(ResultDamage);
                context.combatcontext->Opponent->Won=true;
            }
            if(context.combatcontext->Opponent->Won)
                context.context.Gamestate->log.Add(context.combatcontext->Opponent->fighter->GetName()+" won the Combat ");
            else context.context.Gamestate->log.Add(context.combatcontext->Current->fighter->GetName()+" won the Combat ");


         return res;  

}
ContinueResult CombatUseCase::AfterCombatEffectDeffender(EffectContext &context){
        ContinueResult res;
        res.status=ContinueStatus::FINISHED;
        context.context.Gamestate->log.Add("After Combat ");

        if(context.combatcontext->Current->card)
            if(context.combatcontext->Current->IsActiveCardEffect ||
                context.combatcontext->Current->hero->GetFighterType()==FighterType::SHERLOCK){
                if(context.combatcontext->Current->card->GetCardPlayTiming()==PlayTiming::ATFER_COMBAT)
                    res= context.combatcontext->Current->effect->Continue(context);   
            }     
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

        if(context.combatcontext->Current->card)
        if(context.combatcontext->Current->IsActiveCardEffect ||
            context.combatcontext->Current->hero->GetFighterType()==FighterType::SHERLOCK){
            if(context.combatcontext->Current->card->GetCardPlayTiming()==PlayTiming::ATFER_COMBAT)
                res= context.combatcontext->Current->effect->Continue(context); 
        }       
        if(res.status==ContinueStatus::FINISHED){
            res.status=ContinueStatus::CONTINUE;
            combatstep=CombatStep::FINISHED;
                this->cardStep=CardPlayStep::DEFFENDER_CARD;

        }
         return res;  

}
