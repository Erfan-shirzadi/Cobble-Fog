#ifndef ATTACK_USECASE
#define ATTACK_USECASE
#include "Domain/Game/GameState.h"
#include "Domain/Combat/CombatContext.h"
#include "Application/UseCases/IUseCase.h"

class AttackUseCase : public IUseCase {
    
    CombatContext context;
    
    public:
    bool execute(GameState & );
    void ChooseCardAttaker();
    bool CanAttack(GameState &)const;
    bool IsInChanceAttack(Fighter * fighter,Hero *enemy ,Board & borad)const;
    void FighterSelection(Hero * , Hero * , Board &  );
    void ChooseCardDeffender();
    void TargetSelection(Hero *);



    ContinueResult Continue(ActionContext&)override;
    void Start(ActionContext&)override;


};

#endif /* ATTACK_USECASE */
