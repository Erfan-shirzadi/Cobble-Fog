#include "Domain/Entities/Cards/Dracula/Feint.h"
#include "Domain/Combat/CombatContext.h"

Feint::Feint(){
    SetDamageOrDeffend(2);
    SetBoost(2);
    SetName("Feint");
    SetCategory(CardCategory::ATTACKANDDEFFENS);

}
void Feint::Play(CombatContext & combatcontext )const {
    combatcontext.Opponent->IsActiveCardEffect=false;
}
PlayTiming Feint::GetCardPlayTiming()const {
    return PlayTiming::IMMEDIATE;
}
FighterType Feint::GetOwner()const {
 return FighterType::ANY;
}

