#include "Domain/Entities/Heroes/Dracula.h"
#include "Domain/Entities/Heroes/Holmes.h"
#include "Application/UseCases/ManeverUseCase.h"
#include <iostream>
#include <vector>
#include "Domain/Entities/Board.h"
#include "Domain/Combat/CombatContext.h"
#include "Domain/Entities/Cards/FeedingFrenzy.h"
#include "Domain/Combat/CombatParticipant.h"
#include "Application/UseCases/PlaceMentUseCase.h"
#include "Domain/Player.h"

using namespace std;

int main(){

   
   
    GameState gamestate;
    
    Player a;
    a.SetHero(std::make_unique<Dracula>());
    Player b;
    b.SetHero(std::make_unique<Holmes>());
    gamestate.currnetPlayer=&a;
    gamestate.opponentPlayre=&b;
    Board board;
    gamestate.board=board;

    CombatContext combat;
    CombatParticipant dracula ;
    dracula.card=new FeedingFrenzy;
    dracula.fighter=a.GetHero();
    dracula.hero=a.GetHero();

    CombatParticipant holmes;
    holmes.fighter=b.GetHero();
    holmes.hero=b.GetHero();
    holmes.card=nullptr;

    combat.Current=&dracula;
    combat.Opponent=&holmes;
    combat.board=&board;

    



    // PlaceMentUseCase plaecment;

    // plaecment.PlaceHero(gamestate);
    // plaecment.PlaceSideKicks(gamestate);


    Hero * hero=a.GetHero();
    
    // cout << "dracula node "<<hero->GetNode()<<endl;
    // cout << "sidekicks "<<endl;
    // for(Fighter * fighter:hero->GetSideKicks())
    //     cout<<fighter->GetNode();

    // std::swap(gamestate.currnetPlayer,gamestate.opponentPlayre);
    // plaecment.PlaceHero(gamestate);
    // plaecment.PlaceSideKicks(gamestate);
    // cout << "Holmes node "<<hero->GetNode()<<endl;
    // cout << "sidekicks "<<endl;
    // for(Fighter * fighter:hero->GetSideKicks())
    //     cout<<fighter->GetNode();





    
    
    // context.Current->hero=&d;
    // context.Opponent->hero=&h;
    
    
    // h.SetNode(1);
    // d.SetNode(4);
    // vector<Fighter*> sidekick=d.GetSideKicks();
    // sidekick[0]->SetNode(3);
    // sidekick[1]->SetNode(31);
    // sidekick[2]->SetNode(20);
    

    // cout<<h.GetName()<<" hp:"<<h.GetHP()<<" "<<h.GetNode()<< " "<<h.GetMove()<<endl;
    // cout<<d.GetName()<<" hp:"<<d.GetHP()<<" "<<d.GetNode()<< " "<<d.GetMove()<<endl;

    // // std::vector<int> nodes;
    // der.card->Play(contexe);
    // cout << "*********";
    // cout << contexe.Current->DamageOrDeffend;

    // // nodes=board.reachableNodes(h,d,h.GetMove(),h.GetNode());
    // // for(int node:nodes)
    // //     cout << node <<" ";


    return 0;
}




