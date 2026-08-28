#ifndef STEP_LIGHTLY_EFFECT
#define STEP_LIGHTLY_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"
#include <vector>
enum class StepStepLightly{
    DAMAGE_ENMEY,
    CHOOSE_FOG,
    MOVE_FOG,
};
class StepLightlyEffect : public CardEffect{

    StepStepLightly step=StepStepLightly::DAMAGE_ENMEY;
    std::vector<Fighter*> enemies;
    std::vector<int>Nodes;
    Fog * fog;
    public:
    ContinueResult Continue(EffectContext & );
    ContinueResult DamageEnemy(EffectContext &);
    ContinueResult ChooseFog(EffectContext &);
    ContinueResult MoveFog(EffectContext &);
};

#endif /* STEP_LIGHTLY_EFFECT */
