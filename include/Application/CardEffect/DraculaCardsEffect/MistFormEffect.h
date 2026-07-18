#ifndef MISTFORM_EFFECT
#define MISTFORM_EFFECT
#include "Application/CardEffect/CardEffect.h"

enum class MistFormEffectStep{
    MOVE_DRACULA,
    GAIN_ACTION,
    FINISHED,
};

class MistFormEffect : public CardEffect{

    MistFormEffectStep step=MistFormEffectStep::MOVE_DRACULA;

    std::vector<int> emptyNodes;

    public:

    ContinueResult Continue(EffectContext &);
    ContinueResult MoveDracula(EffectContext&);
    ContinueResult GainAction(EffectContext&);
    ContinueResult Finished(EffectContext &);

    ContinueResult BuildDestinationsMunu(EffectContext&);
};

#endif /* MISTFORM_EFFECT */
