#ifndef COMBAT_CARD
#define COMBAT_CARD
#include "Domain/Entities/Card.h"
#include "Domain/Combat/CombatContext.h"
class CombatCard :public Card{

    int DamageOrDeffend;
    public:
    void SetDamageOrDeffend(int amount );
    int GetDamgeOrDeffend()const;
    virtual void Play(CombatContext & )const=0;

};

#endif /* COMBAT_CARD */
