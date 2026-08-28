#ifndef INTO_THIN_AIR_EFFECT
#define INTO_THIN_AIR_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"
#include <vector>

enum class IntoThinStep{
    MOVE_INISIBLEMAN,
    CHOOSE_FOG,
    MOVE_FOG
};
class IntoThinAirEffect : public CardEffect{

    IntoThinStep step=IntoThinStep::MOVE_INISIBLEMAN;
    Fog * fog;

    std::vector<int> rechbleNodes;
    public:
    ContinueResult Continue(EffectContext & );
    ContinueResult MoveHero(EffectContext & context);
    ContinueResult ChooseFog(EffectContext & context);
    ContinueResult MoveFog(EffectContext & context);
};


#endif /* INTO_THIN_AIR_EFFECT */
