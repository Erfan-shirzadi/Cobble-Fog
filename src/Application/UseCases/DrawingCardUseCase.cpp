#include "Application/UseCases/DrawingCardUseCase.h"
#include "Domain/Game/GameLog.h"
void DrawingCardUseCase::DrawCard(Hero * hero,GameLog&log){
    if(hero->GetDeckSize()==0){
        hero->TakeDamge(2);
        for(auto sidekick:hero->GetSideKicks()){
            sidekick->TakeDamge(2);
            log.Add("Damage 2"+sidekick->GetName() );
        }
        log.Add("Damage 2 "+hero->GetName() );

    }
    else{
        log.Add("Drawed A card form "+hero->GetName() );
        hero->DrawCard();
    }
}
