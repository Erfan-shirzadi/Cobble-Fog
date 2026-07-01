#include "Domain/Entities/Heroes/Dracula.h"
#include "Domain/Entities/Heroes/Holmes.h"
#include "Application/UseCases/ManeverUseCase.h"
#include <iostream>
#include <vector>
#include "Domain/Entities/Board.h"
using namespace std;

int main(){

    Board board;
    Holmes h;
    Dracula d;
    h.SetNode(1);
    d.SetNode(4);
    cout<<h.GetName()<<" hp:"<<h.GetHP()<<" "<<h.GetNode()<< " "<<h.GetMove()<<endl;
    cout<<d.GetName()<<" hp:"<<d.GetHP()<<" "<<d.GetNode()<< " "<<d.GetMove()<<endl;

    std::vector<int> nodes;

    nodes=board.reachableNodes(h,d,h.GetMove(),h.GetNode());
    for(int node:nodes)
        cout << node <<" ";


    return 0;
}




