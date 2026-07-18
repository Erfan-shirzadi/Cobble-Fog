#ifndef FEINT_EFFECT
#define FEINT_EFFECT

#include "Application/CardEffect/CardEffect.h"

class FeintEffect :public CardEffect{

    public: 
    ContinueResult Continue(EffectContext&);
};

#endif /* FEINT_EFFECT */
