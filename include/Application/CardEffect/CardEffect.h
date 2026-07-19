#ifndef CARD_EFFFECT
#define CARD_EFFFECT
#include "Application/interaction/ContinueResult.h"
struct EffectContext;
class CardEffect {
    
    public :
    virtual ContinueResult Continue(EffectContext & )=0;


};

#endif /* CARD_EFFFECT */
