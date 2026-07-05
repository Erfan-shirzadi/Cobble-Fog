#include "Domain/Entities/Cards/Dracula/PeryUpon.h"
 #include <vector>
void PeryUpon::Play(Hero *hero ,Hero * enemy , Board * board){
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

    int nodeHero=hero->GetNode();
    for(auto fighter:AllFighters){
        if(board->AreAdjacent(nodeHero,fighter->GetNode())){
            fighter->TakeDamge(1);
            hero->Heal(1);
        }
    }
    
}
FighterType PeryUpon::GetOwner()const{
    return FighterType::DRACULA;
}

