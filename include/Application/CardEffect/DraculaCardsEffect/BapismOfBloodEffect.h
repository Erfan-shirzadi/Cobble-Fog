#ifndef BAPISM_OF_BLOOD_EFFECT
#define BAPISM_OF_BLOOD_EFFECT
#include "Application/CardEffect/CardEffect.h"

enum class BapismEffectStep{
    HEAL_DRACULA,
    RETURN_SISTER,
    FINISHED,
};

enum class ReturnSisterStep{
    HEAL_SISITER,
    CHOOSEDESTINATION,
};

class BapismOfBloodEffect : public CardEffect{
    BapismEffectStep bapismstep=BapismEffectStep::HEAL_DRACULA;
    ReturnSisterStep returnstep=ReturnSisterStep::CHOOSEDESTINATION;

    std::vector<int> reachableNodes;
    Fighter * sister=nullptr;

    public:
     ContinueResult Continue(EffectContext &)override;
    ContinueResult ReturnSister(EffectContext &);
    ContinueResult HealSister(EffectContext &);
    ContinueResult ChooseDestinationSister(EffectContext&);
    ContinueResult BuildDestinationMenu(EffectContext context);
};

#endif /* BAPISM_OF_BLOOD_EFFECT */
