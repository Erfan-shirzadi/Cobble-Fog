#include "Domain/Entities/Cards/Dracula/Dash.h"
#include "Domain/Combat/CombatContext.h"
#include <vector>
#include <iostream>

Dash::Dash(){
    SetDamageOrDeffend(3);
    SetBoost(1);
    SetName("Dash");
    SetCategory(CardCategory::ATTACKANDDEFFENS);

}
void Dash::Play(CombatContext & combatcontext )const {

    Hero * hero=combatcontext.Current->hero;
    Fighter * fighter=combatcontext.Current->fighter;
    Hero * enemy =combatcontext.Opponent->hero;
    std::vector<int> nodes=combatcontext.board->reachableNodes(hero,enemy,3,fighter->GetNode());
    std::cout<< " Show rechable nodes "<<std::endl;
    int choice;
    while (true){
        std::cout <<"Enter: ";
        std::cin >>choice;
        for(int node: nodes)
            if(node==choice)
                break;
        std:: cout << "Enter Correct plese "<<std::endl;
    }
    fighter->SetNode(choice);
    
}
PlayTiming Dash::GetCardPlayTiming()const {
    return PlayTiming::ATFER_COMBAT;
}
FighterType Dash::GetOwner()const {
    return FighterType::ANY;
}
