#ifndef EFFECT_CONTEXT
#define EFFECT_CONTEXT
#include "Application/interaction/ActionContext.h"
#include "Application/interaction/Combat/CombatContext.h"
struct EffectContext{
    ActionContext  context;
    CombatContext *combatcontext=nullptr;
};

#endif /* EFFECT_CONTEXT */
