#include "Domain/Entities/Cards/Holmes/DeduceStrategy.h"
#include <iostream>

DeduceStrategy::DeduceStrategy(){
    SetDamageOrDeffend(3);
    SetBoost(1);
    SetName("DeduceStrategy");
    SetCategory(CardCategory::ATTACKANDDEFFENS);
        SetId(CardId::DEDUCE_STRATEGY);


}
PlayTiming DeduceStrategy::GetCardPlayTiming()const {
    return PlayTiming::DURING_COMBAT;

}
FighterType DeduceStrategy::GetOwner()const {
    return FighterType::SHERLOCK;
}
