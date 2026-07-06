#include "Domain/Entities/Cards/Dracula/BapismOfBlood.h"
 #include <iostream>

BapismOfBlood::BapismOfBlood(){
    SetName("BapismOfBlood");
    SetBoost(2);
    SetCategory(CardCategory::SCHEME);
}

void BapismOfBlood::Play(Hero * hero,Hero * enemy , Board *  board){

    hero->Heal(2);
    bool Recovered=false;
    for(auto fighter:hero->GetSideKicks()){
        if(!fighter->IsAlive() && Recovered==false){
            fighter->Heal(1);
            int choice;
            while (true)
            {
                std::cout<<" Select A node :";
                std::cin>>choice;
                if(board->IsAnArea(hero->GetNode(),choice) && (!board->isOccupied(choice))){
                    fighter->SetNode(choice);
                    Recovered=true;
                    break;
                }
            }
            
        }
    }

}
FighterType BapismOfBlood::GetOwner()const{
    return FighterType::DRACULA;
}

