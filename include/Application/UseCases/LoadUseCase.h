#ifndef LOAD_USE_CASE
#define LOAD_USE_CASE
#include "Domain/Game/DataContext.h"
class LoadUseCase{

    public:
    void Load (DataContext &);
    void LoadGameState(GameState *);
    void LoadPlayer(int number,Player*);
    void LoadTurnUseCase(TurnUseCase*,Player *);
    void LoadManever(ManeverUseCase&);
    void LoadScheme(SchemeUseCase&,Player* currentplayer);
    void LoadAttck(AttackUseCase&);
};
#endif /* LOAD_USE_CASE */
