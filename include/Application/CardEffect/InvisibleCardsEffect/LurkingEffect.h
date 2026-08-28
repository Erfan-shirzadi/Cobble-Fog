#ifndef LURKING_EFFECT
#define LURKING_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"
#include <vector>

enum class LurkingStep{
    DRAW_CARD,
    CHOOSE_EFFECT,
    MOVE_INVISIBLEMAN_TO_FOG,
    CHOOSE_FOG,
    MOVE3_FOG
};
class LurkingEffect : public CardEffect{

    LurkingStep step=LurkingStep::DRAW_CARD;
    std::vector<int>Nodes;
    Fog * fog;
    public:
    ContinueResult Continue(EffectContext & );
    ContinueResult ChooseEffect(EffectContext &);
    ContinueResult MoveInvisibleMan(EffectContext &);
    ContinueResult ChooseFog(EffectContext&);
    ContinueResult MoveFog(EffectContext &);

};

#endif /* LURKING_EFFECT */
