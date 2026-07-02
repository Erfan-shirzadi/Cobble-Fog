#ifndef COMBAT_CARD
#define COMBAT_CARD
#include "Domain/Entities/Card.h"
struct CombatContext;
class CombatCard :public Card{

    int DamageOrDeffend;
    public:
    void SetDamageOrDeffend(int amount );
    int GetDamgeOrDeffend()const;
    virtual void Play(CombatContext & )const=0;
    virtual PlayTiming GetCardPlayTiming()const=0;
    virtual FighterType GetOwner()const=0;

};

#endif /* COMBAT_CARD */
