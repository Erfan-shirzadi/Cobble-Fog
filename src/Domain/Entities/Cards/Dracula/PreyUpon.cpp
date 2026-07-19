#include "Domain/Entities/Cards/Dracula/PeryUpon.h"
 #include <vector>
 #include <iostream>

PeryUpon::PeryUpon(){
    SetName("PeryUpon");
    SetBoost(4);
    SetCategory(CardCategory::SCHEME);
    SetId(CardId::PERYUPON);

}
FighterType PeryUpon::GetOwner()const{
    return FighterType::DRACULA;
}

