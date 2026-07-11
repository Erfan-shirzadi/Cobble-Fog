#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "Domain/Game/GameState.h"
#include "Domain/Player.h"
class GameEngine {

    GameState gamestate;
    Player player1;
    Player player2;
    Board board;
    public:
    void run();
    void GameResult(GameState &);

};
#endif /*GAMEENGINE_H */
