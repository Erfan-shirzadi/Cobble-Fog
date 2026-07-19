#ifndef EXPLIOT_EFFECT
#define EXPLIOT_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"

class ExpliotEffect : public CardEffect{

    public: 
    ContinueResult Continue(EffectContext &);
};

#endif /* EXPLIOT_EFFECT */
