#ifndef DREAMINGOF_REVENGE
#define DREAMINGOF_REVENGE

#include "Domain/Entities/CombatCard.h"

class DreaminOfRevenge : public CombatCard{

    public:
    DreaminOfRevenge();
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;



};

#endif /* DREAMING_OF_REVENGE */
