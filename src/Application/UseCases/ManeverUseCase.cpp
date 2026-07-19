#include "Application/UseCases/ManeverUseCase.h"
#include  <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include "Application/interaction/EffectContext.h"
using namespace std;
void ManeverUseCase::execute(GameState & gamestate){
    Hero * hero=gamestate.currnetPlayer->GetHero(); 
    int movement=hero->GetMove(); 
    if(!gamestate.currnetPlayer->GetHero()->DrawCard()){
        std::vector<Fighter * > sidekicks=hero->GetSideKicks();
        hero->TakeDamge(2);
        for(auto fighter : sidekicks){
            fighter->TakeDamge(2);
        }
    }

    cout<< " Do you want to boost you move ? (Y/N) ";
    string temp;
    cin>> temp;
    if( temp=="Y")movement+=BoostMovement(hero);

    Fighter * Fighter=FighterSelection(hero);
    int nodetarget=GetTargetNode(gamestate,movement,Fighter);
    Fighter->SetNode(nodetarget);


}

int ManeverUseCase::BoostMovement(Hero * hero ){
    std::vector< Card *> cards=hero->GetHand();
    for(auto card: cards){
        cout<< card->GetName()<<" Boost : "<<card->GetBoost()<<endl;
    }
    int choice ;
    while(true){
        cout<<" Enter Number of card :";
        cin>> choice;
        if(choice<0 || choice >= cards.size())   
            cout<<" Enter a correct card  please "<<endl;
        else break;
    }
    Card * card= hero ->GetCard(choice);
    return card->GetBoost();
}

Fighter * ManeverUseCase::FighterSelection(Hero* hero){
    vector<Fighter *> Fighters;
    Fighters.push_back (dynamic_cast<Fighter*>(hero));
    for(auto fighter:hero->GetSideKicks()){
        if(fighter->IsAlive())
            Fighters.push_back(fighter);
    }

    for(auto fighter: Fighters)
        cout<<fighter->GetName()<<endl;

    int choice;
    while(true){
        cout<< " Enter Your Fightre who you want to move : ";
        cin>>choice;
        if(choice<0 || choice>=Fighters.size()){
            cout<< "Please Enter a correct Number "<<endl;
        }
        else break; 
    }

    return Fighters[choice];
}


int ManeverUseCase::GetTargetNode(GameState & gamestate, int movment,Fighter * fighter){
    Hero * hero =gamestate.currnetPlayer->GetHero();
    Hero * enemy=gamestate.opponentPlayre->GetHero();
    vector<int> rechbleNodse=gamestate.board.reachableNodes(hero
    ,enemy,movment,fighter->GetNode());
    cout<<" CUrrent node :"<<fighter->GetNode()<<endl;
        cout<<" rechable nodes :"<<endl;
    
    for(int i{};i<rechbleNodse.size();i++){
        cout<<i << " ."<<rechbleNodse[i]<<endl;
    }
    int choice;
    while(true){
        cout<< "Enter your chice :";
        cin>>choice;
        if(choice<0 || choice>=rechbleNodse.size()){
            cout<< "Please Enter a correct Number "<<endl;
        }
        else break;
    }
    return rechbleNodse[choice];
}

ContinueResult ManeverUseCase::Continue(EffectContext&context){
    
    switch (step)
    {
    case ManeverStep::DRAW_CARD:
        return DrawCard(context);
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

ContinueResult ManeverUseCase::DrawCard(EffectContext & context){
    context.context.Gamestate->currnetPlayer->GetHero()->DrawCard();
    step=ManeverStep::ASK_INCREASE_MOVEMENT;

    ContinueResult res;
    res.status=ContinueStatus::CONTINUE;
    return res;
}
 