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
#include "Domain/Game/GameState.h"
#include <iostream>
Dracula::Dracula():Hero("Dracula",13,2,FighterType::DRACULA){

    this->SideKicks.push_back(std::make_unique<Fighter>("Sister",1,2,FighterType::SISTER_1));
    this->SideKicks.push_back(std::make_unique<Fighter>("Sister",1,2,FighterType::SISTER_2));
    this->SideKicks.push_back(std::make_unique<Fighter>("Sister",1,2,FighterType::SISTER_3));
    SideKicks[0]->SetAttack(Attack::MELEE);
    SideKicks[1]->SetAttack(Attack::MELEE);
    SideKicks[2]->SetAttack(Attack::MELEE);
    this->SetAttack(Attack::MELEE);

    AddCardToDeck(std::make_unique<Ambush>());
    AddCardToDeck(std::make_unique<Ambush>());

    AddCardToDeck(std::make_unique<BapismOfBlood>());
    AddCardToDeck(std::make_unique<BapismOfBlood>());

    AddCardToDeck(std::make_unique<BestForm>());
    AddCardToDeck(std::make_unique<BestForm>());

    AddCardToDeck(std::make_unique<Dash>());
    AddCardToDeck(std::make_unique<Dash>());
    AddCardToDeck(std::make_unique<Dash>());

    AddCardToDeck(std::make_unique<Exploit>());
    AddCardToDeck(std::make_unique<Exploit>());
    AddCardToDeck(std::make_unique<Exploit>());

    AddCardToDeck(std::make_unique<FeedingFrenzy>());
    AddCardToDeck(std::make_unique<FeedingFrenzy>());

    AddCardToDeck(std::make_unique<Feint>());
    AddCardToDeck(std::make_unique<Feint>());
    AddCardToDeck(std::make_unique<Feint>());

    AddCardToDeck(std::make_unique<LookIntoMyEyes>());
    AddCardToDeck(std::make_unique<LookIntoMyEyes>());
    AddCardToDeck(std::make_unique<LookIntoMyEyes>());

    AddCardToDeck(std::make_unique<MistForm>());
    AddCardToDeck(std::make_unique<MistForm>());

    AddCardToDeck(std::make_unique<PeryUpon>());
    AddCardToDeck(std::make_unique<PeryUpon>());

    AddCardToDeck(std::make_unique<RaveningSeduction>());
    AddCardToDeck(std::make_unique<RaveningSeduction>());
    AddCardToDeck(std::make_unique<RaveningSeduction>());

    AddCardToDeck(std::make_unique<ThirstForSustenance>());
    AddCardToDeck(std::make_unique<ThirstForSustenance>());
    AddCardToDeck(std::make_unique<ThirstForSustenance>());

   






}

std::vector<Fighter *> Dracula::GetSideKicks(){
    std::vector<Fighter*> sidekicks{};
    for(int i{};i<3;i++)
        if(SideKicks[i].get()->IsAlive())
            sidekicks.push_back(SideKicks[i].get());

    return sidekicks;
}

bool Dracula::IsAliveAnySideKick(){
    for(int i{};i<3;i++)
        if(this->SideKicks[i].get()->IsAlive())
            return true;

    return false;
};

void Dracula::Ability(GameState& gamestate){
    Board board=gamestate.board;
    std::vector<Fighter* > fighters;
    for(auto fighter: this->GetSideKicks()){
        if(board.AreAdjacent(fighter->GetNode(),this->GetNode()))fighters.push_back(fighter);
    }
    for(auto fighter:gamestate.opponentPlayre->GetHero()->GetSideKicks()){
        if(board.AreAdjacent(fighter->GetNode(),this->GetNode()))fighters.push_back(fighter);
    }
    Hero* enemy=gamestate.opponentPlayre->GetHero();
        if(board.AreAdjacent(enemy->GetNode(),this->GetNode())
         && !(board.GetNodeType(enemy->GetNode())==NodeType::SECREST && board.GetNodeType(enemy->GetNode())==NodeType::SECREST))
            fighters.push_back(dynamic_cast<Fighter* > (gamestate.opponentPlayre->GetHero()));

    int choice;
    for(int i{};i<fighters.size();i++){
        std::cout<< i << fighters[i]->GetName()<<std::endl;
    }

    while (true)
    {
        std::cin>>choice;
        if(choice<0 || choice>=fighters.size())
            std::cout<<" Enter A correct NUmber Please "<<std::endl;
        else break;
        
    }
    
    fighters[choice]->TakeDamge(1);
    this->DrawCard();



}

bool Dracula::CanUseCability(GameState GameState){
    Board board=GameState.board;
    for(auto fighter: this->GetSideKicks()){
        if(board.AreAdjacent(fighter->GetNode(),this->GetNode()))
            return true;
    }
    for(auto fighter: GameState.opponentPlayre->GetHero()->GetSideKicks()){
        if(board.AreAdjacent(fighter->GetNode(),this->GetNode()))
            return true;
    }
    if(board.AreAdjacent(GameState.opponentPlayre->GetHero()->GetNode(),this->GetNode()))
        return true;

    return false;
}


Fighter * Dracula::GetDeadSideKick()const {
  for(int i{};i<3;i++){
    if(!this->SideKicks[i]->IsAlive())
        return SideKicks[i].get();
  }
  return nullptr;
}
