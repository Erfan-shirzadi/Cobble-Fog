#ifndef DASH_H
#define DASH_H
#include "Domain/Entities/CombatCard.h"

class Dash :public CombatCard{

    public :
    Dash();
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;



};

#endif /* DASH_H */
