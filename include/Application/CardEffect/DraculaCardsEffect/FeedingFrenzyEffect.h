#ifndef FEEDING_FRENZY_EFFECT
#define FEEDING_FRENZY_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"

enum class FeedinFrenzyEffectStep{
    INCREASE_DAMAGE,
    FINISHED,
};

class FeedingFrenzyEffect :public CardEffect{

    FeedinFrenzyEffectStep step=FeedinFrenzyEffectStep::INCREASE_DAMAGE;
    public :
    ContinueResult Continue(EffectContext&)override;
    ContinueResult IncreseDamage(EffectContext&);
};

#endif /* FEEDING_FRENZY_EFFECT */
