#ifndef THIRST_EFFECT
#define THIRST_EFFECT
#include "Application/CardEffect/CardEffect.h"

class ThirstEffect :public CardEffect{

    std::vector<int> rechabenode;
    public:
    ContinueResult Continue(EffectContext&);
    ContinueResult BuildReachableNodes(EffectContext&);
};

#endif /* THIRST_EFFECT */
