#ifndef EMERGE_FROM_MIST
#define EMERGE_FROM_MIST

#include "Domain/Entities/CombatCard.h"

class ImpossibleToSee : public CombatCard{

    public:
    ImpossibleToSee();
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;



};


#endif /* EMERGE_FROM_MIST */
