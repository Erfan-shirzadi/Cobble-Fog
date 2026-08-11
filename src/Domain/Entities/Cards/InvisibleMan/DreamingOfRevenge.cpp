#include "Domain/Entities/Cards/InvisibleMan/DreamingOfRevenge.h"

DreaminOfRevenge::DreaminOfRevenge(){

    SetDamageOrDeffend(3);
    SetBoost(1);
    SetName("DreaminOfRevenge");
    SetCategory(CardCategory::ATTACKANDDEFFENS);
    SetId(CardId::DREAMIN_OF_REVENGE);


}
PlayTiming DreaminOfRevenge::GetCardPlayTiming()const {
    return PlayTiming::ATFER_COMBAT;
}
FighterType DreaminOfRevenge::GetOwner()const {
    return FighterType::INVISIBLEMAN;
}
