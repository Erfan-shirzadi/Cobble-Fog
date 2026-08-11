#include "Domain/Entities/Cards/InvisibleMan/SlipAway.h"

SlipAway::SlipAway(){
    SetDamageOrDeffend(3);
    SetBoost(2);
    SetName("SlipAway");
    SetCategory(CardCategory::ATTACK);
    SetId(CardId::SLIP_AWAY);

}
PlayTiming SlipAway::GetCardPlayTiming()const {
    return PlayTiming::ATFER_COMBAT;
}
FighterType SlipAway::GetOwner()const {
    return FighterType::INVISIBLEMAN;
}
