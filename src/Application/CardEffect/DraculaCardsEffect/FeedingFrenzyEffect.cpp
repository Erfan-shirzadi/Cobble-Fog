#include "Application/CardEffect/DraculaCardsEffect/FeedingFrenzyEffect.h"
#include "Application/interaction/EffectContext.h"

ContinueResult FeedingFrenzyEffect::Continue(EffectContext & context){

    switch (this->step)
    {
    case FeedinFrenzyEffectStep::INCREASE_DAMAGE:
        return IncreseDamage(context);
        break;
    case FeedinFrenzyEffectStep::FINISHED:
        {
            ContinueResult result;
            result.status=ContinueStatus::FINISHED;
            return result;
        }
        break;
    default:{
        ContinueResult res;
        res.status=ContinueStatus::FINISHED;
        return res;
    }
    }
}


ContinueResult FeedingFrenzyEffect::IncreseDamage(EffectContext & context){
    Hero * hero =context.combatcontext->Current->hero;
    Fighter * enemy=context.combatcontext->Opponent->fighter;
    std::vector<Fighter*> sisters=hero->GetSideKicks();
    int increaseDamage=0;
    for(Fighter * sidekick: sisters){
        if(context.combatcontext->board->IsAnArea(sidekick->GetNode(),enemy->GetNode()))
            increaseDamage++;
    }

    context.combatcontext->Current->DamageOrDeffend+=increaseDamage;

    context.combatcontext->Current->card->IncreseDamageOfDeffend(increaseDamage);
    ContinueResult res;
    res.status=ContinueStatus::CONTINUE;

    this->step=FeedinFrenzyEffectStep::FINISHED;
    return res;
}
