#include "Domain/Entities/Cards/Dracula/ThirstForSustenance.h"
#include "Domain/Combat/CombatContext.h"
#include <vector>
#include<iostream>
ThirstForSustenance::ThirstForSustenance(){
    SetDamageOrDeffend(3);
    SetBoost(3);
    SetName("ThirstForSustenance");
    SetCategory(CardCategory::ATTACK);

}
void ThirstForSustenance::Play(CombatContext & combatcontext )const {
    if(combatcontext.Current->Won){
        Fighter * fighter=combatcontext.Opponent->fighter;
        std::vector<int> rechablenode=combatcontext.board->GetReachableNighbors(fighter->GetNode());
        int choice;
        bool flag=true;
        while(flag){
            std::cout<< " SHow Nodes"<<std::endl;
            std::cin>>choice;
            for(int node:rechablenode)
                if(choice==node)
                    flag=false;
            if(flag)
                std::cout<< "Enter Correct Please "<<std::endl;     
        }
    }
}
PlayTiming ThirstForSustenance::GetCardPlayTiming()const {
    return PlayTiming::ATFER_COMBAT;
}
FighterType ThirstForSustenance::GetOwner()const {
    return FighterType::SISTER;
}

