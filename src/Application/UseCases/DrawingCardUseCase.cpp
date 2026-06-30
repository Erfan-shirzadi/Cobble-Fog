#include "Application/UseCases/DrawingCardUseCase.h"

void DrawingCardUseCase::execute(Hero & hero){
    Card card=hero.GetRandomCard();
    hero.AddCardToHand(card);
}
