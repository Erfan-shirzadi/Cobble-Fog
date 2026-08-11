#include "Domain/Entities/Cards/InvisibleMan/RollingFog.h"

RollingFog::RollingFog(){
    SetBoost(1);
    SetName("RollingFog");
    SetCategory(CardCategory::SCHEME);
    SetId(CardId::ROLLING_FOG);

}
FighterType RollingFog::GetOwner()const{
    return FighterType::INVISIBLEMAN;
}
