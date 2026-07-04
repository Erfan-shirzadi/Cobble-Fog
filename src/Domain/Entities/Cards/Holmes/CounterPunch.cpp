#include "Domain/Entities/Cards/Holmes/CounterPunch.h"
#include "Domain/Combat/CombatContext.h"

CounterPunch::CounterPunch(){
    SetDamageOrDeffend(3);
    SetBoost(1);
    SetName("CounterPunch");
    SetCategory(CardCategory::ATTACKANDDEFFENS);

}
void CounterPunch::Play(CombatContext & combatcontext)const {
    int nodeHolmes=combatcontext.Current->hero->GetNode();
    int nodeFighter=combatcontext.Opponent->fighter->GetNode();
    if(combatcontext.board->AreAdjacent(nodeHolmes,nodeFighter)){
        combatcontext.Opponent->fighter->TakeDamge(2);
    }
}
PlayTiming CounterPunch::GetCardPlayTiming()const {
    return PlayTiming::ATFER_COMBAT;    
}
FighterType CounterPunch::GetOwner()const {
    return FighterType::SHERLOCK;
}

