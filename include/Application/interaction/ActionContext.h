#ifndef ACTION_CONTEXT
#define ACTION_CONTEXT
#include "Domain/Entities/Hero.h"
#include "Domain/Entities/Card.h"
#include "Domain/Game/GameState.h"
struct ActionContext{
    GameState * Gamestate;
    Hero * currentHero;
    Hero * opponentHero;
    Fighter * fighter;

    int SelectedNode;
};

#endif /* ACTION_CONTEXT */
