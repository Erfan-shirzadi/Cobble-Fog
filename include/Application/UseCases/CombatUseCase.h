#ifndef COMBAT_USECASE
#define COMBAT_USECASE
#include "Domain/Combat/CombatContext.h"
class CombatUseCase{
    public:
    void execute(CombatContext &);
    void BeforCombat(CombatContext &);
    void DuringCombat(CombatContext &);
    void AfterCombat(CombatContext &);
    void Finished(CombatContext &);
};

#endif /* COMBAT_USECASE */
