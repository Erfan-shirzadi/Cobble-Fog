#ifndef DREAMING_OF_REVENGE_EFFECT
#define DREAMING_OF_REVENGE_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"

class DreamingOfRevengeEffect : public CardEffect{

    public:
    ContinueResult Continue(EffectContext & );
};



#endif /* DREAMING_OF_REVENGE_EFFECT */
