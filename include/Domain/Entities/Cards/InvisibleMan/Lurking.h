#ifndef LURKING
#define LURKING
#include "Domain/Entities/CombatCard.h"

class Lurking : public CombatCard{

    public:
    Lurking();
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;



};


#endif /* LURKING */
