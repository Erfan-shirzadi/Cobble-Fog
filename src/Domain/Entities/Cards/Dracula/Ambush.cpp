#include "Domain/Entities/Cards/Dracula/Ambush.h"
#include "Domain/Combat/CombatContext.h"
#include <cstdlib>
Ambush::Ambush(){
    SetDamageOrDeffend(2);
    SetBoost(3);
    SetName("Ambush");
    SetCategory(CardCategory::ATTACK);

}
void Ambush::Play(CombatContext & combatcontext )const {

    int randomindex=rand()%combatcontext.Opponent->hero->GetSizeHand();
    Card * card=combatcontext.Opponent->hero->GetCard(randomindex);
    int boostCard=card->GetBoost();
    combatcontext.Opponent->hero->RemoveCardHand(randomindex);
    int DamageCardCurrentFighter=combatcontext.Current->card->GetDamgeOrDeffend();
    combatcontext.Current->DamageOrDeffend=boostCard+DamageCardCurrentFighter;

}
PlayTiming Ambush::GetCardPlayTiming()const {
    return PlayTiming::DURING_COMBAT;
}
FighterType Ambush::GetOwner()const {
    return FighterType::ANY;
}
