#ifndef COUNTERPUNCH_H
#define COUNTERPUNCH_H
#include "Domain/Entities/CombatCard.h"

class CounterPunch : public CombatCard{

    public:
    CounterPunch();
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;



};

#endif /* COUNTERPUNCH_H */
