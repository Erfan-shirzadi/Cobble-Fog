#include "Domain/Entities/Cards/Holmes/MasterOfDisguise.h"
#include <iostream>
MasterOfDisguise::MasterOfDisguise(){
    SetName("MasterOfDisguise");
    SetBoost(2);
    SetCategory(CardCategory::SCHEME);
}

void MasterOfDisguise::Play(Hero * hero ,Hero * enemy , Board * board){
    std::cout<< " Master Of Disguise card is Playing "<<std::endl;
    hero->SetNode(enemy->GetNode());
    enemy->SetNode(hero->GetNode());
    enemy->TakeDamge(1);

}
FighterType MasterOfDisguise::GetOwner()const{
    return FighterType::SHERLOCK;
}

