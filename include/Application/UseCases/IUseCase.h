#ifndef IUSE_CASE
#define IUSE_CASE
#include "Application/interaction/ContinueResult.h"
#include "Application/interaction/ActionContext.h"
#include "Application/interaction/EffectContext.h"

class IUseCase{

    public:
    virtual ContinueResult Continue(EffectContext&)=0;
    virtual void Start(EffectContext &)=0;

};

#endif /* IUSE_CASE */
