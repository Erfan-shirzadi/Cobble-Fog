#ifndef AMBUSH_H
#define AMBUSH_H
#include "Domain/Entities/CombatCard.h"

class Ambush : public CombatCard{

    public:
    Ambush();
     void Play(CombatContext & )const override;
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;
};
#endif /* AMBUSH_H */
