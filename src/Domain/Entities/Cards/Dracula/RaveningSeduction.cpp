#include "Domain/Entities/Cards/Dracula/RaveningSeduction.h"

#include <iostream>

RaveningSeduction::RaveningSeduction(){
    SetName("RaveningSeduction");
    SetBoost(2);
    SetCategory(CardCategory::SCHEME);
    SetId(CardId::RAVENING_SEDUCTION);

}

FighterType RaveningSeduction::GetOwner()const{
    return FighterType::SISTER;
}
