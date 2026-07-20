#ifndef DRACULA_ABILITY
#define DRACULA_ABILITY
#include "Application/interaction/EffectContext.h"
#include "Application/Ability/IAbility.h"

enum class DraculaAbilityStep{
    CHOOSE_TARGET,
    DRAW_CARD,
    FINISHED
};

class DraculaAbility :public IAbility{

    DraculaAbilityStep step=DraculaAbilityStep::CHOOSE_TARGET;

    std::vector<Fighter*>fighters;
    public :
    ContinueResult Continue(EffectContext &);
    ContinueResult BuildTargetMenu(EffectContext&);
    ContinueResult ChooseTarget(EffectContext &);
    ContinueResult Finished(EffectContext &);
    virtual FighterType HeroAbility()=0;

} ;


#endif /* DRACULA_ABILITY */
