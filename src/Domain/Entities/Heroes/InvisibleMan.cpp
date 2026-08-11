#include "Domain/Entities/Heroes/InvisibleMan.h"

InvisibleMan::InvisibleMan():Hero("Invisible Man",15,2,FighterType::INVISIBLEMAN){
    SideKicks.push_back(std::make_unique<Fighter>("Fog",1,0,FighterType::FOG));
    SideKicks.push_back(std::make_unique<Fighter>("Fog",1,0,FighterType::FOG));
    SideKicks.push_back(std::make_unique<Fighter>("Fog",1,0,FighterType::FOG));
    

}

std::vector<Fighter *> InvisibleMan::GetSideKicks(){

}
