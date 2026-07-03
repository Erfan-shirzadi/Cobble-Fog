#include "Domain/Entities/Cards/FeedingFrenzy.h"
#include <vector>
#include "Domain/Combat/CombatContext.h"
#include <iostream>
FeedingFrenzy::FeedingFrenzy(){
    SetDamageOrDeffend(2);
    SetBoost(3);
    SetName("FeedingFrenzy");
    SetCategory(CardCategory::ATTACK);
}

void FeedingFrenzy::Play(CombatContext &  combatcontext)const{

    Hero * hero =combatcontext.Current->hero;
    Fighter * enemy=combatcontext.Opponent->fighter;
    std::vector<Fighter*> sisters=hero->GetSideKicks();
    int increaseDamage=0;
    for(Fighter * sidekick: sisters){
        if(combatcontext.board->IsAnArea(sidekick->GetNode(),enemy->GetNode()));
            increaseDamage++;
    }
    std::cout << increaseDamage;
    
    combatcontext.Current->DamageOrDeffend=increaseDamage+this->GetDamgeOrDeffend();
}

PlayTiming FeedingFrenzy::GetCardPlayTiming()const{
    return PlayTiming::DURING_COMBAT;
}
FighterType FeedingFrenzy::GetOwner()const{
    return FighterType::DRACULA;
}
