#include "Domain/Entities/Heroes/Dracula.h"
Dracula::Dracula():Hero("Dracula",13,2,FighterType::DRACULA){

    this->SideKicks.push_back(std::make_unique<Fighter>("Sister",1,2,FighterType::SISTERS));
    this->SideKicks.push_back(std::make_unique<Fighter>("Sister",1,2,FighterType::SISTERS));
    this->SideKicks.push_back(std::make_unique<Fighter>("Sister",1,2,FighterType::SISTERS));

}

std::vector<Fighter *> Dracula::GetSideKicks(){
    std::vector<Fighter*> sidekicks{};
    for(int i{};i<3;i++)
        if(SideKicks[i].get()->IsAlive())
            sidekicks.push_back(SideKicks[i].get());

    return sidekicks;
}
