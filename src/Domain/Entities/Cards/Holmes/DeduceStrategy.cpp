#include "Domain/Entities/Cards/Holmes/DeduceStrategy.h"
#include "Domain/Combat/CombatContext.h"
#include "Application/interaction/ActionContext.h"
#include "Application/interaction/ContinueResult.h"
#include <iostream>

DeduceStrategy::DeduceStrategy(){
    SetDamageOrDeffend(3);
    SetBoost(1);
    SetName("DeduceStrategy");
    SetCategory(CardCategory::ATTACKANDDEFFENS);

}
void DeduceStrategy::Play(CombatContext & combatcontext )const{
    std::string command;
    std::cout<< " Do you wnat to change amount to Boost ? (Y/N) ";
    std::cin>> command;
    if(command=="Y")
        combatcontext.Opponent->DamageOrDeffend=combatcontext.Opponent->card->GetBoost(); 
}
PlayTiming DeduceStrategy::GetCardPlayTiming()const {
    return PlayTiming::DURING_COMBAT;

}
FighterType DeduceStrategy::GetOwner()const {
    return FighterType::SHERLOCK;
}

ContinueResult DeduceStrategy::Continue(ActionContext &){
    
}