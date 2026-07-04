#include "Domain/Entities/Cards/Dracula/Ambush.h"
#include "Domain/Combat/CombatContext.h"

Ambush::Ambush(){
    SetDamageOrDeffend(2);
    SetBoost(3);
    SetName("Ambush");
    SetCategory(CardCategory::ATTACK);

}
void Ambush::Play(CombatContext & combatcontext )const {


    Card* card=combatcontext.Opponent->hero->GetRandomCardOfHand();
    int boostCard=card->GetBoost();
    int DamageCardCurrentFighter=combatcontext.Current->card->GetDamgeOrDeffend();
    combatcontext.Current->DamageOrDeffend=boostCard+DamageCardCurrentFighter;

}
PlayTiming Ambush::GetCardPlayTiming()const {
    return PlayTiming::DURING_COMBAT;
}
FighterType Ambush::GetOwner()const {
    return FighterType::ANY;
}
