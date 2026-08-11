#ifndef IMPOSSIBLE_TO_SEE_EFFECT
#define IMPOSSIBLE_TO_SEE_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"

class ImpossibleToSeeEffect : public CardEffect{

    public:
    ContinueResult Continue(EffectContext & );
};



#endif /* IMPOSSIBLE_TO_SEE_EFFECT */
