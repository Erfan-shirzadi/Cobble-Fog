#ifndef DEDUCE_STRATEGY_EFFECT
#define DEDUCE_STRATEGY_EFFECT
#include "Application/CardEffect/CardEffect.h"

class DeduceStrategyEffect : public CardEffect{

    public:
    ContinueResult Continue(EffectContext & );
};

#endif /* DEDUCE_STRATEGY_EFFECT */
