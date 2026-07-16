#include "Domain/Entities/Cards/Dracula/Dash.h"
#include "Domain/Combat/CombatContext.h"
#include "Application/interaction/ActionContext.h"
#include "Application/interaction/ContinueResult.h"


#include <vector>
#include <iostream>

Dash::Dash(){
    SetDamageOrDeffend(3);
    SetBoost(1);
    SetName("Dash");
    SetCategory(CardCategory::ATTACKANDDEFFENS);

}
void Dash::Play(CombatContext & combatcontext )const {
    std::cout<< " Dash card is Playing "<<std::endl;
    Hero * hero=combatcontext.Current->hero;
    Fighter * fighter=combatcontext.Current->fighter;
    Hero * enemy =combatcontext.Opponent->hero;
    std::vector<int> nodes=combatcontext.board->reachableNodes(hero,enemy,3,fighter->GetNode());
    std::cout<< " Show rechable nodes "<<std::endl;
    for(int x{};x<nodes.size();x++){
        std::cout<<x <<".   "<<nodes[x]<<std::endl;
    }
    
    int choice;
    bool flag=true;
    while (flag){
        std::cout <<"Enter: ";
        std::cin >>choice;
        if(choice<0||choice>=nodes.size())
            std:: cout << "Enter Correct plese "<<std::endl;
        else break;
    }
    
    fighter->SetNode(nodes[choice]);
    
}
PlayTiming Dash::GetCardPlayTiming()const {
    return PlayTiming::ATFER_COMBAT;
}
FighterType Dash::GetOwner()const {
    return FighterType::ANY;
}

ContinueResult Dash::Continue(ActionContext &){
    
}