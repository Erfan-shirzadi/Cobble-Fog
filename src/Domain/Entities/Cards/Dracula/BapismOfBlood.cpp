#include "Domain/Entities/Cards/Dracula/BapismOfBlood.h"
#include "Application/interaction/ActionContext.h"
#include "Application/interaction/ContinueResult.h"


 #include <iostream>

BapismOfBlood::BapismOfBlood(){
    SetName("BapismOfBlood");
    SetBoost(2);
    SetCategory(CardCategory::SCHEME);
    SetId(CardId::BAPISM_OF_BLOOD);

}

void BapismOfBlood::Play(Hero * hero,Hero * enemy , Board *  board){
    std::cout<< " Bapism of blood is playing "<<std::endl;
    hero->Heal(2);
    bool Recovered=false;
        if(hero->GetDeadSideKick()){
            Fighter* fighter=hero->GetDeadSideKick();
            fighter->Heal(1);
            std::vector<int> rechableNodes=board->GetNodeofArea(hero->GetNode());
            for(int i{ };i<rechableNodes.size();i++){
                std::cout<<i << ".  "<<rechableNodes[i]<<std::endl;
            }
            int choice;
            while (true)
            {
                std::cout<<" Select A node :";
                std::cin>>choice;
                if(!(choice<0 || choice>=rechableNodes.size())){
                    fighter->SetNode(rechableNodes[choice]);
                    break;
                }else{
                    std::cout<< " Enter correct please"<<std::endl;
                }
                
            }
            
        }
    

}
FighterType BapismOfBlood::GetOwner()const{
    return FighterType::DRACULA;
}

ContinueResult BapismOfBlood::Continue(ActionContext &){
    
}