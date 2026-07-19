#include "Application/UseCases/DrawingCardUseCase.h"

void DrawingCardUseCase::DrawCard(Hero * hero){
    if(hero->GetDeckSize()==0){
        hero->TakeDamge(2);
        for(auto sidekick:hero->GetSideKicks())
            sidekick->TakeDamge(2);
    }
    else{
        hero->DrawCard();
    }
}
