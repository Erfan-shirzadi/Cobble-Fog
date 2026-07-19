#ifndef LOOK_INTO_MY_EYSE_EFFECT
#define LOOK_INTO_MY_EYSE_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"

class LookIntoMyEyesEffect : public CardEffect{

    public :
    ContinueResult Continue(EffectContext & );
};

#endif /* LOOK_INTO_MY_EYSE_EFFECT */
