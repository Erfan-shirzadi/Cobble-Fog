#include "Domain/Entities/Cards/Holmes/ServiceRevolver.h"
#include "Application/interaction/ActionContext.h"
#include "Application/interaction/ContinueResult.h"



ServiceRevolver::ServiceRevolver(){

    SetDamageOrDeffend(5);
    SetBoost(3);
    SetName("ServiceRevolver");
    SetCategory(CardCategory::ATTACK);

}
void ServiceRevolver::Play(CombatContext & )const {

}
PlayTiming ServiceRevolver::GetCardPlayTiming()const {
    return PlayTiming::DURING_COMBAT;
}
FighterType ServiceRevolver::GetOwner()const {
    return FighterType::DR_WATSON;
}

ContinueResult ServiceRevolver::Continue(ActionContext &){
    
}