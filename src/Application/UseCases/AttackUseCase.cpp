#include "Application/UseCases/AttackUseCase.h"
#include <iostream>
void AttackUseCase::ChooseCardAttaker(GameState & gamestate)const{
    Hero * hero=gamestate.currnetPlayer->GetHero();
    std::cout<< " show hand : "<<std::endl;
    int choose;
    while (true){
        std::cin>>choose;
        Card * cardd=hero->GetCard(choose);
        CombatCard * card=dynamic_cast<CombatCard * > (cardd);
        if(card){
            if(card->GetCategory()==CardCategory::ATTACK ||card->GetCategory()==CardCategory::ATTACKANDDEFFENS){
                this->context.Current->card=cardd;
                break;
            }
            else std::cout<< " Select A Correct card ";
        }
        else std::cout<< " Select A Correct card ";
        
    }
    
}
