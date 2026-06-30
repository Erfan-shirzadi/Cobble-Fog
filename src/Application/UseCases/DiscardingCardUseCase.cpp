#include "Application/UseCases/DiscardingCardUseCase.h"

void DiscardingCardUseCase::execute(Hero & hero, int cardindex){

    Card card= hero.GetCard(cardindex);
    hero.RemoveCardHand(cardindex);
    int boost=card.GetBoost();
    hero.SetBoost(boost);

}