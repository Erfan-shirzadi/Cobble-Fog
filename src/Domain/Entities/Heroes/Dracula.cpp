#include "Domain/Entities/Heroes/Dracula.h"

Dracula::Dracula():Hero("Dracula",13,2,FighterType::DERACULA){

    this->SideKicks.push_back(std::make_unique<Fighter>("Sister",1,2,FighterType::SISTERS));
    this->SideKicks.push_back(std::make_unique<Fighter>("Sister",1,2,FighterType::SISTERS));
    this->SideKicks.push_back(std::make_unique<Fighter>("Sister",1,2,FighterType::SISTERS));

}