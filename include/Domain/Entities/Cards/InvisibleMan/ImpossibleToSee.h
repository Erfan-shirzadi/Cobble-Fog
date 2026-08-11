#ifndef IMPOSSIBLE_TO_SEE
#define IMPOSSIBLE_TO_SEE

#include "Domain/Entities/CombatCard.h"

class ImpossibleToSee : public CombatCard{

    public:
    ImpossibleToSee();
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;



};


#endif /* IMPOSSIBLE_TO_SEE */
