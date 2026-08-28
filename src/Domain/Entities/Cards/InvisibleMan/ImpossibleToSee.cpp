#include "Domain/Entities/Cards/InvisibleMan/ImpossibleToSee.h"

ImpossibleToSee::ImpossibleToSee(){
    SetDamageOrDeffend(2);
    SetBoost(2);
    SetName("ImpossibleToSee");
    SetCategory(CardCategory::ATTACKANDDEFFENS);
    SetId(CardId::IMPOSSIBLE_TO_SEE);

}
PlayTiming ImpossibleToSee::GetCardPlayTiming()const {
    return PlayTiming::IMMEDIATE;
}
FighterType ImpossibleToSee::GetOwner()const {
    return FighterType::INVISIBLEMAN;
}
