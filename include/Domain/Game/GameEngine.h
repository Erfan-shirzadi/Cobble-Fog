#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "Domain/Game/GameState.h"
#include "Domain/Player.h"
#include "Application/UseCases/TurnUseCase.h"
#include "Application/UseCases/SetUpGameUseCase.h"
#include "presentation/console/GameView.h"
#include "Application/interaction/ActionContext.h"
class GameEngine {

    GameState gamestate;
    Player player1;
    Player player2;
    Board board;
    GameView view;

    TurnUseCase turnusecase;

    ActionContext context;
    
    void Process();
    
    public:
    void run();
    void GameResult(GameState &);


    void Start();
   
    void OnSelection(int selection);

};
#endif /*GAMEENGINE_H */
