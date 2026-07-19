#ifndef ATTACK_USECASE
#define ATTACK_USECASE
#include "Domain/Game/GameState.h"
#include "Application/UseCases/IUseCase.h"
#include "Application/interaction/Combat/CombatContext.h"
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
    ASK_FOR_DEFFEND,
    CHOOSE_DEFFENDER_CARD,
};
class AttackUseCase : public IUseCase {
    
    CombatContext combatcontext;
    CombatUseCase combat;

    SetUpStep setupstep;
    AttackStep attackstep;

    std::vector<Fighter*> Attacker;
    std::vector<Card*> AttackerCards;
    std::vector<Card*> DeffenderCards;

    std::vector<Fighter*> enemiescanAttack;

    
    public:
    bool CanAttack(GameState &)const;
    bool IsInChanceAttack(Fighter * fighter,Hero *enemy ,Board & borad)const;
    void GetFighterCanAttackIt(Board & board);
    void FighterSelection(Hero * , Hero * , Board &  );
    void ChooseCardDeffender();
    void TargetSelection(Hero *);



    ContinueResult Continue(EffectContext&)override;
    void Start(EffectContext&)override;
    ContinueResult SetUp(EffectContext&);
    ContinueResult Finished(EffectContext&);
    ContinueResult Combat(EffectContext&);

    ContinueResult ChooseAttaker(EffectContext & );
    ContinueResult ChooseAttckerCard(EffectContext & );
    ContinueResult ChooseDeffender(EffectContext &);
    ContinueResult ChooseDeffenderCard(EffectContext &);
    ContinueResult AskForDeffend(EffectContext &);


    ContinueResult BuildAttakerMenu(EffectContext &);
    ContinueResult BuildAttackerCardMenu(EffectContext & );
    ContinueResult BuildDeffenderMenu(EffectContext &);
    ContinueResult BuildDeffenerCardMenu(EffectContext&);
    ContinueResult BuildAskDeffendMenu();
    void SetDeffenderCards();
    bool CanDeffendDffender();
    
};

#endif /* ATTACK_USECASE */
