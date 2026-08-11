#ifndef EMERGE_FROM_MIST_EFFECT
#define EMERGE_FROM_MIST_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"

class EmergeFromMistEffect : public CardEffect{

    public:
    ContinueResult Continue(EffectContext & );
};


#endif /* EMERGE_FROM_MIST_EFFECT */
