#include "Application/CardEffect/HolmesCardsEffect/EducationNeverEndsEffect.h"

ContinueResult EducationNeverEndsEffect::Continue(EffectContext & context){
    if(context.combatcontext->Current->Won){
        Hero * hero=context.combatcontext->Opponent->hero;
        hero->DrawCard();
    }
    else{
        Hero * Holmes =context.combatcontext->Current->hero;
        Holmes->DrawCard();
        Holmes->DrawCard();

    }

    ContinueResult res;
     res.status=ContinueStatus::FINISHED;
     return res;
    
}
