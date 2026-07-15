#include "Domain/Entities/Cards/Holmes/AdministerAid.h"
#include <iostream>
#include <vector>

AdministerAid::AdministerAid(){
    SetName("AdministerAid");
    SetCategory(CardCategory::SCHEME);
    SetBoost(2);
}

void AdministerAid::Play(Hero * hero ,Hero * enemy  , Board * board){
    std::cout<< "Play card Administer aid";
    int nodeHolmes=hero->GetNode();
    std::vector<int> Adjacences=board->GetReachableNighbors(nodeHolmes);
    std::cout<< "Reachable nodes"<<std::endl;
    for(int x: Adjacences){
        std::cout<< x <<"     ";
    }
    if(Adjacences.size()>0){
        int choice;
        bool flag=true;
        while (flag)
        {
            std::cout<< " Enter a Node for move watson ";
            std::cin>>choice;
            for(int node: Adjacences)
                if(node==choice)
                    flag=false;
            if(!flag)
                std::cout<< "Enter A correct Please "<<std::endl;
        }
    std::vector<Fighter*> sidekicks=hero->GetSideKicks();
    sidekicks[0]->SetNode(choice);
    }
    hero->Heal(1);
    if(hero->DrawCard()){
        for(auto fighter: hero->GetSideKicks())
            fighter->TakeDamge(2);
        hero->TakeDamge(2);
    }
    




    
}

FighterType AdministerAid::GetOwner()const{
    return FighterType::DR_WATSON;
}


ContinueResult AdministerAid::Continue(ActionContext & actioncontext ){

    switch (this->step)
    {
    case 0:
       this->step=1;
       return RequestNodeSelection(actioncontext);
        break;
    
    case 1:
        return MoveWatson(actioncontext);
        break;
    case 2:
        return HealHolmes(actioncontext);
        break;
    case 3:
        return DrawCard(actioncontext);
        break;
    case 4:{
        ContinueResult a;
        a.status=ContinueStatus::FINISHED;

        return  a;
        }
    }
}

ContinueResult AdministerAid::RequestNodeSelection(ActionContext & act){
    Hero * holmes=act.Gamestate->currnetPlayer->GetHero();
    Board board=act.Gamestate->board;
    this->RechableNodes=board.GetReachableNighbors(holmes->GetNode());

    ContinueResult result;
    result.menu_request.title="Choose Watson Desination";

    for(int x:this->RechableNodes){
        result.menu_request.options.push_back(std::to_string(x));
    }

    return result;
    

}


ContinueResult AdministerAid::MoveWatson(ActionContext & context){

    Hero * holmes=context.Gamestate->currnetPlayer->GetHero();
    std::vector<Fighter* > watson=holmes->GetSideKicks();
    int indexNode=context.SelectedNode;

    watson[0]->SetNode(this->RechableNodes[indexNode]);
    this->step=2;

    return Continue(context);
}

ContinueResult AdministerAid::HealHolmes(ActionContext &context){
    Hero * holmes=context.Gamestate->currnetPlayer->GetHero();
    holmes->Heal(1);
    this->step=3;
    return Continue(context);
}

ContinueResult AdministerAid::DrawCard(ActionContext & context){
    Hero * holmes=context.Gamestate->currnetPlayer->GetHero();
    if(!holmes->DrawCard()){
        for(auto fighter:holmes->GetSideKicks())
            fighter->TakeDamge(2);
        holmes->TakeDamge(2);
    }
    this->step=4;
    return Continue(context);

}
