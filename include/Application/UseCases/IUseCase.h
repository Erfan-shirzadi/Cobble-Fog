#ifndef IUSE_CASE
#define IUSE_CASE
#include "Application/interaction/ContinueResult.h"
#include "Application/interaction/ActionContext.h"

class IUseCase{

    public:
    virtual ContinueResult Continue(ActionContext&)=0;

};

#endif /* IUSE_CASE */
