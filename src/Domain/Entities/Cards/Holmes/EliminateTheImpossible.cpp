#include "Domain/Entities/Cards/Holmes/EliminateTheImpossible.h"
#include <vector>
#include <iostream>

EliminateTheImpossible::EliminateTheImpossible(){
    SetName("EliminateTheImpossible");
    SetBoost(2);
    SetCategory(CardCategory::SCHEME);
}

void EliminateTheImpossible::Play(Hero * hero,Hero * enemy , Board * board){
    std::cout<< "Eliminate The Impossible card is Playing "<<std::endl;
    std::vector<Card *> cards=enemy->GetHand();
    for( int i{ };i<cards.size();i++)
        std::cout<<i<<" ." <<cards[i]->GetName()<<std::endl;

    int choice;
    while(true){
        std::cout<< "Select Card "<<std::endl;
        std::cin>>choice;

        try{
            enemy->RemoveCardHand(choice);
            break;
        }
        catch (std::runtime_error &e){
            std::cout<< e.what();
        }
    }
}
FighterType EliminateTheImpossible::GetOwner()const{
    return FighterType::SHERLOCK;
}

