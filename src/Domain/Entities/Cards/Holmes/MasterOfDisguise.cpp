#include "Domain/Entities/Cards/Holmes/MasterOfDisguise.h"

MasterOfDisguise::MasterOfDisguise(){
    SetName("MasterOfDisguise");
    SetBoost(2);
    SetCategory(CardCategory::SCHEME);
}

void MasterOfDisguise::Play(Hero * hero ,Hero * enemy , Board * board){
    hero->SetNode(enemy->GetNode());
    enemy->SetNode(hero->GetNode());
    enemy->TakeDamge(1);

}
FighterType MasterOfDisguise::GetOwner()const{
    return FighterType::SHERLOCK;
}

