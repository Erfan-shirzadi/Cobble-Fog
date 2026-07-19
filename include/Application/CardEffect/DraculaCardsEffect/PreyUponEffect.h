#ifndef PREYUPON_EFFECT
#define PREYUPON_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"

class PreyUponEffect : public CardEffect{

    public: 
    ContinueResult Continue(EffectContext &);
};

#endif /* PREYUPON_EFFECT */
