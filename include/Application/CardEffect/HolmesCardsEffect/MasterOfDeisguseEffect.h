#ifndef MASTER_OF_DEISGUSE_EFFECT
#define MASTER_OF_DEISGUSE_EFFECT
#include "Application/CardEffect/CardEffect.h"

class MasterOfDeisGuseEffect:public CardEffect{

    public:
    ContinueResult Continue(EffectContext &);
};

#endif /* MASTER_OF_DEISGUSE_EFFECT */
