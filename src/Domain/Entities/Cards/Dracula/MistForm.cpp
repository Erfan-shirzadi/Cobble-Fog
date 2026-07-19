#include "Domain/Entities/Cards/Dracula/MistForm.h"
#include <iostream>
MistForm::MistForm(){
    SetName("MistForm");
    SetBoost(2);
    SetCategory(CardCategory::SCHEME);
    SetId(CardId::MISTFORM);

}

FighterType MistForm::GetOwner()const{
    return FighterType::DRACULA;
}

