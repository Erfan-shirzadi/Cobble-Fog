#include "Domain/Entities/Cards/Dracula/Dash.h"


#include <vector>
#include <iostream>

Dash::Dash(){
    SetDamageOrDeffend(3);
    SetBoost(1);
    SetName("Dash");
    SetCategory(CardCategory::ATTACKANDDEFFENS);
    SetId(CardId::DASH);

}

PlayTiming Dash::GetCardPlayTiming()const {
    return PlayTiming::ATFER_COMBAT;
}
FighterType Dash::GetOwner()const {
    return FighterType::ANY;
}

