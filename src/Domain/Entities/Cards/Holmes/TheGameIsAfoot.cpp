#include "Domain/Entities/Cards/Holmes/TheGameIsAfoot.h"
#include "Domain/Combat/CombatContext.h"
#include "Application/interaction/ActionContext.h"
#include "Application/interaction/ContinueResult.h"


#include <iostream>
TheGameIsAfoot::TheGameIsAfoot(){

    SetDamageOrDeffend(5);
    SetBoost(2);
    SetName("TheGameIsAfoot");
    SetCategory(CardCategory::ATTACK);


}
void TheGameIsAfoot::Play(CombatContext & combatcontext)const {
    Hero * hero=combatcontext.Current->hero;
    Hero * enemy =combatcontext.Opponent->hero;
    std::vector<int> nodes=combatcontext.board->reachableNodes(hero,enemy,3,hero->GetNode());
    std::cout<< " Show rechable nodes "<<std::endl;
    int choice;
    bool flag=true;
    while (flag){
        std::cout <<"Enter: ";
        std::cin >>choice;
        for(int node: nodes)
            if(node==choice)
                flag=false;
        if(flag)
            std:: cout << "Enter Correct plese "<<std::endl;
    }
    hero->SetNode(choice);

}
PlayTiming TheGameIsAfoot::GetCardPlayTiming()const {
    return PlayTiming::ATFER_COMBAT;
}
FighterType TheGameIsAfoot::GetOwner()const {
 return FighterType::SHERLOCK;
}   

ContinueResult TheGameIsAfoot::Continue(ActionContext &){
    
}