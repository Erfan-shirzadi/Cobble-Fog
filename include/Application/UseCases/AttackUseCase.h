#ifndef ATTACK_USECASE
#define ATTACK_USECASE
#include "Domain/Game/GameState.h"
#include "Domain/Combat/CombatContext.h"

class AttackUseCase{
    
    CombatContext context;
    
    public:
    bool execute(GameState & );
    void ChooseCardAttaker();
    bool CanAttack(GameState &)const;
    bool IsInChanceAttack(Fighter * fighter,Hero *enemy ,Board & borad)const;
    void FighterSelection(Hero * , Hero * , Board &  );
    void ChooseCardDeffender();
    void TargetSelection(Hero *);
};

#endif /* ATTACK_USECASE */
