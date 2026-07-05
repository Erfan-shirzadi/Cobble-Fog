#include "Domain/Entities/Cards/Dracula/MistForm.h"
#include <iostream>
void MistForm::Play(Hero * hero,Hero * enemy, Board * board){
    
    std::vector<int> Fullnodes=board->AllFullNodes();
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
