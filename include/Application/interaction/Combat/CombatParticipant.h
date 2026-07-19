#ifndef COMBAT_PARTICIPANT
#define COMBAT_PARTICIPANT
#include "Domain/Entities/Hero.h"
#include "Domain/Entities/CombatCard.h"
#include "Application/CardEffect/CardEffect.h"
struct CombatParticipant{
    Hero  *hero;
    Fighter * fighter;
    CombatCard *card;
     std::unique_ptr<CardEffect> effect;

    int DamageOrDeffend=0;
    bool Won=false;
    bool IsActiveCardEffect=true;


};

#endif /* COMBAT_PARTICIPANT */
