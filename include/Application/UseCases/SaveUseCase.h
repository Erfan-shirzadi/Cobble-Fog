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
    void SaveCurrentPlayerNumber(int)const;
    void SaveHandViewStatus(HandView)const;
    void SaveGameViewState(ViewState)const;
    void SaveTurnUseCase(TurnUseCase*)const;

    void SaveManever(ManeverUseCase &)const;
    void SaveScheme(SchemeUseCase &)const;
    void SaveAttack(AttackUseCase &)const;
    void SaveTurnUseCaseStep(TurnStep)const;
    void SaveCurrentAction(ActoinType)const;

};

#endif /* SAVE_USE_CASE */
