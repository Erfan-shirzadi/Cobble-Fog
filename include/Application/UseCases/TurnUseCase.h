#ifndef TURN_USECASE
#define TURN_USECASE
#include "Domain/Game/GameState.h"
#include "Application/interaction/ContinueResult.h"
#include "Application/interaction/ActionContext.h"
#include "Application/UseCases/IUseCase.h"
#include "Application/UseCases/AttackUseCase.h"
#include "Application/UseCases/SchemeUseCase.h"
#include "Application/UseCases/ManeverUseCase.h"

class TurnUseCase{

    int step=0;
    IUseCase * CurrentUseCase=nullptr;

    ManeverUseCase manever;
    SchemeUseCase scheme;
    AttackUseCase attack;

    public:
    void execute(GameState & );
    void ManageHandSize(Hero *);
    bool GameOver(GameState &);

    ContinueResult Continue(ActionContext &);

    void Start(ActionContext&);


    ContinueResult ExecuteAction(ActionContext&);
    ContinueResult ChooseAction(ActionContext &);
    ContinueResult FinishedResult(ActionContext & );

    void SetUseCase(int index);


    MenuRequest BuildActionMenu();
};

#endif /* TURN_USECASE */
