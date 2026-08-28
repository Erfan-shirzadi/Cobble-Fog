#ifndef SAVE_USE_CASE
#define SAVE_USE_CASE
#include "Application/UseCases/TurnUseCase.h"
#include "Domain/Game/GameState.h"
#include "Domain/Game/DataContext.h"

class SaveUseCase {

    int sessionNumber;
    std::string folderpathPlayer2="/home/lionborn/programs/projects/PROJECT/Cobble & fog/Cobble-Fog/include/Infrastructure/SavedGames/Game1/Player2/";
    std::string folderpathPlayer1="/home/lionborn/programs/projects/PROJECT/Cobble & fog/Cobble-Fog/include/Infrastructure/SavedGames/Game1/Player1/";
    std::string foderpathTurnusecase="/home/lionborn/programs/projects/PROJECT/Cobble & fog/Cobble-Fog/include/Infrastructure/SavedGames/Game1/TurnUseCase/";
    std::string folderpathGame="/home/lionborn/programs/projects/PROJECT/Cobble & fog/Cobble-Fog/include/Infrastructure/SavedGames/Game1";
    public :
    void SetFolderPath();
    void Save(DataContext,int session);
    void SaveGameState(GameState*)const;
    void SavePlayer(int ,Player *)const;
    void SaveCurrentPlayerNumber(int)const;
    void SaveHandViewStatus(HandView)const;
    void SaveGameViewState(ViewState)const;
    void SaveTurnUseCase(TurnUseCase*)const;

    void SaveManever(ManeverUseCase &)const;
    void SaveScheme(SchemeUseCase &)const;
    void SaveAttack(AttackUseCase &)const;
    void SaveTurnUseCaseStep(TurnStep)const;
    void SaveCurrentAction(ActoinType)const;
    void SaveCombatContext(CombatContext*)const;

    void RemoveTxtFiles(std::string)const;

    void UpdateSessionFile(int);

    std::vector<std::string> GetSessionStatus()const;

};

#endif /* SAVE_USE_CASE */
