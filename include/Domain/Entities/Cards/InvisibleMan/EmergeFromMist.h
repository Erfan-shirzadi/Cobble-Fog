#ifndef EMERGEFROM_MIST
#define EMERGEFROM_MIST

#include "Domain/Entities/CombatCard.h"

class EmergeFromMist : public CombatCard{

    public:
    EmergeFromMist();
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;



};


#endif /* EMERGE_FROM_MIST */
