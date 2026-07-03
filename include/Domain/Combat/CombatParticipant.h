#ifndef COMBAT_PARTICIPANT
#define COMBAT_PARTICIPANT
#include "Domain/Entities/Hero.h"
#include "Domain/Entities/CombatCard.h"
struct CombatParticipant{
    Hero  *hero;
    Fighter * fighter;
    Card *card;
    int DamageOrDeffend=0;

};

#endif /* COMBAT_PARTICIPANT */
