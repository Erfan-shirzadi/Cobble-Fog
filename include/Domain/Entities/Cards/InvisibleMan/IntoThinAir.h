#ifndef INTO_THIN_AIR
#define INTO_THIN_AIR
#include "Domain/Entities/CombatCard.h"

class IntoThinAir : public CombatCard{

    public:
    IntoThinAir();
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;



};


#endif /* INTO_THIN_AIR */
