#include "Application/CardEffect/DraculaCardsEffect/LookIntoMyEyesEffect.h"
#include "Application/interaction/EffectContext.h"

ContinueResult LookIntoMyEyesEffect::Continue(EffectContext & context){
    Card * card=context.combatcontext->Opponent->card;
    
    context.combatcontext->Current->card->IncreseDamageOfDeffend(card->GetBoost());

    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}
