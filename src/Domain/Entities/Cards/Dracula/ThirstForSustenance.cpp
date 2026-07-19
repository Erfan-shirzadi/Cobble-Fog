#include "Domain/Entities/Cards/Dracula/ThirstForSustenance.h"


#include <vector>
#include<iostream>
ThirstForSustenance::ThirstForSustenance(){
    SetDamageOrDeffend(3);
    SetBoost(3);
    SetName("ThirstForSustenance");
    SetCategory(CardCategory::ATTACK);
    SetId(CardId::THIRST_FOR_SUSTENANCE);


}
PlayTiming ThirstForSustenance::GetCardPlayTiming()const {
    return PlayTiming::ATFER_COMBAT;
}
FighterType ThirstForSustenance::GetOwner()const {
    return FighterType::SISTER;
}

