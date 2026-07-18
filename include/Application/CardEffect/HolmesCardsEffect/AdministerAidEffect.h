#ifndef ADMINISTER_AID_EFFECT
#define ADMINISTER_AID_EFFECT
#include "Application/CardEffect/CardEffect.h"

enum class AdministerEffectStep{
    CHOOSE_DESTINATION,
    HEAL_HOLMES,
    DRAW_CARD
};

class AdministerAidEffect : public CardEffect{

    AdministerEffectStep step=AdministerEffectStep::CHOOSE_DESTINATION;
    std::vector<int> rechableNodes;
    public:
    ContinueResult Continue(EffectContext &);

    ContinueResult ChooseDestination(EffectContext &);
    ContinueResult BuildReachableNodes(EffectContext &);
};

#endif /* ADMINISTER_AID_EFFECT */
