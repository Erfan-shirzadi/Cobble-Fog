#ifndef SLIP_AWAY_EFFECT
#define SLIP_AWAY_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"

enum class SlipStep{
    CHOOSE_FOG,
    MOVE_FOG,
};
class SlipAwayEffect : public CardEffect{

    SlipStep step=SlipStep::CHOOSE_FOG;
    std::vector<int>Nodes;
    Fog * fog;
    public:
    ContinueResult Continue(EffectContext & );
    ContinueResult ChooseFog(EffectContext&);
    ContinueResult MoveFog(EffectContext &);

};

#endif /* SLIP_AWAY_EFFECT */
