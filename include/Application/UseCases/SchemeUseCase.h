#ifndef SCHEME_USECASE
#define SCHEME_USECASE
#include "Domain/Game/GameState.h"

class SchemeUseCase{

    public:
    bool execute(GameState & gamestate);
    bool CanDoAction(GameState & gamestate);
    Card * CardSelection(Hero * hero);
};
#endif /* SCHEME_USECASE */
