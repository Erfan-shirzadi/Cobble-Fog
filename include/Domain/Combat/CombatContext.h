#ifndef COMBAT_CONTEXT
#define COMBAT_CONTEXT
#include "Domain/Combat/CombatParticipant.h"
#include "Domain/Entities/Board.h"

struct CombatContext{
    CombatParticipant attaker;
    CombatParticipant deffender;
    Board & board;
};

#endif /* COMBAT_CONTEXT */
