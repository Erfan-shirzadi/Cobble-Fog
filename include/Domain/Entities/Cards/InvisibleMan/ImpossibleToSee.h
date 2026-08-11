#ifndef IMPOSSIBLETO_SEE
#define IMPOSSIBLETO_SEE

#include "Domain/Entities/CombatCard.h"

class ImpossibleToSee : public CombatCard{

    public:
    ImpossibleToSee();
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;



};


#endif /* IMPOSSIBLE_TO_SEE */
