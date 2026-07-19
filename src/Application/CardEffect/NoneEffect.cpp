#include "Application/CardEffect/NoneEffect.h"
ContinueResult NoneEffect::Continue(EffectContext &){
    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}
