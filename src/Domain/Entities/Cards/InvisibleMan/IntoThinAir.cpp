#include "Domain/Entities/Cards/InvisibleMan/IntoThinAir.h"

IntoThinAir::IntoThinAir(){
    SetDamageOrDeffend(4);
    SetBoost(1);
    SetName("IntoThinAir");
    SetCategory(CardCategory::DEFFENSE);
    SetId(CardId::INTO_THIN_AIR);

}
PlayTiming IntoThinAir::GetCardPlayTiming()const {
    return PlayTiming::ATFER_COMBAT;
}
FighterType IntoThinAir::GetOwner()const {
    return FighterType::INVISIBLEMAN;
}
