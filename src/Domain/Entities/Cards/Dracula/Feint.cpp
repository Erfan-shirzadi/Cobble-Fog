#include "Domain/Entities/Cards/Dracula/Feint.h"
#include "Domain/Combat/CombatContext.h"
#include "Application/interaction/ActionContext.h"
#include "Application/interaction/ContinueResult.h"


#include <iostream>
Feint::Feint(){
    SetDamageOrDeffend(2);
    SetBoost(2);
    SetName("Feint");
    SetCategory(CardCategory::ATTACKANDDEFFENS);

}
void Feint::Play(CombatContext & combatcontext )const {
    std::cout<<"Feint card is playing "<<std::endl;
    combatcontext.Opponent->IsActiveCardEffect=false;
}
PlayTiming Feint::GetCardPlayTiming()const {
    return PlayTiming::IMMEDIATE;
}
FighterType Feint::GetOwner()const {
 return FighterType::ANY;
}

ContinueResult Feint::Continue(ActionContext &){
    
}

