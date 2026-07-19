#include "Domain/Entities/Cards/Holmes/TheGameIsAfoot.h"
TheGameIsAfoot::TheGameIsAfoot(){

    SetDamageOrDeffend(5);
    SetBoost(2);
    SetName("TheGameIsAfoot");
    SetCategory(CardCategory::ATTACK);
    SetId(CardId::THE_GAME_IS_AFOOT);


}

PlayTiming TheGameIsAfoot::GetCardPlayTiming()const {
    return PlayTiming::ATFER_COMBAT;
}
FighterType TheGameIsAfoot::GetOwner()const {
 return FighterType::SHERLOCK;
}   
