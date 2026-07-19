#ifndef TURN_USECASE
#define TURN_USECASE
#include "Domain/Game/GameState.h"
#include "Application/interaction/ContinueResult.h"
#include "Application/interaction/ActionContext.h"
#include "Application/UseCases/IUseCase.h"
#include "Application/UseCases/AttackUseCase.h"
#include "Application/UseCases/SchemeUseCase.h"
#include "Application/UseCases/ManeverUseCase.h"

enum class TurnStep{
    CHOOSE_ACTION,
    EXECUTE_USECASE,
    FINISHED,
    MANAGE_HAND_SIZE
};
class TurnUseCase{

    TurnStep step=TurnStep::CHOOSE_ACTION;
    IUseCase * CurrentUseCase=nullptr;

    ManeverUseCase manever;
    SchemeUseCase scheme;
    AttackUseCase attack;

    public:
    bool GameOver(GameState &);

    ContinueResult Continue(EffectContext &);

    void Start(EffectContext&);


    ContinueResult ExecuteAction(EffectContext&);
    ContinueResult ChooseAction(EffectContext &);
    ContinueResult FinishedResult(EffectContext & );
    ContinueResult ManageHandSize(EffectContext &);

    void SetUseCase(int index);


    MenuRequest BuildActionMenu();
    ContinueResult BuildHandMenu(Hero *);
};

#endif /* TURN_USECASE */
