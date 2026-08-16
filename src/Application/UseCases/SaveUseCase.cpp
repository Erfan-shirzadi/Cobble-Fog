#include "Application/UseCases/SaveUseCase.h"


void SaveUseCase::Save(DataContext data)const{

    SaveGameState(data.context.context.Gamestate);
}

void SaveUseCase::SaveGameState(GameState * gamestate)const{

}
    void SaveTurnUseCase();
