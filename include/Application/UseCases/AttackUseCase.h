#ifndef ATTACK_USECASE
#define ATTACK_USECASE
#include "Domain/Game/GameState.h"
#include "Domain/Combat/CombatContext.h"
#include "Application/UseCases/IUseCase.h"
#include "Application/UseCases/CombatUseCase.h"

enum class AttackStep{
    SETUP,
    COMBAT,
    FINISHED
};

enum class SetUpStep{
    CHOOSE_ATTACKER,
    CHOOSE_ATTACKER_CARD,
    CHOOSE_DEFFENDER,
    CHOOSE_DEFFENDER_CARD
};
class AttackUseCase : public IUseCase {
    
    CombatContext combatcontext;
    CombatUseCase combat;

    SetUpStep setupstep;
    AttackStep attackstep;

    std::vector<Fighter*> Attacker;

    
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
    ContinueResult SetUp(ActionContext&);
    ContinueResult Finished(ActionContext&);
    ContinueResult Combat(ActionContext&);


    ContinueResult BuildAttakerMenu(ActionContext &);
    ContinueResult ChooseAttaker(ActionContext & );
    
};

#endif /* ATTACK_USECASE */
