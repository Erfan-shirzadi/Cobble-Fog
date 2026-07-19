#ifndef COMBAT_PARTICIPANT
#define COMBAT_PARTICIPANT
#include "Domain/Entities/Hero.h"
#include "Domain/Entities/CombatCard.h"

struct CombatParticipant{
    Hero  *hero;
    Fighter * fighter;
    CombatCard *card;

    int DamageOrDeffend=0;
    bool Won=false;
    bool IsActiveCardEffect=true;


};

#endif /* COMBAT_PARTICIPANT */
