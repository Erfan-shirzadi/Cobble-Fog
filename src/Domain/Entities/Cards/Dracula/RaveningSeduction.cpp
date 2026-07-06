#include "Domain/Entities/Cards/Dracula/RaveningSeduction.h"
#include <iostream>

RaveningSeduction::RaveningSeduction(){
    SetName("RaveningSeduction");
    SetBoost(2);
    SetCategory(CardCategory::SCHEME);
}


void RaveningSeduction::Play(Hero * hero ,Hero * enemy, Board * board){
    std::vector<Fighter *> AllFighters=GetAllFighter(hero,enemy);
   

    for(int i{1};i<=AllFighters.size();i++){
        std::cout<<i <<" ."<<AllFighters[i-1]->GetName()<<std::endl;
    }
   
    Fighter * target=SelectFighter(AllFighters);
    std::vector<int> ReachbleNodes=board->reachableNodes(enemy,hero,2,target->GetNode());
    int Nodetarget=SelectNode(ReachbleNodes);
    
    target->SetNode(Nodetarget);
     for( auto fighter: enemy->GetSideKicks()){
            if(fighter->IsAlive()){
                if(board->AreAdjacent(target->GetNode(),fighter->GetNode()))
                    target->TakeDamge(1);
            }
    }
    

    
}
FighterType RaveningSeduction::GetOwner()const{
    return FighterType::SISTER;
}

std::vector<Fighter*> RaveningSeduction::GetAllFighter(Hero * hero, Hero * enemy){
    std::vector<Fighter *> AllFighters;
    AllFighters.push_back(enemy);
    for( auto fighter: enemy->GetSideKicks()){
            if(fighter->IsAlive())
                AllFighters.push_back(fighter);
    }
    for(auto fighter: hero->GetSideKicks()){
            if(fighter->IsAlive())
                AllFighters.push_back(fighter);
    }
    return AllFighters;
}

Fighter * RaveningSeduction::SelectFighter(std::vector<Fighter*> AllFighters){
    int Fighterchoice;
    
    while(true){
        std::cout<< "Select A fihgter :";
        std::cin>> Fighterchoice;
        if(Fighterchoice>=1 &&Fighterchoice<=AllFighters.size())
            break;
        else std::cout<<" enter Correct Please "<<std::endl;
    }
    return AllFighters[Fighterchoice];
}

int RaveningSeduction::SelectNode(std::vector<int> ReachbleNodes){
   int Nodetarget;
    bool flag=true;
    while(true){
        std::cout<< " Select A node :";
        std::cin>>Nodetarget;
        for(int x:ReachbleNodes)
            if(x==Nodetarget)flag=false;

        if(!flag)
            std::cout<< "Enter A correct Number Please "<<std::endl;

    }
    return Nodetarget;
}