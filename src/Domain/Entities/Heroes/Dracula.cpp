#include "Domain/Entities/Heroes/Dracula.h"

Dracula::Dracula():Hero("Dracula",13,2,FighterType::DRACULA){

    this->SideKicks.push_back(std::make_unique<Fighter>("Sister",1,2,FighterType::SISTERS));
    this->SideKicks.push_back(std::make_unique<Fighter>("Sister",1,2,FighterType::SISTERS));
    this->SideKicks.push_back(std::make_unique<Fighter>("Sister",1,2,FighterType::SISTERS));

}

Fighter * Dracula::GetSideKicks(int index)const{
    
    return this->SideKicks[index-1].get();
}
