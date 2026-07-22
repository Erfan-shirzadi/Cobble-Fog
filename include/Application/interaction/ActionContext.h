#ifndef ACTION_CONTEXT
#define ACTION_CONTEXT
#include "Domain/Entities/Hero.h"
#include "Domain/Entities/Card.h"
#include "Domain/Game/GameState.h"
struct ActionContext{
    GameState * Gamestate;
    int Selected;
};

#endif /* ACTION_CONTEXT */
