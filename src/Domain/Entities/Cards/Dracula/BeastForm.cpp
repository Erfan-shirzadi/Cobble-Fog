#include "Domain/Entities/Cards/Dracula/BeastForm.h"
#include <iostream>

BestForm::BestForm(){
    SetDamageOrDeffend(6);
    SetBoost(4);
    SetName("BeastForm");
    SetCategory(CardCategory::ATTACK);
    SetId(CardId::BEASTFORM);

}
PlayTiming BestForm::GetCardPlayTiming()const {
    return PlayTiming::DURING_COMBAT;
}
FighterType BestForm::GetOwner()const {
    return FighterType::DRACULA;
}

