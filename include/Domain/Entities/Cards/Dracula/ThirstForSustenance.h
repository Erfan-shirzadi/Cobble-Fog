#ifndef THIRSTFORSUSTENANCE_H
#define THIRSTFORSUSTENANCE_H
#include "Domain/Entities/CombatCard.h"

class ThirstForSustenance: public CombatCard{

    public:
    ThirstForSustenance();
     void Play(CombatContext & )const override;
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;

};

#endif /* THIRSTFORSUSTENANCE_H */
