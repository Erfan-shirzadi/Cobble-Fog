#include "Domain/Entities/Cards/Dracula/LookIntoMyEyes.h"


#include <iostream>
LookIntoMyEyes::LookIntoMyEyes(){
    SetDamageOrDeffend(1);
    SetBoost(2);
    SetName("LookIntoMyEyes");
    SetCategory(CardCategory::DEFFENSE);
    SetId(CardId::LOOK_INTO_MY_EYES);


}
PlayTiming LookIntoMyEyes::GetCardPlayTiming()const {
    return PlayTiming::DURING_COMBAT;
}
FighterType LookIntoMyEyes::GetOwner()const {
    return FighterType::DRACULA;
}
