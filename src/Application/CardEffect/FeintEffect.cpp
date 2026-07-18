#include "Application/CardEffect/FeintEffect.h"

ContinueResult FeintEffect::Continue(EffectContext & context){
    ContinueResult result;
    context.combatcontext->Opponent->IsActiveCardEffect=false;
    result.status=ContinueStatus::FINISHED;

    return result;
}
