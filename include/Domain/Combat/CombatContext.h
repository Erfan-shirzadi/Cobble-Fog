#ifndef COMBAT_CONTEXT
#define COMBAT_CONTEXT
#include "Domain/Combat/CombatParticipant.h"
#include "Domain/Entities/Board.h"
#include "Domain/Combat/CombatResult.h"
#include <memory>
struct CombatContext{
    std::unique_ptr< CombatParticipant > Current;
    std::unique_ptr< CombatParticipant > Opponent;
    Board * board;

};

#endif /* COMBAT_CONTEXT */
