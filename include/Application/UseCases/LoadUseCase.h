#ifndef LOAD_USE_CASE
#define LOAD_USE_CASE
#include "Domain/Game/DataContext.h"
class LoadUseCase{

    int sessionNumber;
    public:
    void Load (DataContext &, int session);
    void LoadGameState(GameState *);
    void LoadPlayer(int number,Player*);
    void LoadTurnUseCase(TurnUseCase*,GameState*);
    void LoadManever(ManeverUseCase&,Player *);
    void LoadScheme(SchemeUseCase&,Player* currentplayer);
    void LoadAttck(AttackUseCase&,GameState*);
    void LoadCommbatContext(CombatContext&,GameState* gamestate);
};
#endif /* LOAD_USE_CASE */
