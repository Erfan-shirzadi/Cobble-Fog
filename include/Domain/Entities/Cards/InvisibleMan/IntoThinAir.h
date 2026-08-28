#ifndef INTOTHIN_AIR
#define INTOTHIN_AIR
#include "Domain/Entities/CombatCard.h"

class IntoThinAir : public CombatCard{

    public:
    IntoThinAir();
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;



};


#endif /* INTO_THIN_AIR */
