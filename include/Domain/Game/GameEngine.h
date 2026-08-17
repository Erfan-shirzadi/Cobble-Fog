#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "Domain/Game/GameState.h"
#include "Domain/Player.h"
#include "Application/UseCases/TurnUseCase.h"
#include "Application/UseCases/SetUpGameUseCase.h"
#include "presentation/console/GameView.h"
#include "Application/interaction/ActionContext.h"
#include "Domain/Game/DataContext.h"
#include "Application/UseCases/SaveUseCase.h"
#include "Application/UseCases/LoadUseCase.h"

enum class GameEngineState{
    START_GAME,
    HERO_SELECTION,
    SETUP,
    GAME,
    GAMEOVER
};
class GameEngine {

    GameState gamestate;
    // Player * player1;
    // Player * player2;
    Board board;
    GameView view;

    // TurnUseCase turnusecase;
    TurnUseCase * TURNUSECASE;
    SetUpGameUseCase setup;

    GameEngineState state=GameEngineState::START_GAME;
    EffectContext context;

    SaveUseCase saveuseCase;

    void Process();
    
    public:
    GameEngine();
    void run();
    void GameResult(GameState &);


    void Start();
    void InitialObjects();
   
    void OnSelection(int selection);

    void SetUp();
    bool GameOver();

    void DeleteObjects();

    void SaveGame()const;
};
#endif /*GAMEENGINE_H */
