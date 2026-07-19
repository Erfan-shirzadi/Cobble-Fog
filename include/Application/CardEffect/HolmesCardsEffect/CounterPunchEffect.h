#ifndef COUNTER_PUNCH_EFFECT
#define COUNTER_PUNCH_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"

class CounterPunchEffect: public CardEffect{

    public:
    ContinueResult Continue(EffectContext & );
};

#endif /* COUNTER_PUNCH_EFFECT */
