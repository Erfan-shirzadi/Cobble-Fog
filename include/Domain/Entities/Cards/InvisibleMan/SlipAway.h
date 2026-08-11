#ifndef SLIP_AWAY
#define SLIP_AWAY
#include "Domain/Entities/CombatCard.h"

class SlipAway : public CombatCard{

    public:
    SlipAway();
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;



};


#endif /* SLIP_AWAY */
