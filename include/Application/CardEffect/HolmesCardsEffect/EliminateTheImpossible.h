#ifndef ELIMINATE_THE_IMPOSSIBLE_EFFECT
#define ELIMINATE_THE_IMPOSSIBLE_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"

class EliminateTheImpossibleEffect :public CardEffect{

    public: 
    ContinueResult Continue(EffectContext&);
    ContinueResult BuildCardMenu(EffectContext&);
};

#endif /* ELIMINATE_THE_IMPOSSIBLE_EFFECT */
