#include "Domain/Entities/Cards/InvisibleMan/EmergeFromMist.h"

EmergeFromMist::EmergeFromMist(){
    SetDamageOrDeffend(3);
    SetBoost(2);
    SetName("EmergeFromMist");
    SetCategory(CardCategory::ATTACK);
    SetId(CardId::EMERGE_FROM_MIST);

}
PlayTiming EmergeFromMist::GetCardPlayTiming()const {
    return PlayTiming::DURING_COMBAT;
}
FighterType EmergeFromMist::GetOwner()const {
    return FighterType::INVISIBLEMAN;
}
