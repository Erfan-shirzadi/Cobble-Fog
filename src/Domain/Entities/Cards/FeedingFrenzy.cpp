#include "Domain/Entities/Cards/FeedingFrenzy.h"
#include <vector>
FeedingFrenzy::FeedingFrenzy(){
    SetDamageOrDeffend(2);
    SetBoost(3);
    SetName("FeedingFrenzy");
    AddCategory(CardCategory::ATTACK);
}

void FeedingFrenzy::Play(CombatContext &  combatcontext)const{

    Hero * hero =combatcontext.Current->hero;
    Fighter * enemy=combatcontext.Opponent->fighter;
    std::vector<Fighter*> sisters=hero->GetSideKicks();
    int increaseDamage=0;
    for(Fighter * sidekick: sisters)
        if(combatcontext.board.IsAnArea(sidekick->GetNode(),enemy->GetNode()));
            increaseDamage++;
    
    combatcontext.Current->DamageOrDeffend+=increaseDamage;
}

PlayTiming FeedingFrenzy::GetCardPlayTiming()const{
    return PlayTiming::DURING_COMBAT;
}
FighterType FeedingFrenzy::GetOwner()const{
    return FighterType::DRACULA;
}
