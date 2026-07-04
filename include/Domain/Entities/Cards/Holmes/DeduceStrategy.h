#ifndef DEDUCESTRATEGY_H
#define DEDUCESTRATEGY_H
#include "Domain/Entities/CombatCard.h"

class DeduceStrategy : public CombatCard{

    public:
    DeduceStrategy();
     void Play(CombatContext & )const override;
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;


};

#endif /* DEDUCESTRATEGY_H */
