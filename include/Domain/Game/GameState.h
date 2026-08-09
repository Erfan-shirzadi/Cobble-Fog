#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "Domain/Entities/Board.h"
#include "Domain/Game/GamePhase.h"
#include "Domain/Player.h"
#include "Domain/Game/GameLog.h"
#include "Domain/Game/GameResult.h"
#include "Application/interaction/Combat/CombatContext.h"
struct GameState{
    GameLog log;
    Board board;
    GamePhase phase;
    Player *player1;
    Player *player2;
    Player * currnetPlayer=nullptr;
    Player * opponentPlayre=nullptr;
    CombatContext * combatsatat=nullptr;
    GameResult gameresult;
};


#endif /* GAMESTATE_H */
