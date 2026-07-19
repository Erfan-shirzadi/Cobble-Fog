#include "Domain/Entities/Cards/Dracula/Ambush.h"
#include <cstdlib>
#include <iostream>
Ambush::Ambush(){
    SetDamageOrDeffend(2);
    SetBoost(3);
    SetName("Ambush");
    SetCategory(CardCategory::ATTACK);
    SetId(CardId::AMBUSH);


}

PlayTiming Ambush::GetCardPlayTiming()const {
    return PlayTiming::DURING_COMBAT;
}
FighterType Ambush::GetOwner()const {
    return FighterType::ANY;
}

