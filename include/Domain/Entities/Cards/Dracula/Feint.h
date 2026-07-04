#ifndef FEINT_H
#define FEINT_H
#include "Domain/Entities/CombatCard.h"

class Feint: public CombatCard{

    public:
    Feint();
     void Play(CombatContext & )const override;
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;

};

#endif /* FEINT_H */
