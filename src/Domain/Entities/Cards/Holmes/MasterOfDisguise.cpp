#include "Domain/Entities/Cards/Holmes/MasterOfDisguise.h"
#include "Application/interaction/ActionContext.h"
#include "Application/interaction/ContinueResult.h"


#include <iostream>
MasterOfDisguise::MasterOfDisguise(){
    SetName("MasterOfDisguise");
    SetBoost(2);
    SetCategory(CardCategory::SCHEME);
        SetId(CardId::MASTER_OF_DISGUISE);

}

void MasterOfDisguise::Play(Hero * hero ,Hero * enemy , Board * board){
    std::cout<< " Master Of Disguise card is Playing "<<std::endl;
    int enemynode=enemy->GetNode();
    int heronode=hero->GetNode();
    hero->SetNode(enemynode);
    enemy->SetNode(heronode);
    enemy->TakeDamge(1);

}
FighterType MasterOfDisguise::GetOwner()const{
    return FighterType::SHERLOCK;
}

ContinueResult MasterOfDisguise::Continue(ActionContext &){
    
}