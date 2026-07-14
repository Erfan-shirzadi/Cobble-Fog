#ifndef CONTINUE_RESULT
#define CONTINUE_RESULT
#include "Application/interaction/MenuRequest.h"
#include "Application/interaction/ContinueState.h"

struct ContinueResult{
    MenuRequest menu_request;
    ContinueStatus status;

};

#endif /* CONTINUE_RESULT */
