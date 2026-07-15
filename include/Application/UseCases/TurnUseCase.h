#ifndef TURN_USECASE
#define TURN_USECASE
#include "Domain/Game/GameState.h"
#include "Application/interaction/ContinueResult.h"
#include "Application/interaction/ActionContext.h"
class TurnUseCase{

    int step=0;
    public:
    void execute(GameState & );
    void ManageHandSize(Hero *);
    bool GameOver(GameState &);

    ContinueResult Continue(ActionContext &);

    void Start(ActionContext&);


    ContinueResult ExecuteAction(ActionContext&);
    ContinueResult ChooseAction(ActionContext &);
    ContinueResult FinishedResult();
};

#endif /* TURN_USECASE */
