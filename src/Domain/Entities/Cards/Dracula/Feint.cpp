#include "Domain/Entities/Cards/Dracula/Feint.h"


#include <iostream>
Feint::Feint(){
    SetDamageOrDeffend(2);
    SetBoost(2);
    SetName("Feint");
    SetCategory(CardCategory::ATTACKANDDEFFENS);
    SetId(CardId::FEINT);
}

PlayTiming Feint::GetCardPlayTiming()const {
    return PlayTiming::IMMEDIATE;
}
FighterType Feint::GetOwner()const {
 return FighterType::ANY;
}


