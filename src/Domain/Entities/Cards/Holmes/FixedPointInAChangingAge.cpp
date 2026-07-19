#include "Domain/Entities/Cards/Holmes/FixedPointInAChangingAge.h"
#include "Application/interaction/ActionContext.h"
#include "Application/interaction/ContinueResult.h"

FixedPointInAChangingAge::FixedPointInAChangingAge(){
    SetDamageOrDeffend(3);
    SetBoost(1);
    SetName("FixedPointInAChangingAge");
    SetCategory(CardCategory::ATTACKANDDEFFENS);
        SetId(CardId::FIXED_POINT_IN_A_CHANGING_AGE);


}
PlayTiming FixedPointInAChangingAge::GetCardPlayTiming()const {
 return PlayTiming::ATFER_COMBAT;
}
FighterType FixedPointInAChangingAge::GetOwner()const {
 return FighterType::DR_WATSON;
}
