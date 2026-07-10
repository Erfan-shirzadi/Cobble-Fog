#include "Domain/Entities/Cards/Dracula/LookIntoMyEyes.h"
#include "Domain/Combat/CombatContext.h"
#include <iostream>
LookIntoMyEyes::LookIntoMyEyes(){
    SetDamageOrDeffend(1);
    SetBoost(2);
    SetName("LookIntoMyEyes");
    SetCategory(CardCategory::DEFFENSE);


}
void LookIntoMyEyes::Play(CombatContext &  combatcontext)const {
    std::cout<<"LookIntoMyEyes is palying "<<std::endl;
    combatcontext.Current->DamageOrDeffend+=combatcontext.Opponent->card->GetBoost();
}
PlayTiming LookIntoMyEyes::GetCardPlayTiming()const {
    return PlayTiming::DURING_COMBAT;
}
FighterType LookIntoMyEyes::GetOwner()const {
    return FighterType::DRACULA;
}

