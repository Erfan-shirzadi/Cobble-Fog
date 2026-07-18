#include "Domain/Entities/Cards/Dracula/Ambush.h"
#include "Domain/Combat/CombatContext.h"
#include "Application/interaction/ActionContext.h"
#include "Application/interaction/ContinueResult.h"


#include <cstdlib>
#include <iostream>
Ambush::Ambush(){
    SetDamageOrDeffend(2);
    SetBoost(3);
    SetName("Ambush");
    SetCategory(CardCategory::ATTACK);
    SetId(CardId::AMBUSH);


}
void Ambush::Play(CombatContext & combatcontext )const {
    std::cout<< "Ambush card is playing  "<<std::endl;
    int randomindex=rand()%combatcontext.Opponent->hero->GetSizeHand();
    Card * card=combatcontext.Opponent->hero->GetCard(randomindex);
    int boostCard=card->GetBoost();

    
    combatcontext.Opponent->hero->RemoveCardHand(randomindex);



    combatcontext.Current->DamageOrDeffend+=boostCard;

}
PlayTiming Ambush::GetCardPlayTiming()const {
    return PlayTiming::DURING_COMBAT;
}
FighterType Ambush::GetOwner()const {
    return FighterType::ANY;
}

ContinueResult Ambush::Continue(ActionContext &){
    
}