#include  <vector>
#include <unordered_map>
#include <queue>
#include "Application/UseCases/ManeverUseCase.h"
#include "Application/interaction/EffectContext.h"
#include "Application/UseCases/DrawingCardUseCase.h"
#include "Application/UseCases/MoveUseCase.h"
using namespace std;




ContinueResult ManeverUseCase::Continue(EffectContext&context){
    
    switch (step)
    {
    case ManeverStep::DRAW_CARD:
        return drawcard(context);
        break;
    case ManeverStep::ASK_INCREASE_MOVEMENT:
        return AskIncreseMovment(context);
        break;
    case ManeverStep::CHOOSE_CARD:
        return ChooseCard(context);
        break;
    case ManeverStep::CHOOSE_FIHGTER:
        return CooseFighter(context);
        break;
    case ManeverStep::CHOOSE_DESTINATION:
        return ChooseDestination(context);
        break;
    case ManeverStep::MOVE:
        return Move(context);
        break;    
    case ManeverStep::FINISHED:
        return Finished(context);
        break;
    default:{
        ContinueResult res;
        res.status=ContinueStatus::FINISHED;
        return res;

    }
    }
}



ContinueResult ManeverUseCase::AskIncreseMovment(EffectContext & context){

    if(context.context.Selected==-1)return BuildAskIncreaseMovmentMenu();

    int choice=context.context.Selected;
    context.context.Selected=-1;

    if(choice==0)this->step=ManeverStep::CHOOSE_CARD;
    else if(choice==1)step=ManeverStep::CHOOSE_FIHGTER;
    else if(choice==2)step=ManeverStep::FINISHED;

    return Continue(context);
}
ContinueResult ManeverUseCase::ChooseCard(EffectContext&context){

    if(context.context.Selected==-1)return BuildCardChoosingMunu(context);

    int choice=context.context.Selected;
    context.context.Selected=-1;

    Card * card=context.context.Gamestate->currnetPlayer->GetHero()->GetCard(choice);
    this->incresemovment+=card->GetBoost();
    InceaseMovment(context.context.Gamestate->currnetPlayer->GetHero(),incresemovment);
    
    this->step=ManeverStep::ASK_INCREASE_MOVEMENT;

    return Continue(context);

}
ContinueResult ManeverUseCase::CooseFighter(EffectContext&context){
   if(context.context.Selected==-1)return BuildFightersMenu(context);

    int choice=context.context.Selected;
    context.context.Selected=-1;
   
    // DrawingCardUseCase::DrawCard(context.context.Gamestate->currnetPlayer->GetHero(),context.context.Gamestate->log);

    this->selectedHero=fighters[choice];

    this->step=ManeverStep::CHOOSE_DESTINATION;
    return Continue(context);

}
ContinueResult ManeverUseCase::ChooseDestination(EffectContext& context){

    if(context.context.Selected==-1)return BuildNodesMenu(context);

    int choice =context.context.Selected;
    context.context.Selected=-1;
    Destination=this->rechableNode[choice];
    context.context.Gamestate->log.Add(std::to_string(context.context.Gamestate->board.Distance(selectedHero->GetNode(),Destination))+"Distance");
    selectedHero->ReduceMove(context.context.Gamestate->board.Distance(selectedHero->GetNode(),Destination));
    this->step=ManeverStep::MOVE;
    return Continue(context);
}
ContinueResult ManeverUseCase::Move(EffectContext& context){
    MoveUseCase::Move(selectedHero,Destination,context.context.Gamestate->log);

    if(CanMoveAnyFighter())
        step=ManeverStep::ASK_INCREASE_MOVEMENT;
    else step=ManeverStep::FINISHED;
    return Continue(context);
}
ContinueResult ManeverUseCase::Finished(EffectContext& context){
    ResetMovment(context.context.Gamestate->currnetPlayer->GetHero());
    context.context.Selected=-1;
    this->incresemovment=0;
    this->rechableNode.clear();
    this->fighters.clear();
    selectedHero=nullptr;
    Destination=-1;
    
    ContinueResult result;
    result.status=ContinueStatus::FINISHED;
    return result;
}




ContinueResult ManeverUseCase::BuildAskIncreaseMovmentMenu(){
    ContinueResult result;
    result.menu_request.title="Increse Movment ?";
    result.menu_request.options.push_back("Increse Movment");
    result.menu_request.options.push_back("Continue");
    result.menu_request.options.push_back("End Turn");
    result.status=ContinueStatus::NEEDMENU;
    result.menu_request.type=InputType::QUESTION;

    return result;
}

ContinueResult ManeverUseCase::BuildCardChoosingMunu(EffectContext&context){
    ContinueResult result;
    result.status=ContinueStatus::NEEDMENU;
    for(auto card: context.context.Gamestate->currnetPlayer->GetHero()->GetHand()){
        result.menu_request.cards.push_back(card->GetCardId());
    }
    result.menu_request.title="Hand Card";
    result.menu_request.type=InputType::CARD;
    return result;
}

ContinueResult  ManeverUseCase::BuildFightersMenu(EffectContext& context){
    fighters.clear();
    ContinueResult result;
    Hero * hero=context.context.Gamestate->currnetPlayer->GetHero();
    if(hero->GetMove()>0)
        fighters.push_back(dynamic_cast<Fighter*>(hero));
    for(auto sidekick: hero->GetSideKicks()){
        if(sidekick->GetMove()>0)
            fighters.push_back(sidekick);
    }
   
    for(auto fighter:fighters){
        
        result.menu_request.nodes.push_back(fighter->GetNode());
      
    }
    result.menu_request.title="Fighters";
    result.status=ContinueStatus::NEEDMENU;
    result.menu_request.type=InputType::NODE;
    return result;
 }

ContinueResult ManeverUseCase::BuildNodesMenu(EffectContext& context){
    ContinueResult result;
    Board & board=context.context.Gamestate->board;
    rechableNode=board.reachableNodes(
         context.context.Gamestate->currnetPlayer->GetHero(),
        context.context.Gamestate->opponentPlayre->GetHero(),
        selectedHero->GetMove(),
        selectedHero->GetNode()
    );
    for(int node:rechableNode ){
        result.menu_request.nodes.push_back(node);
    }
    result.menu_request.title="Destination";
    result.status=ContinueStatus::NEEDMENU;
    result.menu_request.type=InputType::NODE;
    return result;
}

void ManeverUseCase::Start(EffectContext & context ){
    context.context.Selected=-1;
    this->step=ManeverStep::DRAW_CARD;
    selectedHero=nullptr;
    Destination=-1;
    rechableNode.clear();
    fighters.clear();
}

ContinueResult ManeverUseCase::drawcard(EffectContext & context){
    Hero *hero=context.context.Gamestate->currnetPlayer->GetHero();
    step=ManeverStep::ASK_INCREASE_MOVEMENT;
    DrawingCardUseCase::DrawCard(hero,context.context.Gamestate->log);
    ContinueResult res;
    res.status=ContinueStatus::CONTINUE;
    return res;
}
 
void ManeverUseCase::ResetMovment(Hero * hero){
    hero->SetMove(2);

    for(auto sidekick:hero->GetSideKicks()){
        sidekick->SetMove(2);
    }
}

void ManeverUseCase::InceaseMovment(Hero * hero,int amount){
    hero->SetMove(amount+hero->GetMove());

    for(auto sidekick:hero->GetSideKicks()){
        sidekick->SetMove(amount+sidekick->GetMove());
    }
}

bool ManeverUseCase::CanMoveAnyFighter(){
    for(auto fighter:this->fighters){
        if(fighter->GetMove()>0)return true;
    }
    return false;
}


std::vector<Fighter*> ManeverUseCase::GetFighters(){
    return this->fighters;
}
ManeverStep ManeverUseCase::GetStep(){
    return this->step;
}
std::vector<int> ManeverUseCase::GetRechbleNodes(){
    return this->rechableNode;
}
Fighter * ManeverUseCase::SelectedFighter(){
    return this->selectedHero;
}

void ManeverUseCase::SetStep(ManeverStep step){
    this->step=step;
}

void ManeverUseCase::SetSelectedFighter(Fighter* fighter){
    this->selectedHero=fighter;
}
