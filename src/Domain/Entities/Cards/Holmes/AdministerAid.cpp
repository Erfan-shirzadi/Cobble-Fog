#include "Domain/Entities/Cards/Holmes/AdministerAid.h"
#include <iostream>
#include <vector>

AdministerAid::AdministerAid(){
    SetName("AdministerAid");
    SetCategory(CardCategory::SCHEME);
    SetBoost(2);
}

void AdministerAid::Play(Hero * hero ,Hero * enemy  , Board * board){
    std::cout<< "Play card Administer aid";
    int nodeHolmes=hero->GetNode();
    std::vector<int> Adjacences=board->GetReachableNighbors(nodeHolmes);
    std::cout<< "Reachable nodes"<<std::endl;
    for(int x: Adjacences){
        std::cout<< x <<"     ";
    }
    if(Adjacences.size()>0){
        int choice;
        bool flag=true;
        while (flag)
        {
            std::cout<< " Enter a Node for move watson ";
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

