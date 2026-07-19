#include "Application/CardEffect/NoneEffect.h"
#include "Application/interaction/EffectContext.h"

ContinueResult NoneEffect::Continue(EffectContext &){
    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}
