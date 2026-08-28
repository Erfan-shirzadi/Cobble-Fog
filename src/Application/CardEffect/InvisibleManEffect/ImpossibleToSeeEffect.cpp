#include "Application/CardEffect/InvisibleCardsEffect/ImpossibleToSeeEffect.h"

ContinueResult ImpossibleToSeeEffect::Continue(EffectContext & context ){
    context.combatcontext->Opponent->CanChangeAmountCard=false;
    context.combatcontext->Opponent->card->SetDamageOrDeffend(0);
    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}
