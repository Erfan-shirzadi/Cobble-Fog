#include "Application/UseCases/CombatUseCase.h"
#include <iostream>
#include "Application/CardEffect/CardEffectFactory.h"

using namespace std;

ContinueResult CombatUseCase::Continue(EffectContext & context){
    switch (combatstep)
    {
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
        CombatCard* card=context.combatcontext->Opponent->card;
        
    }
    case CardPlayStep::ATTACKER_CARD:{

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

    }
    case CardPlayStep::ATTACKER_CARD:{

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

    }
    case CardPlayStep::ATTACKER_CARD:{

    }
    }
    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;

}
ContinueResult CombatUseCase::Finished(EffectContext & context){
    
}
