#ifndef SAVE_USE_CASE
#define SAVE_USE_CASE
#include "Application/UseCases/TurnUseCase.h"
#include "Domain/Game/GameState.h"

class SaveUseCase {

    public :
    void Save();
    void SaveGameState();
    void SaveTurnUseCase();

};

#endif /* SAVE_USE_CASE */
