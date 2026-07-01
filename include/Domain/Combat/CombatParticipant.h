#ifndef COMBAT_PARTICIPANT
#define COMBAT_PARTICIPANT
#include "Domain/Entities/Fighter.h"
#include "Domain/Entities/Hero.h"
#include "Domain/Entities/CombatCard.h"
struct CombatParticipant
{
    Hero & hero;
    Fighter & fighter;
    CombatCard & card;
    int DamageOrDeffend=0;

};

#endif /* COMBAT_PARTICIPANT */
