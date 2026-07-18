#ifndef RAVENEING_SEDUCTION_EFFECT
#define RAVENEING_SEDUCTION_EFFECT
#include "Application/CardEffect/CardEffect.h"

enum class RaveningStep{
    CHOOSE_FIGHTER,
    MOVE_FIGHTER,
    DAMAGE_FIGHTER,
};
class RaveningSeductionEffect :  public CardEffect{

    RaveningStep step=RaveningStep::CHOOSE_FIGHTER;

    Fighter * fighter=nullptr;

    std::vector<Fighter*> Allfighters;
    std::vector <int> rechableNodes;
    
    public:
    ContinueResult Continue(EffectContext &);
    ContinueResult ChooseFighter(EffectContext&);
    ContinueResult MoveFighter(EffectContext&);
    ContinueResult DamageFighter(EffectContext&);

    ContinueResult BuildFightersMenu(EffectContext&);
    ContinueResult BuildDestinationMenu(EffectContext&);


};

#endif /* RAVENEING_SEDUCTION_EFFECT */
