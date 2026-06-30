#include "Domain/Entities/Heroes/Dracula.h"
#include "Domain/Entities/Heroes/Holmes.h"
#include "Application/UseCases/ManeverUseCase.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){

    ManeverUseCase m;
    Graph map;
    Holmes h;
    Dracula d;
    h.SetNode(1);
    d.SetNode(1);
    cout<<h.GetName()<<" hp:"<<h.GetHP()<<" "<<h.GetNode()<< " "<<h.GetMove()<<endl;
    cout<<d.GetName()<<" hp:"<<d.GetHP()<<" "<<d.GetNode()<< " "<<d.GetMove()<<endl;

    std::vector<int> nodes;

    nodes=m.reachableNodesCurrentHero(map,h,16);
    for(int node:nodes)
        cout << node <<" ";


    return 0;
}




