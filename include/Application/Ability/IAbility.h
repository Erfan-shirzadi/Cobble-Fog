#ifndef ABILITY_H
#define ABILITY_H
#include "Application/interaction/EffectContext.h"

class IAbility {

    public :
    virtual ContinueResult Continue(EffectContext &)=0;
    virtual bool CanUseAbility(){
        return false;
    };
};
#endif /* ABILITY_H */
