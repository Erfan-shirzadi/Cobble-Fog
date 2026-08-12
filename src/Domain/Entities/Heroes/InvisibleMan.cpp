#include "Domain/Entities/Heroes/InvisibleMan.h"
#include "Domain/Entities/Cards/InvisibleMan/CodedNotes.h"
#include "Domain/Entities/Cards/InvisibleMan/DreamingOfRevenge.h"
#include "Domain/Entities/Cards/InvisibleMan/EmergeFromMist.h"
#include "Domain/Entities/Cards/InvisibleMan/ImpossibleToSee.h"
#include "Domain/Entities/Cards/InvisibleMan/IntoThinAir.h"
#include "Domain/Entities/Cards/InvisibleMan/Lurking.h"
#include "Domain/Entities/Cards/InvisibleMan/ReignOfTerror.h"
#include "Domain/Entities/Cards/InvisibleMan/RollingFog.h"
#include "Domain/Entities/Cards/InvisibleMan/SlipAway.h"
#include "Domain/Entities/Cards/InvisibleMan/StepLightly.h"
#include "Domain/Game/GameState.h"


InvisibleMan::InvisibleMan():Hero("Invisible Man",15,2,FighterType::INVISIBLEMAN){
    // SideKicks.push_back(std::make_unique<Fighter>("Fog",1,0,FighterType::FOG));
    // SideKicks.push_back(std::make_unique<Fighter>("Fog",1,0,FighterType::FOG));
    // SideKicks.push_back(std::make_unique<Fighter>("Fog",1,0,FighterType::FOG));
    fogs.push_back(std::make_unique<Fog>());
    fogs.push_back(std::make_unique<Fog>());
    fogs.push_back(std::make_unique<Fog>());
    this->SetAttack(Attack::MELEE);


    AddCardToDeck(std::make_unique<CodedNotes>());
    AddCardToDeck(std::make_unique<CodedNotes>());

    AddCardToDeck(std::make_unique<DreaminOfRevenge>());
    AddCardToDeck(std::make_unique<DreaminOfRevenge>());

    AddCardToDeck(std::make_unique<EmergeFromMist>());
    AddCardToDeck(std::make_unique<EmergeFromMist>());


    AddCardToDeck(std::make_unique<ImpossibleToSee>());
    AddCardToDeck(std::make_unique<ImpossibleToSee>());

    AddCardToDeck(std::make_unique<IntoThinAir>());
    AddCardToDeck(std::make_unique<IntoThinAir>());

    AddCardToDeck(std::make_unique<Lurking>());
    AddCardToDeck(std::make_unique<Lurking>());

    AddCardToDeck(std::make_unique<ReignOfTerror>());
    AddCardToDeck(std::make_unique<ReignOfTerror>());

    AddCardToDeck(std::make_unique<RollingFog>());
    AddCardToDeck(std::make_unique<RollingFog>());

    AddCardToDeck(std::make_unique<SlipAway>());
    AddCardToDeck(std::make_unique<SlipAway>());
    AddCardToDeck(std::make_unique<SlipAway>());

    
    AddCardToDeck(std::make_unique<StepLightly>());
    AddCardToDeck(std::make_unique<StepLightly>());

    AddCardToDeck(std::make_unique<CodedNotes>());

    AddCardToDeck(std::make_unique<DreaminOfRevenge>());

    AddCardToDeck(std::make_unique<Lurking>());
    AddCardToDeck(std::make_unique<RollingFog>());
    AddCardToDeck(std::make_unique<SlipAway>());
    AddCardToDeck(std::make_unique<IntoThinAir>());



}


std::vector<Fighter *> InvisibleMan::GetSideKicks() {
    std::vector<Fighter *> s;
    return s;
}
Fighter * InvisibleMan::GetDeadSideKick()const {
    return nullptr;
}


 void InvisibleMan::Ability(GameState&){

}
bool InvisibleMan::CanUseCability(GameState){
    return false;
}

std::vector<Fog *> InvisibleMan::GetFogs(){
    std::vector<Fog *>result;
    for(int i{};i<3;i++){
        result.push_back(fogs[i].get());
    }
    return result;
}
