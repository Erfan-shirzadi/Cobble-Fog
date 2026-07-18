#ifndef AMBUSH_EFFECT
#define AMBUSH_EFFECT
#include "Application/CardEffect/CardEffect.h"

enum AmbushEffectStep{
    DRAW_RANDOM_CARD,
    INCEASE_DAMAGE_FOR_THIS_CARD,
    FINISHED,
};

class AmbushEffect :public CardEffect{
    AmbushEffectStep step=DRAW_RANDOM_CARD;
    int boostEnemycard;

    public:
    ContinueResult Continue(EffectContext&)override;
    ContinueResult DrawCardEnemy(EffectContext &);
    ContinueResult INceaseDamage(EffectContext &);
};

#endif /* AMBUSH_EFFECT */
