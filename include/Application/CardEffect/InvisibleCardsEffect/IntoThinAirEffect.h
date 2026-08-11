#ifndef INTO_THIN_AIR_EFFECT
#define INTO_THIN_AIR_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"

class ImpossibleToSeeEffect : public CardEffect{

    public:
    ContinueResult Continue(EffectContext & );
};


#endif /* INTO_THIN_AIR_EFFECT */
