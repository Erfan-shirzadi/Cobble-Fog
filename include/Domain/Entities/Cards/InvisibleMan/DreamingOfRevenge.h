#ifndef DREAMING_OF_REVENGE
#define DREAMING_OF_REVENGE

#include "Domain/Entities/CombatCard.h"

class DreaminOfRevenge : public CombatCard{

    public:
    DreaminOfRevenge();
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;



};

#endif /* DREAMING_OF_REVENGE */
