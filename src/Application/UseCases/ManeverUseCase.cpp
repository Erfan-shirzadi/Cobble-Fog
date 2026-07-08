#include "Application/UseCases/ManeverUseCase.h"
#include  <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
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

