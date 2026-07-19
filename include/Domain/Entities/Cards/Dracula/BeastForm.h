#ifndef BEASTFORM_H
#define BEASTFORM_H
#include "Domain/Entities/CombatCard.h"

class BestForm :public CombatCard{
    
    public:
    BestForm();
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;


};

#endif /* BEASTFORM_H */
