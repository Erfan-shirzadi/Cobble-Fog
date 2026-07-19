#ifndef COMBAT_USECASE
#define COMBAT_USECASE
#include "Application/interaction/ContinueResult.h"
#include "Application/interaction/EffectContext.h"
#include "Application/interaction/Combat/CombatContext.h"

enum class CombatStep{
    BEFOR_COMBAT,
    DURING_COMBAT,
    AFTER_COMBAT,
    FINISHED
};

enum class CardPlayStep{
    DEFFENDER_CARD,
    ATTACKER_CARD,
};
class CombatUseCase{

    CombatStep combatstep;
    CardPlayStep cardStep;
    public:


    ContinueResult Continue(EffectContext &);
    ContinueResult BeforCombat(EffectContext &);
    ContinueResult DuringCombat(EffectContext &);
    ContinueResult AfterCombat(EffectContext &);
    ContinueResult Finished(EffectContext &);
};

#endif /* COMBAT_USECASE */
