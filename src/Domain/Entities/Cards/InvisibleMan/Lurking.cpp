#include "Domain/Entities/Cards/InvisibleMan/Lurking.h"
Lurking::Lurking(){
    SetDamageOrDeffend(2);
    SetBoost(2);
    SetName("Lurking");
    SetCategory(CardCategory::DEFFENSE);
    SetId(CardId::LURKING);

}
PlayTiming Lurking::GetCardPlayTiming()const {
    return PlayTiming::ATFER_COMBAT;
}
FighterType Lurking::GetOwner()const {
    return FighterType::INVISIBLEMAN;
}
