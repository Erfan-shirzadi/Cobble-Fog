#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "Domain/Game/GameState.h"
#include "Domain/Player.h"
#include "Application/UseCases/TurnUseCase.h"
#include "Application/UseCases/SetUpGameUseCase.h"
#include "presentation/console/GameView.h"
#include "Application/interaction/ActionContext.h"

enum class GameEngineState{
    HERO_SELECTION,
    SETUP,
    GAME,
    GAMEOVER
};
class GameEngine {

    GameState gamestate;
    Player player1;
    Player player2;
    Board board;
    GameView view;

    TurnUseCase turnusecase;
    SetUpGameUseCase setup;

    GameEngineState state=GameEngineState::HERO_SELECTION;
    EffectContext context;
    void Process();
    
    public:
    GameEngine();
    void run();
    void GameResult(GameState &);


    void Start();
   
    void OnSelection(int selection);

    void SetUp();
    bool GameOver();

    void FinishedGame();

};
#endif /*GAMEENGINE_H */
