#include "Domain/Entities/Heroes/Dracula.h"
#include "Domain/Entities/Heroes/Holmes.h"
#include "Application/UseCases/ManeverUseCase.h"
#include <iostream>
#include <vector>
#include "Domain/Entities/Board.h"
#include "Domain/Combat/CombatContext.h"
#include "Domain/Entities/Cards/FeedingFrenzy.h"
#include "Domain/Combat/CombatParticipant.h"
using namespace std;

int main(){

    Board board;
    Holmes h;
    
    Dracula d;
    CombatParticipant der;
    der.card=new FeedingFrenzy;
    der.fighter=&d;
    der.hero=&d;
    CombatParticipant enmy;
    enmy.fighter=&h;
    enmy.hero=&h;
    CombatContext contexe;
    contexe.Current=&der;
    contexe.Opponent=&enmy;
    contexe.board=&board;
    
    // context.Current->hero=&d;
    // context.Opponent->hero=&h;
    
    
    h.SetNode(1);
    d.SetNode(4);
    vector<Fighter*> sidekick=d.GetSideKicks();
    sidekick[0]->SetNode(3);
    sidekick[1]->SetNode(31);
    sidekick[2]->SetNode(20);
    

    cout<<h.GetName()<<" hp:"<<h.GetHP()<<" "<<h.GetNode()<< " "<<h.GetMove()<<endl;
    cout<<d.GetName()<<" hp:"<<d.GetHP()<<" "<<d.GetNode()<< " "<<d.GetMove()<<endl;

    // std::vector<int> nodes;
    der.card->Play(contexe);
    cout << "*********";
    cout << contexe.Current->DamageOrDeffend;

    // nodes=board.reachableNodes(h,d,h.GetMove(),h.GetNode());
    // for(int node:nodes)
    //     cout << node <<" ";


    return 0;
}




