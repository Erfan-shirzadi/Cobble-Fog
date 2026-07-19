#ifndef THIRSTFORSUSTENANCE_H
#define THIRSTFORSUSTENANCE_H
#include "Domain/Entities/CombatCard.h"

class ThirstForSustenance: public CombatCard{

    public:
    ThirstForSustenance();
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;

};

#endif /* THIRSTFORSUSTENANCE_H */
