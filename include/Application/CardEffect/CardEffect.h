#ifndef CARD_EFFFECT
#define CARD_EFFFECT
#include "Application/interaction/ContinueResult.h"
struct EffectContext;
class CardEffect {
    int step=0;
    public :
    virtual ContinueResult Continue(EffectContext & )=0;
    int GetStep(){
        return step;
    }
    void SetStep(int newstep){
        this->step=newstep;
    }   


};

#endif /* CARD_EFFFECT */
