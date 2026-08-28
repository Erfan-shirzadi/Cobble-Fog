#ifndef REIGN_OF_TERORR_EFFECT
#define REIGN_OF_TERORR_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"

class ReignOfTerrorEffect : public CardEffect{

    public:
    ContinueResult Continue(EffectContext & );
};


#endif /* REIGN_OF_TERORR_EFFECT */
