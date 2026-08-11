#ifndef STEP_LIGHTLY_EFFECT
#define STEP_LIGHTLY_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"

class ImpossibleToSeeEffect : public CardEffect{

    public:
    ContinueResult Continue(EffectContext & );
};

#endif /* STEP_LIGHTLY_EFFECT */
