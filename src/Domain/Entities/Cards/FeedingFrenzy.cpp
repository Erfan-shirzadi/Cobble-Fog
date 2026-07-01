#include "Domain/Entities/Cards/FeedingFrenzy.h"

FeedingFrenzy::FeedingFrenzy(){
    SetName("Feeding Frenzy");
    SetBoost(3);
    AddCategory(CardCategory::ATTACK);
    SetDamageOrDeffend(2);

}
int FeedingFrenzy::Play(Dracula * attacker,Fighter * deffender,Graph map){
    
    int enemynode=deffender->GetNode();
    std::vector<Area> areas=map.GetArea(enemynode);
    int increaseDamage=0;

    for(int i{1};i<=3;i++){
        Fighter * sidekicks=attacker->GetSideKicks(i);
        int node=sidekicks->GetNode();
        for(Area sidekicksArea:map.GetArea(node))
            for(Area area:areas){
                if(area==sidekicksArea)
                    increaseDamage++;
            }   
    }

    return increaseDamage + this->GetDamgeOrDeffend();    

    
}
PlayTiming FeedingFrenzy::GetCardPlayTiming()const{
    return PlayTiming::DURING_COMBAT;
}

FighterType FeedingFrenzy::GetOwner()const {
    return FighterType::DRACULA;
}
