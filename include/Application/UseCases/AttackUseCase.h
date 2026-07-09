#ifndef ATTACK_USECASE
#define ATTACK_USECASE
#include "Domain/Game/GameState.h"
#include "Domain/Combat/CombatContext.h"

class AttackUseCase{
    
    CombatContext context;
    
    public:
    void execute(GameState & );
    void ChooseCardAttaker(GameState &)const;
    bool CanAttack(GameState &)const;
    bool IsInChanceAttack(Fighter * fighter,Hero * ,Board borad)const;
};

#endif /* ATTACK_USECASE */
