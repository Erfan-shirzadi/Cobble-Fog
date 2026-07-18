#include "Domain/Entities/Cards/Dracula/ThirstForSustenance.h"
#include "Domain/Combat/CombatContext.h"
#include "Application/interaction/ActionContext.h"
#include "Application/interaction/ContinueResult.h"


#include <vector>
#include<iostream>
ThirstForSustenance::ThirstForSustenance(){
    SetDamageOrDeffend(3);
    SetBoost(3);
    SetName("ThirstForSustenance");
    SetCategory(CardCategory::ATTACK);
    SetId(CardId::THIRST_FOR_SUSTENANCE);


}
void ThirstForSustenance::Play(CombatContext & combatcontext )const {
    std::cout<< "ThirstForSustenance is palying "<<std::endl;
    if(combatcontext.Current->Won){
        Fighter * fighter=combatcontext.Opponent->fighter;
        std::vector<int> rechablenode=combatcontext.board->GetReachableNighbors(fighter->GetNode());
        int choice;
        for(int i{};i<rechablenode.size();i++){
            std::cout<< i<<".  "<<rechablenode[i]<<std::endl;
        }
        while(true){
            
            std::cin>>choice;
            if(choice<0 ||choice>=rechablenode.size())
                std::cout<< "Enter Correct Please "<<std::endl; 
            else break;
        }
        fighter->SetNode(rechablenode[choice]);
    }

}
PlayTiming ThirstForSustenance::GetCardPlayTiming()const {
    return PlayTiming::ATFER_COMBAT;
}
FighterType ThirstForSustenance::GetOwner()const {
    return FighterType::SISTER;
}

ContinueResult ThirstForSustenance::Continue(ActionContext &){
    
}