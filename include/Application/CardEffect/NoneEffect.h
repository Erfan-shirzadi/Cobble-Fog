#ifndef NONE_EFFECT
#define NONE_EFFECT

#include "Application/CardEffect/CardEffect.h"

class NoneEffect : public CardEffect{

    public : 
    ContinueResult Continue(EffectContext &);
};

#endif /* NONE_EFFECT */
