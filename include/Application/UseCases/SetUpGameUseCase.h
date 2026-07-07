#ifndef SETUPGAME_USECASE
#define SETUPGAME_USECASE
#include "Domain/Game/GameState.h"

class SetUpGameUseCase{

    public:
    void execute(GameState & gamestate);
    void CreateHero(Player * );
    void ShuffelDecks(Hero *);
    void DrawInitialCards(Hero *);
};

#endif /* SETUP_USECASE */
