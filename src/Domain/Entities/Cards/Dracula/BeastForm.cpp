#include "Domain/Entities/Cards/Dracula/BeastForm.h"
#include "Domain/Combat/CombatContext.h"
#include "Application/interaction/ActionContext.h"
#include "Application/interaction/ContinueResult.h"


#include <iostream>

BestForm::BestForm(){
    SetDamageOrDeffend(6);
    SetBoost(4);
    SetName("BeastForm");
    SetCategory(CardCategory::ATTACK);
    SetId(CardId::BEASTFORM);

}
void BestForm::Play(CombatContext & combatcontext )const {
    std::cout<< " Beast Form card iS playing "<<std::endl;
    Hero * hero=combatcontext.Current->hero;
    std::string command;
    int removedCard=0;
    std::cout<< " Do you want remove card ? (Y/N)"<<std::endl;
    std::cin>>command;
    if(command=="Y"){
        int choose;
        while (command=="Y" && hero->GetSizeHand()>0)
        {
            
            std::cout<< hero->GetHandCards()<<std::endl;
            std::cin>>choose;
            try{
                hero->RemoveCardHand(choose);
                removedCard++;
            }
            catch (std::runtime_error &e){
                std::cout<<e.what()<<std::endl;
            }
            if(hero->GetSizeHand()>0){
            std::cout<<" DO you want continue ? (Y/N)";
            std::cin>>command;
            }
        }
    }
    combatcontext.Current->DamageOrDeffend+=removedCard;
}
PlayTiming BestForm::GetCardPlayTiming()const {
    return PlayTiming::DURING_COMBAT;
}
FighterType BestForm::GetOwner()const {
    return FighterType::DRACULA;
}

ContinueResult BestForm::Continue(ActionContext &){
    
}