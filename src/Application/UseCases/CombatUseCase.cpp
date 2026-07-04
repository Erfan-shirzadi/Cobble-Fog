#include "Application/UseCases/CombatUseCase.h"

void CombatUseCase::execute(CombatContext & combatcontext){
    std::swap(combatcontext.Current,combatcontext.Opponent);
    BeforCombat(combatcontext);
    DuringCombat(combatcontext);
    AfterCombat(combatcontext);
    
}

void CombatUseCase::BeforCombat(CombatContext & combatcontext){

    if(combatcontext.Current->card)
        if(combatcontext.Current->card->GetCardPlayTiming()==PlayTiming::IMMEDIATE){
            combatcontext.Current->card->Play(combatcontext);
        }
    std::swap(combatcontext.Current,combatcontext.Opponent);
    if(combatcontext.Current->card->GetCardPlayTiming()==PlayTiming::IMMEDIATE){
        combatcontext.Current->card->Play(combatcontext);
    }
    std::swap(combatcontext.Current,combatcontext.Opponent);

}

void CombatUseCase::DuringCombat(CombatContext & combatcontext){
    if(combatcontext.Current->card)
        if(combatcontext.Current->card->GetCardPlayTiming()==PlayTiming::DURING_COMBAT){
            combatcontext.Current->card->Play(combatcontext);
        }
    std::swap(combatcontext.Current,combatcontext.Opponent);
    if(combatcontext.Current->card->GetCardPlayTiming()==PlayTiming::DURING_COMBAT){
        combatcontext.Current->card->Play(combatcontext);
    }
    std::swap(combatcontext.Current,combatcontext.Opponent);
     
   int damageAttacker= combatcontext.Current->DamageOrDeffend;
   int damageDeffender= combatcontext.Opponent->DamageOrDeffend;

   int resDamage=damageAttacker-damageDeffender;

//    if(resDamage<=0)
//     combatcontext.result=CombatResult::WON_DEFFENDER;
//     else {
//         combatcontext.result=CombatResult::WON_DEFFENDER;
//         combatcontext.Opponent->fighter->TakeDamge(resDamage);
//     }


}

void CombatUseCase::AfterCombat(CombatContext & combatcontext){
    if(combatcontext.Current->card)
        if(combatcontext.Current->card->GetCardPlayTiming()==PlayTiming::ATFER_COMBAT){
            combatcontext.Current->card->Play(combatcontext);
        }
    std::swap(combatcontext.Current,combatcontext.Opponent);
    if(combatcontext.Current->card->GetCardPlayTiming()==PlayTiming::ATFER_COMBAT){
        combatcontext.Current->card->Play(combatcontext);
    }

}

void CombatUseCase::Finished(CombatContext & combatcontext){

}
