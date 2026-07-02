#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "Domain/Entities/Board.h"
#include "Domain/Entities/Game/GamePhase.h"

struct GameState{

    Board board;
    GamePhase phase;
    
};


#endif /* GAMESTATE_H */
