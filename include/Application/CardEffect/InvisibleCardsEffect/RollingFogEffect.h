#ifndef ROLLING_FOG_EFFECT
#define ROLLING_FOG_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"

class ImpossibleToSeeEffect : public CardEffect{

    public:
    ContinueResult Continue(EffectContext & );
};

#endif /* ROLLING_FOG_EFFECT */
