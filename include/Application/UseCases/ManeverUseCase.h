#ifndef MANEVER_USECASE
#define MANEVER_USECASE
#include "Domain/Entities/Hero.h"
#include <vector>
#include "Domain/Game/GameState.h"
#include "Application/UseCases/IUseCase.h"

enum class ManeverStep{
    ASK_INCREASE_MOVEMENT,
    INCRESE_MOVEMENT,
    CHOOSE_CARD,
    CHOOSE_FIHGTER,
    CHOOSE_DESTINATION,
    MOVE,
    FINISHED
};
class ManeverUseCase : public IUseCase{


    ManeverStep step=ManeverStep::ASK_INCREASE_MOVEMENT;
    Fighter* selectedHero=nullptr;
    int IncreseMovment=0;
    std::vector<Fighter*> fighters;
    std::vector<int>rechableNode;
    int Destination;

    public:
    void execute(GameState & );
    int BoostMovement(Hero *);
    int GetTargetNode(GameState &, int,Fighter *);
    Fighter * FighterSelection(Hero*);

     ContinueResult Continue(ActionContext&)override;
     void Start(ActionContext&)override;
     ContinueResult AskIncreseMovment(ActionContext&);
     ContinueResult ChooseCard(ActionContext&);
     ContinueResult CooseFighter(ActionContext&);
     ContinueResult ChooseDestination(ActionContext&);
     ContinueResult Move(ActionContext&);
     ContinueResult Finished(ActionContext&);

     ContinueResult BuildAskIncreaseMovmentMenu();
     ContinueResult BuildCardChoosingMunu(ActionContext&);
     ContinueResult BuildFightersMenu(ActionContext&);
     ContinueResult BuildNodesMenu(ActionContext&);



};

#endif /* MANEVER_USECASE */