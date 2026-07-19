#ifndef COMBAT_CONTEXT
#define COMBAT_CONTEXT
#include "Domain/Entities/Board.h"
#include <memory>
#include "Application//interaction/Combat/CombatParticipant.h"
struct CombatContext{
    std::unique_ptr< CombatParticipant > Current;
    std::unique_ptr< CombatParticipant > Opponent;
    Board * board;

};

#endif /* COMBAT_CONTEXT */
