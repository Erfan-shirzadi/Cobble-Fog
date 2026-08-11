#ifndef LURKING_EFFECT
#define LURKING_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"

class ImpossibleToSeeEffect : public CardEffect{

    public:
    ContinueResult Continue(EffectContext & );
};

#endif /* LURKING_EFFECT */
