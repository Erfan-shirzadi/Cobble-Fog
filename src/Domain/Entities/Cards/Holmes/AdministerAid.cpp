#include "Domain/Entities/Cards/Holmes/AdministerAid.h"
#include <iostream>
#include <vector>

AdministerAid::AdministerAid(){
    SetName("AdministerAid");
    SetCategory(CardCategory::SCHEME);
    SetBoost(2);
    SetId(CardId::ADMINISTER_AID);
}


FighterType AdministerAid::GetOwner()const{
    return FighterType::DR_WATSON;
}
