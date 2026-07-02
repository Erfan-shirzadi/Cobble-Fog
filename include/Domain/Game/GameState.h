#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "Domain/Entities/Board.h"
#include "Domain/Game/GamePhase.h"
#include "Domain/Player.h"
struct GameState{

    Board board;
    GamePhase phase;

    Player player1;
    Player player2;
    Player * currnetPlayer=nullptr;
    Player * opponentPlayre=nullptr;
    
};


#endif /* GAMESTATE_H */
