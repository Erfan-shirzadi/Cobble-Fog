#ifndef EXPLIOT_EFFECT
#define EXPLIOT_EFFECT
#include "Application/CardEffect/CardEffect.h"

class ExpliotEffect : public CardEffect{

    public: 
    ContinueResult Continue(EffectContext &);
};

#endif /* EXPLIOT_EFFECT */
