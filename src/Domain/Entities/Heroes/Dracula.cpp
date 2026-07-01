#include "Domain/Entities/Heroes/Dracula.h"

Dracula::Dracula():Hero("Dracula",13,2,FighterType::DERACULA){

    this->SideKicks.push_back(std::make_unique<Fighter>("Sister",1,2,FighterType::SISTERS));
    this->SideKicks.push_back(std::make_unique<Fighter>("Sister",1,2,FighterType::SISTERS));
    this->SideKicks.push_back(std::make_unique<Fighter>("Sister",1,2,FighterType::SISTERS));

}

Fighter * Dracula::GetSideKick(int node){
    for(int i{};i<3;i++){
        if(this->SideKicks[i].get()->GetNode()==node)
            return SideKicks[i].get();
    }
    return nullptr;
}
