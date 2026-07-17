#ifndef COMBAT_USECASE
#define COMBAT_USECASE
#include "Domain/Combat/CombatContext.h"
#include "Application/interaction/ContinueResult.h"

enum class CombatStep{
    BEFOR_COMBAT,
    DURING_COMBAT,
    AFTER_COMBAT,
    FINISHED
};
class CombatUseCase{

    CombatStep step;

    public:


    ContinueResult Continue(CombatContext &);
    void BeforCombat(CombatContext &);
    void DuringCombat(CombatContext &);
    void AfterCombat(CombatContext &);
    void Finished(CombatContext &);
};

#endif /* COMBAT_USECASE */
