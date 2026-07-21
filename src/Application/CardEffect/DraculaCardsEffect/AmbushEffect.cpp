#include "Application/CardEffect/DraculaCardsEffect/AmbushEffect.h"
#include "Application/interaction/EffectContext.h"


ContinueResult AmbushEffect::Continue(EffectContext & context){
    
   int randomindex=std::rand()%context.combatcontext->Opponent->hero->GetSizeHand();
    Card * card=context.combatcontext->Opponent->hero->GetCard(randomindex);
    context.context.Gamestate->log.Add("Remove Card "+card->GetName()+ " Boost: "+std::to_string(card->GetBoost()));
    this->boostEnemycard=card->GetBoost();
    context.combatcontext->Current->card->IncreseDamageOfDeffend(this->boostEnemycard);

    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}
