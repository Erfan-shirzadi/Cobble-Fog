#ifndef COMBAT_CARD
#define COMBAT_CARD
#include "Domain/Entities/Card.h"

class CombatCard :public Card{

    int DamageOrDeffend;
    public:
    void SetDamageOrDeffend(int amount );
    int GetDamgeOrDeffend()const;
};

#endif /* COMBAT_CARD */
