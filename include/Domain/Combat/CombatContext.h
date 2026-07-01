#ifndef COMBAT_CONTEXT
#define COMBAT_CONTEXT
#include "Domain/Combat/CombatParticipant.h"
#include "Domain/Entities/Board.h"
#include "Domain/Combat/CombatResult.h"
struct CombatContext{
    CombatParticipant attaker;
    CombatParticipant deffender;
    Board & board;
    CombatResult result;
    bool MoveAttacker=false;
    bool MoveDeffender=false;
    bool IsActiveCardEffectAttaker=true;
    bool IsActiveCardEffectDeffender=true;


};

#endif /* COMBAT_CONTEXT */
