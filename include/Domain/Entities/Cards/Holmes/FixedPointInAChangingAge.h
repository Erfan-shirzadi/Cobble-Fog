#ifndef FIXEDPOINTINACHANGINGAGE_H
#define FIXEDPOINTINACHANGINGAGE_H
#include "Domain/Entities/CombatCard.h"

class FixedPointInAChangingAge : public CombatCard{

    public:
    FixedPointInAChangingAge();
     void Play(CombatContext & )const override;
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;


};


#endif /* FIXEDPOINTINACHANGINGAGE_H */
