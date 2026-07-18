#ifndef CARD_EFFFECT
#define CARD_EFFFECT
#include "Application/interaction/EffectContext.h"
#include "Application/interaction/ContinueResult.h"

class CardEffect {
    
    public :
    virtual ContinueResult Continue(EffectContext & ){};


};

#endif /* CARD_EFFFECT */
