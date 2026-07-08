#ifndef MANEVER_USECASE
#define MANEVER_USECASE
#include "Domain/Entities/Hero.h"
#include <vector>
#include "Domain/Game/GameState.h"
class ManeverUseCase{

    public:
    void execute(GameState & );
    int BoostMovement(Hero *);
    int GetTargetNode(GameState &, int,Fighter *);
    Fighter * FighterSelection(Hero*);
};

#endif /* MANEVER_USECASE */