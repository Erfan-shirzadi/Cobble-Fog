#include "Domain/Entities/Cards/Holmes/DeduceStrategy.h"
#include "Domain/Combat/CombatContext.h"
#include <iostream>

DeduceStrategy::DeduceStrategy(){
    SetDamageOrDeffend(3);
    SetBoost(1);
    SetName("CounterPunch");
    SetCategory(CardCategory::ATTACKANDDEFFENS);

}
void DeduceStrategy::Play(CombatContext & combatcontext )const{
    std::string command;
    std::cout<< " Do you wnat to change amount to Boost ? (Y/N) ";
    std::cin>> command;
    if(command=="Y")
        combatcontext.Opponent->card->SetDamageOrDeffend(combatcontext.Opponent->card->GetBoost()); 
}
PlayTiming DeduceStrategy::GetCardPlayTiming()const {
    return PlayTiming::DURING_COMBAT;

}
FighterType DeduceStrategy::GetOwner()const {
    return FighterType::SHERLOCK;
}

