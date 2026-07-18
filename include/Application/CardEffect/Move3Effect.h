#ifndef MOVE3_EFFECT
#define MOVE3_EFFECT
#include "Application/CardEffect/CardEffect.h"

class Move3Effect :public CardEffect{

    std::vector<int> rechbleNodes;
    public: 
    ContinueResult Continue(EffectContext &);
    ContinueResult BuildReachableNodes(EffectContext &);
} ;

#endif /* MOVE3_EFFECT */
