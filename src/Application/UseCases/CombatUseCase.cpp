#include "Application/UseCases/CombatUseCase.h"
#include <iostream>

using namespace std;
// void CombatUseCase::execute(CombatContext & combatcontext){
//     std::swap(combatcontext.Current,combatcontext.Opponent);
//     if(combatcontext.Current->card)
//         combatcontext.Current->DamageOrDeffend=combatcontext.Current->card->GetDamgeOrDeffend();
//     combatcontext.Opponent->DamageOrDeffend=combatcontext.Opponent->card->GetDamgeOrDeffend();
//     BeforCombat(combatcontext);
//     DuringCombat(combatcontext);
//     AfterCombat(combatcontext);


//     cout<< combatcontext.Current->fighter->GetName()<<"  "<<combatcontext.Current->fighter->GetHP()<<endl;
//     cout<< combatcontext.Opponent->fighter->GetName()<<"  "<<combatcontext.Opponent->fighter->GetHP()<<endl;

//     if(combatcontext.Current->Won){
//         cout<< combatcontext.Current->fighter->GetName()<< " won the combat "<<endl;
//     }
//     else{
//         cout<< combatcontext.Opponent->fighter->GetName()<< " won the combat "<<endl;
//     }
//     cout<< "Combat finished "<<endl;
// }

void CombatUseCase::BeforCombat(CombatContext & combatcontext){
    if(combatcontext.Current->card)
        if(combatcontext.Current->card->GetCardPlayTiming()==PlayTiming::IMMEDIATE){
            if(combatcontext.Current->hero->GetFighterType()==FighterType::SHERLOCK || combatcontext.Current->IsActiveCardEffect)
             combatcontext.Current->card->Play(combatcontext);
        }
    std::swap(combatcontext.Current,combatcontext.Opponent);
    if(combatcontext.Current->card->GetCardPlayTiming()==PlayTiming::IMMEDIATE){
            if(combatcontext.Current->hero->GetFighterType()==FighterType::SHERLOCK || combatcontext.Current->IsActiveCardEffect)
            combatcontext.Current->card->Play(combatcontext);
    }
    std::swap(combatcontext.Current,combatcontext.Opponent);

}

void CombatUseCase::DuringCombat(CombatContext & combatcontext){

    if(combatcontext.Current->card)
        if(combatcontext.Current->card->GetCardPlayTiming()==PlayTiming::DURING_COMBAT){
            if(combatcontext.Current->hero->GetFighterType()==FighterType::SHERLOCK || combatcontext.Current->IsActiveCardEffect)
                combatcontext.Current->card->Play(combatcontext);
        }
    std::swap(combatcontext.Current,combatcontext.Opponent);
    if(combatcontext.Current->card->GetCardPlayTiming()==PlayTiming::DURING_COMBAT){
        if(combatcontext.Current->hero->GetFighterType()==FighterType::SHERLOCK || combatcontext.Current->IsActiveCardEffect)
            combatcontext.Current->card->Play(combatcontext);
    }
    std::swap(combatcontext.Current,combatcontext.Opponent);
     
   int damageAttacker= combatcontext.Opponent->DamageOrDeffend;

   int damageDeffender= combatcontext.Current->DamageOrDeffend;

   int resDamage=damageAttacker-damageDeffender;

   if(resDamage<=0){
    combatcontext.Current->Won=true;
   }else{
    combatcontext.Current->fighter->TakeDamge(resDamage);
    combatcontext.Opponent->Won=true;
   }


}

void CombatUseCase::AfterCombat(CombatContext & combatcontext){
    if(combatcontext.Current->card)
        if(combatcontext.Current->card->GetCardPlayTiming()==PlayTiming::ATFER_COMBAT){
            if(combatcontext.Current->hero->GetFighterType()==FighterType::SHERLOCK || combatcontext.Current->IsActiveCardEffect)
                combatcontext.Current->card->Play(combatcontext);
        }
    std::swap(combatcontext.Current,combatcontext.Opponent);
    if(combatcontext.Current->card->GetCardPlayTiming()==PlayTiming::ATFER_COMBAT){
        if(combatcontext.Current->hero->GetFighterType()==FighterType::SHERLOCK || combatcontext.Current->IsActiveCardEffect)
            combatcontext.Current->card->Play(combatcontext);
    }

}

void CombatUseCase::Finished(CombatContext & combatcontext){

}


ContinueResult CombatUseCase::Continue(CombatContext &){
    switch (step)
    {
    case CombatStep::BEFOR_COMBAT:
        /* code */
        break;
    case CombatStep::DURING_COMBAT:
        /* code */
        break;
    case CombatStep::AFTER_COMBAT:
        /* code */
        break;
    case CombatStep::FINISHED:
        /* code */
        break;
    }
}
