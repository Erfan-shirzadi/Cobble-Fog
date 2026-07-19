#ifndef THEGAMEISAFOOT_H
#define THEGAMEISAFOOT_H
#include "Domain/Entities/CombatCard.h"

class TheGameIsAfoot : public CombatCard{

    public:
    TheGameIsAfoot();
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;



};

#endif /* THEGAMEISAFOOT_H */
