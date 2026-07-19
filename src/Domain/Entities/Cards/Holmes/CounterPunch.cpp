#include "Domain/Entities/Cards/Holmes/CounterPunch.h"
CounterPunch::CounterPunch(){
    SetDamageOrDeffend(3);
    SetBoost(1);
    SetName("CounterPunch");
    SetCategory(CardCategory::ATTACKANDDEFFENS);
    SetId(CardId::COUNTER_PUNCH);


}

PlayTiming CounterPunch::GetCardPlayTiming()const {
    return PlayTiming::ATFER_COMBAT;    
}
FighterType CounterPunch::GetOwner()const {
    return FighterType::SHERLOCK;
}
