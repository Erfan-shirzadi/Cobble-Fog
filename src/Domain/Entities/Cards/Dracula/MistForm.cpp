#include "Domain/Entities/Cards/Dracula/MistForm.h"
#include <iostream>
MistForm::MistForm(){
    SetName("MistForm");
    SetBoost(2);
    SetCategory(CardCategory::SCHEME);
}

void MistForm::Play(Hero * hero,Hero * enemy, Board * board){
    std::cout<<"Mist form card is playing "<<std::endl;
    std::vector<int> Fullnodes=board->AllFullNodes();
    std::cout<< " Nodes that can not go :"<<std::endl;
    for(int x: Fullnodes){
        std::cout<< x<<std::endl;
    }
    int choice;
    bool flag=true;
    while(flag){
        flag=false;
        std::cout<< "Select :";
        std::cin>>choice;
        for(int x:Fullnodes )
            if(choice==x){
                std::cout<<" here is Fighter Please Select Again ";
                flag=true;
            }
    }
    hero->SetNode(choice);

}
FighterType MistForm::GetOwner()const{
    return FighterType::DRACULA;
}
