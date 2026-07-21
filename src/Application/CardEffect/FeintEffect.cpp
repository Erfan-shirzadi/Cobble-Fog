#include "Application/CardEffect/FeintEffect.h"
#include "Application/interaction/EffectContext.h"


ContinueResult FeintEffect::Continue(EffectContext & context){
    ContinueResult result;
    context.context.Gamestate->log.Add("Card Effect "+context.combatcontext->Opponent->fighter->GetName()+" Canceled");
    context.combatcontext->Opponent->IsActiveCardEffect=false;
    result.status=ContinueStatus::FINISHED;

    return result;
}
