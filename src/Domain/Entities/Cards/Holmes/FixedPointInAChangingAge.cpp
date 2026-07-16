#include "Domain/Entities/Cards/Holmes/FixedPointInAChangingAge.h"
#include "Application/interaction/ActionContext.h"
#include "Application/interaction/ContinueResult.h"


#include "Domain/Combat/CombatContext.h"

FixedPointInAChangingAge::FixedPointInAChangingAge(){
    SetDamageOrDeffend(3);
    SetBoost(1);
    SetName("FixedPointInAChangingAge");
    SetCategory(CardCategory::ATTACKANDDEFFENS);

}
void FixedPointInAChangingAge::Play(CombatContext & combatcontext )const {
    int nodeDrwatson=combatcontext.Current->fighter->GetNode();
    int nodeHolmes=combatcontext.Current->hero->GetNode();
    
    if(combatcontext.board->AreAdjacent(nodeDrwatson,nodeHolmes)){
        combatcontext.Current->fighter->Heal(1);
        combatcontext.Current->hero->Heal(1);
    }
}   
PlayTiming FixedPointInAChangingAge::GetCardPlayTiming()const {
 return PlayTiming::ATFER_COMBAT;
}
FighterType FixedPointInAChangingAge::GetOwner()const {
 return FighterType::DR_WATSON;
}

ContinueResult FixedPointInAChangingAge::Continue(ActionContext &){
    
}