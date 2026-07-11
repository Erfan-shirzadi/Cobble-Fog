#ifndef TURN_USECASE
#define TURN_USECASE
#include "Domain/Game/GameState.h"
class TurnUseCase{

    public:
    void execute(GameState & );
    void ManageHandSize(Hero *);
};

#endif /* TURN_USECASE */
