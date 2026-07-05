#include "Domain/Entities/Cards/Holmes/AdministerAid.h"
#include <iostream>
#include <vector>
void AdministerAid::Play(Hero * hero ,Hero * enemy  , Board * board){
    int nodeHolmes=hero->GetNode();
    std::vector<int> Adjacences=board->GetReachableNighbors(nodeHolmes);
    
    if(Adjacences.size()>0){
        int choice;
        bool flag=true;
        while (flag)
        {
            std::cin>>choice;
            for(int node: Adjacences)
                if(node==choice)
                    flag=false;
            if(!flag)
                std::cout<< "Enter A correct Please "<<std::endl;
        }
    std::vector<Fighter*> sidekicks=hero->GetSideKicks();
    sidekicks[0]->SetNode(choice);
    }
    hero->Heal(1);
    hero->DrawCard();



    
}

FighterType AdministerAid::GetOwner()const{
    return FighterType::DR_WATSON;
}

