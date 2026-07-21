#include "Application/CardEffect/HolmesCardsEffect/StudyMethod.h"
#include "Application/interaction/EffectContext.h"

ContinueResult StudyMethod::Continue(EffectContext & context){
    if(context.combatcontext->Current->Won){
        context.context.Gamestate->log.Add("Enemy Hand:");

        for(auto card: context.combatcontext->Opponent->hero->GetHand()){
            context.context.Gamestate->log.Add(card->GetName());
        }
    }

    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}
