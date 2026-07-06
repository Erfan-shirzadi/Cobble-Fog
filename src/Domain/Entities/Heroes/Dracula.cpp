#include "Domain/Entities/Heroes/Dracula.h"
#include "Domain/Entities/Cards/Dracula/Ambush.h"
#include "Domain/Entities/Cards/Dracula/BapismOfBlood.h"
#include "Domain/Entities/Cards/Dracula/BeastForm.h"
#include "Domain/Entities/Cards/Dracula/Dash.h"
#include "Domain/Entities/Cards/Dracula/Exploit.h"
#include "Domain/Entities/Cards/Dracula/FeedingFrenzy.h"
#include "Domain/Entities/Cards/Dracula/Feint.h"
#include "Domain/Entities/Cards/Dracula/LookIntoMyEyes.h"
#include "Domain/Entities/Cards/Dracula/MistForm.h"
#include "Domain/Entities/Cards/Dracula/PeryUpon.h"
#include "Domain/Entities/Cards/Dracula/RaveningSeduction.h"
#include "Domain/Entities/Cards/Dracula/ThirstForSustenance.h"

Dracula::Dracula():Hero("Dracula",13,2,FighterType::DRACULA){

    this->SideKicks.push_back(std::make_unique<Fighter>("Sister",1,2,FighterType::SISTER));
    this->SideKicks.push_back(std::make_unique<Fighter>("Sister",1,2,FighterType::SISTER));
    this->SideKicks.push_back(std::make_unique<Fighter>("Sister",1,2,FighterType::SISTER));

    AddCardToDeck(std::make_unique<Ambush>(),2);
    AddCardToDeck(std::make_unique<BapismOfBlood>(),2);
    AddCardToDeck(std::make_unique<BestForm>(),2);
    AddCardToDeck(std::make_unique<Dash>(),3);
    AddCardToDeck(std::make_unique<Exploit>(),3);
    AddCardToDeck(std::make_unique<FeedingFrenzy>(),2);
    AddCardToDeck(std::make_unique<Feint>(),3);
    AddCardToDeck(std::make_unique<LookIntoMyEyes>(),3);
    AddCardToDeck(std::make_unique<MistForm>(),2);
    AddCardToDeck(std::make_unique<PeryUpon>(),2);
    AddCardToDeck(std::make_unique<RaveningSeduction>(),3);
    AddCardToDeck(std::make_unique<ThirstForSustenance>(),3);
}

std::vector<Fighter *> Dracula::GetSideKicks(){
    std::vector<Fighter*> sidekicks{};
    for(int i{};i<3;i++)
        if(SideKicks[i].get()->IsAlive())
            sidekicks.push_back(SideKicks[i].get());

    return sidekicks;
}
