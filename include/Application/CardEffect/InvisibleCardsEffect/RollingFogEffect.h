#ifndef ROLLING_FOG_EFFECT
#define ROLLING_FOG_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"

enum class RollingStep{
    CHOOSE_FOG,
    MOVE_FOG,
    GAIN_ACTION
};
class RollingFogEffect : public CardEffect{

    RollingStep step=RollingStep::CHOOSE_FOG;
    std::vector<int>Nodes;
    Fog * fog;

    public:
    ContinueResult Continue(EffectContext & );
    ContinueResult ChooseFog(EffectContext&);
    ContinueResult MoveFog(EffectContext &);
    ContinueResult GainAction(EffectContext &);

};

#endif /* ROLLING_FOG_EFFECT */
