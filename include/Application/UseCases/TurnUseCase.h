#ifndef TURN_USECASE
#define TURN_USECASE
#include "Domain/Game/GameState.h"
#include "Application/interaction/ContinueResult.h"
#include "Application/interaction/ActionContext.h"
#include "Application/UseCases/IUseCase.h"
#include "Application/UseCases/AttackUseCase.h"
#include "Application/UseCases/SchemeUseCase.h"
#include "Application/UseCases/ManeverUseCase.h"
#include "Application/Ability/IAbility.h"

enum class TurnStep{
    START,
    CHOOSE_ACTION,
    EXECUTE_USECASE,
    FINISHED,
    MANAGE_HAND_SIZE,
    ASK_FOR_CONTINUE_REMOVE_CARD
};

enum class ActoinType{
    MANEVER,
    SCHEME,
    ATTACK,
    NONE
};

enum class AbilityStep{
    ASK_USE_ABILITY,
    EXECUTE_ABILITY,
    FINISHED
};
class TurnUseCase{

    TurnStep step=TurnStep::CHOOSE_ACTION;
    AbilityStep abilitystep=AbilityStep::ASK_USE_ABILITY;
    IUseCase * CurrentUseCase=nullptr;
    ActoinType currentaction;
    ManeverUseCase manever;
    SchemeUseCase scheme;
    AttackUseCase attack;

    std::vector<ActoinType>possibleAction;

    std::unique_ptr<IAbility> ability=nullptr;


    public:

    ContinueResult Continue(EffectContext &);

    ContinueResult Start(EffectContext&);


    ContinueResult ExecuteAction(EffectContext&);
    ContinueResult ChooseAction(EffectContext &);
    ContinueResult FinishedResult(EffectContext & );
    ContinueResult ManageHandSize(EffectContext &);
    ContinueResult AskRemoveMoreCard(EffectContext &);

    void SetUseCase(int);


    MenuRequest BuildActionMenu(EffectContext & context);
    ContinueResult BuildHandMenu(Hero *);
    ContinueResult AskAbility(EffectContext &);
    ContinueResult ExecuteAbility(EffectContext &);
    ContinueResult Ability(EffectContext &);


    void Reset(EffectContext&);
    ManeverUseCase & GetManeverUseCase();
    SchemeUseCase &  GetSchemeUseCase();
    AttackUseCase & GetAttackUseCase();
    ActoinType CurrentAction();
    TurnStep GetTurnUseCaseStep();
    void SetStep(TurnStep);

};

#endif /* TURN_USECASE */
