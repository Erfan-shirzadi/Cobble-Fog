#include "Domain/Entities/Cards/Holmes/MasterOfDisguise.h"
#include <iostream>
MasterOfDisguise::MasterOfDisguise(){
    SetName("MasterOfDisguise");
    SetBoost(2);
    SetCategory(CardCategory::SCHEME);
        SetId(CardId::MASTER_OF_DISGUISE);

}

FighterType MasterOfDisguise::GetOwner()const{
    return FighterType::SHERLOCK;
}
