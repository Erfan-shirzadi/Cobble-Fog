#include "Application/CardEffect/DraculaCardsEffect/AmbushEffect.h"
#include "Application/interaction/EffectContext.h"

ContinueResult AmbushEffect::Continue(EffectContext & context){
    switch (step)
    {
    case AmbushEffectStep::DRAW_RANDOM_CARD:
        return DrawCardEnemy(context);
        break;
    case AmbushEffectStep::INCEASE_DAMAGE_FOR_THIS_CARD:
         return INceaseDamage(context);
        break;
    }
      ContinueResult res;
        res.status =ContinueStatus::FINISHED;
        return res;
}



ContinueResult AmbushEffect::DrawCardEnemy(EffectContext & context){

    int randomindex=rand()%context.combatcontext->Opponent->hero->GetSizeHand();

    Card * card=context.combatcontext->Opponent->hero->GetCard(randomindex);
    this->boostEnemycard=card->GetBoost();

    step=AmbushEffectStep::INCEASE_DAMAGE_FOR_THIS_CARD;
    ContinueResult res;
    res.status= ContinueStatus::CONTINUE;
    return res;
}
ContinueResult AmbushEffect::INceaseDamage(EffectContext & context){
    context.combatcontext->Current->card->IncreseDamageOfDeffend(this->boostEnemycard);
    this->step=FINISHED;
    ContinueResult res;
    res.status= ContinueStatus::CONTINUE;
    return res;
}

