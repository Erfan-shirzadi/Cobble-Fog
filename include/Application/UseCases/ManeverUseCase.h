#ifndef MANEVER_USECASE
#define MANEVER_USECASE
#include "Domain/Entities/Hero.h"
#include <vector>
#include "Domain/Game/GameState.h"
#include "Application/UseCases/IUseCase.h"

enum class ManeverStep{
    DRAW_CARD,
    ASK_INCREASE_MOVEMENT,
    INCRESE_MOVEMENT,
    CHOOSE_CARD,
    CHOOSE_FIHGTER,
    CHOOSE_DESTINATION,
    MOVE,
    FINISHED
};
class ManeverUseCase : public IUseCase{


    ManeverStep step=ManeverStep::DRAW_CARD;
    Fighter* selectedHero=nullptr;
    int incresemovment=0;
    std::vector<Fighter*> fighters;
    std::vector<int>rechableNode;
    int Destination;

    public:
    void ResetMovment();
    void InceaseMovment(Hero *,int);


     ContinueResult Continue(EffectContext&)override;
     void Start(EffectContext&)override;
     ContinueResult AskIncreseMovment(EffectContext&);
     ContinueResult ChooseCard(EffectContext&);
     ContinueResult CooseFighter(EffectContext&);
     ContinueResult ChooseDestination(EffectContext&);
     ContinueResult Move(EffectContext&);
     ContinueResult Finished(EffectContext&);
     ContinueResult drawcard(EffectContext&);

     ContinueResult BuildAskIncreaseMovmentMenu();
     ContinueResult BuildCardChoosingMunu(EffectContext&);
     ContinueResult BuildFightersMenu(EffectContext&);
     ContinueResult BuildNodesMenu(EffectContext&);



};

#endif /* MANEVER_USECASE */