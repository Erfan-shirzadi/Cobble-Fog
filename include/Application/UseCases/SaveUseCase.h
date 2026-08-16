#ifndef SAVE_USE_CASE
#define SAVE_USE_CASE
#include "Application/UseCases/TurnUseCase.h"
#include "Domain/Game/GameState.h"
#include "Domain/Game/DataContext.h"

class SaveUseCase {

    public :
    void Save(DataContext)const;
    void SaveGameState(GameState*)const;
    void SavePlayer(int ,Player *)const;
    void SaveTurnUseCase();

};

#endif /* SAVE_USE_CASE */
