#ifndef MANEVER_USECASE
#define MANEVER_USECASE
#include "Domain/Entities/Hero.h"
#include <vector>
#include "Domain/Game/GameState.h"
#include "Application/UseCases/IUseCase.h"

class ManeverUseCase : public IUseCase{

    public:
    void execute(GameState & );
    int BoostMovement(Hero *);
    int GetTargetNode(GameState &, int,Fighter *);
    Fighter * FighterSelection(Hero*);
     ContinueResult Continue(ActionContext&)override;

};

#endif /* MANEVER_USECASE */