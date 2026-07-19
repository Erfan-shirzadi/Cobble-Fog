#ifndef FIXED_A_POINT_IN_CHANGING_AGE_EFFECT
#define FIXED_A_POINT_IN_CHANGING_AGE_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"

class FixedAPointInChangingAgeEffect : public CardEffect{

    public:
    ContinueResult Continue(EffectContext& context);
};

#endif /* FIXED_A_POINT_IN_CHANGING_AGE_EFFECT */
