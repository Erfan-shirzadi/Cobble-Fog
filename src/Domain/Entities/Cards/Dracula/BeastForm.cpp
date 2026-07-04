#include "Domain/Entities/Cards/Dracula/BeastForm.h"
#include "Domain/Combat/CombatContext.h"
#include <iostream>

BestForm::BestForm(){
    SetDamageOrDeffend(6);
    SetBoost(4);
    SetName("BeastForm");
    SetCategory(CardCategory::ATTACK);
}
void BestForm::Play(CombatContext & combatcontext )const {
    Hero * hero=combatcontext.Current->hero;
    std::string command;
    int removedCard=0;
    std::cout<< " Do you want remove card ? (Y/N)"<<std::endl;
    std::cin>>command;
    if(command=="Y"){
        int choose;
        while (command=="Y" && hero->GetSizeHand()>0)
        {
            
            std::cout<< "Show Hand "<<std::endl;
            std::cin>>choose;
            try{
                hero->RemoveCardHand(choose);
                removedCard++;
            }
            catch (std::runtime_error &e){
                std::cout<<e.what()<<std::endl;
            }
        }
    }
    int damage=combatcontext.Current->card->GetDamgeOrDeffend();
    combatcontext.Current->DamageOrDeffend=damage+removedCard;
}
PlayTiming BestForm::GetCardPlayTiming()const {
    return PlayTiming::DURING_COMBAT;
}
FighterType BestForm::GetOwner()const {
    return FighterType::DRACULA;
}
