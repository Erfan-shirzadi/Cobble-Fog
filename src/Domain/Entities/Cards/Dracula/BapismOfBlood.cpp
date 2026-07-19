#include "Domain/Entities/Cards/Dracula/BapismOfBlood.h"
 #include <iostream>

BapismOfBlood::BapismOfBlood(){
    SetName("BapismOfBlood");
    SetBoost(2);
    SetCategory(CardCategory::SCHEME);
    SetId(CardId::BAPISM_OF_BLOOD);

}


FighterType BapismOfBlood::GetOwner()const{
    return FighterType::DRACULA;
}

