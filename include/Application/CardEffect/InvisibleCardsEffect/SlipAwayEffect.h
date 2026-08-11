#ifndef SLIP_AWAY_EFFECT
#define SLIP_AWAY_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"

class ImpossibleToSeeEffect : public CardEffect{

    public:
    ContinueResult Continue(EffectContext & );
};

#endif /* SLIP_AWAY_EFFECT */
