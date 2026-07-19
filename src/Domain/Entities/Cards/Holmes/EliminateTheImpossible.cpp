#include "Domain/Entities/Cards/Holmes/EliminateTheImpossible.h"
#include <vector>
#include <iostream>

EliminateTheImpossible::EliminateTheImpossible(){
    SetName("EliminateTheImpossible");
    SetBoost(2);
    SetCategory(CardCategory::SCHEME);
        SetId(CardId::ELIMINATE_THE_IMPOSSIBLE);

}

FighterType EliminateTheImpossible::GetOwner()const{
    return FighterType::SHERLOCK;
}

