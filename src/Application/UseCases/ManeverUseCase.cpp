#include "Application/UseCases/ManeverUseCase.h"
#include  <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
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
    else step=ManeverStep::CHOOSE_FIHGTER;

    return Continue(context);
}
ContinueResult ManeverUseCase::ChooseCard(EffectContext&context){

    if(context.context.Selected==-1)return BuildCardChoosingMunu(context);

    int choice=context.context.Selected;
    context.context.Selected=-1;

    Card * card=context.context.Gamestate->currnetPlayer->GetHero()->GetCard(choice);
    this->IncreseMovment+=card->GetBoost();
    this->step=ManeverStep::ASK_INCREASE_MOVEMENT;

    return Continue(context);

}
ContinueResult ManeverUseCase::CooseFighter(EffectContext&context){
   if(context.context.Selected==-1)return BuildFightersMenu(context);

   int choice=context.context.Selected;
   context.context.Selected=-1;
    DrawingCardUseCase::DrawCard(context.context.Gamestate->currnetPlayer->GetHero(),context.context.Gamestate->log);

   this->selectedHero=fighters[choice];

   selectedHero->SetMove(this->IncreseMovment+selectedHero->GetMove());
   this->step=ManeverStep::CHOOSE_DESTINATION;
   return Continue(context);

}
ContinueResult ManeverUseCase::ChooseDestination(EffectContext& context){

    if(context.context.Selected==-1)return BuildNodesMenu(context);

    int choice =context.context.Selected;
    context.context.Selected=-1;
    Destination=this->rechableNode[choice];

    this->step=ManeverStep::MOVE;
    return Continue(context);
}
ContinueResult ManeverUseCase::Move(EffectContext& context){
    selectedHero->SetNode(Destination);
    MoveUseCase::Move(selectedHero,Destination,context.context.Gamestate->log);
    step=ManeverStep::FINISHED;
    return Continue(context);
}
ContinueResult ManeverUseCase::Finished(EffectContext& context){
    selectedHero->SetMove(2);
    context.context.Selected=-1;
    this->IncreseMovment=0;
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
    result.status=ContinueStatus::NEEDMENU;

    return result;
}

ContinueResult ManeverUseCase::BuildCardChoosingMunu(EffectContext&context){
    ContinueResult result;
    result.status=ContinueStatus::NEEDMENU;
    for(auto card: context.context.Gamestate->currnetPlayer->GetHero()->GetHand()){
        result.menu_request.options.push_back(card->GetName());
    }
    result.menu_request.title="Hand Card";

    return result;
}

ContinueResult  ManeverUseCase::BuildFightersMenu(EffectContext& context){
    ContinueResult result;
    Hero * hero=context.context.Gamestate->currnetPlayer->GetHero();
    fighters.push_back(dynamic_cast<Fighter*>(hero));
    result.menu_request.options.push_back(hero->GetName()+" ("+std::to_string(hero->GetNode())+" ) ");
    for(auto sidekick: hero->GetSideKicks()){
        fighters.push_back(sidekick);
        result.menu_request.options.push_back(sidekick->GetName()+" ("+std::to_string(sidekick->GetNode())+" ) ");
    }
    result.menu_request.title="Fighters";
    result.status=ContinueStatus::NEEDMENU;
    return result;
 }

ContinueResult ManeverUseCase::BuildNodesMenu(EffectContext& context){
    ContinueResult result;
    rechableNode=context.context.Gamestate->board.reachableNodes(
         context.context.Gamestate->currnetPlayer->GetHero(),
        context.context.Gamestate->opponentPlayre->GetHero(),
        selectedHero->GetMove(),
        selectedHero->GetNode()
    );
    for(int node:rechableNode ){
        result.menu_request.options.push_back(std::to_string(node));
    }
    result.menu_request.title="Destination";
    result.status=ContinueStatus::NEEDMENU;
    return result;
}

void ManeverUseCase::Start(EffectContext & context ){
    context.context.Selected=-1;
    this->step=ManeverStep::ASK_INCREASE_MOVEMENT;
    selectedHero=nullptr;
    Destination=-1;
    rechableNode.clear();
    fighters.clear();
}

ContinueResult ManeverUseCase::drawcard(EffectContext & context){
    Hero *hero=context.context.Gamestate->currnetPlayer->GetHero();
    // hero->DrawCard();
    step=ManeverStep::ASK_INCREASE_MOVEMENT;
    // DrawingCardUseCase::DrawCard(hero,context.context.Gamestate->log);
    ContinueResult res;
    res.status=ContinueStatus::CONTINUE;
    return res;
}
 