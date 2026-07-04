#ifndef COMBAT_CONTEXT
#define COMBAT_CONTEXT
#include "Domain/Combat/CombatParticipant.h"
#include "Domain/Entities/Board.h"
#include "Domain/Combat/CombatResult.h"
struct CombatContext{
    CombatParticipant * Current;
    CombatParticipant * Opponent;
    Board * board;

};

#endif /* COMBAT_CONTEXT */
