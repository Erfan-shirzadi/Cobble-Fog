#include "Domain/Entities/Cards/Dracula/FeedingFrenzy.h"
#include "Domain/Entities/Cards/CardId.h"

#include <vector>
#include <iostream>
FeedingFrenzy::FeedingFrenzy(){
    SetDamageOrDeffend(2);
    SetBoost(3);
    SetName("FeedingFrenzy");
    SetCategory(CardCategory::ATTACK);
    SetId(CardId::FEEDINGFRENZY);

}

PlayTiming FeedingFrenzy::GetCardPlayTiming()const{
    return PlayTiming::DURING_COMBAT;
}
FighterType FeedingFrenzy::GetOwner()const{
    return FighterType::DRACULA;
}
