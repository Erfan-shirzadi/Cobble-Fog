#include "Application/UseCases/PlaceMentUseCase.h"
#include <vector>
#include <iostream>
void PlaceMentUseCase::PlaceHero(GameState & gamestate){
    Hero * hero=gamestate.currnetPlayer->GetHero();
    int Nodeset;
    std::vector<int>reachableNodes;

    if( !gamestate.board.isOccupied(1)) reachableNodes.push_back(1);
    if(!gamestate.board.isOccupied(26)) reachableNodes.push_back(26);

    bool flag=false;
    while(true){
        std::cout<< "Set your hero : \n";
        for(int node:reachableNodes)
            std::cout<<"+"<<node<<std::endl;
        std::cin>>Nodeset;
        for(int node:reachableNodes)
            if(node==Nodeset)
                flag=true;
        if(!flag)
            std::cout<< " Please Selecte a curroct node"<<std::endl;
        else if(gamestate.board.isOccupied(Nodeset)){
            std::cout<<" in this node exists a fighter allready"<<std::endl;
        }
        else {
            gamestate.board.AddFighter(dynamic_cast<Fighter*>(hero),Nodeset);
            break;
        }

    }
    hero->SetNode(Nodeset);


}
void PlaceMentUseCase::PlaceSideKicks(GameState & gamestate){
    Hero * hero=gamestate.currnetPlayer->GetHero();
    std::vector<Fighter*> sidekicks=hero->GetSideKicks();
    std::vector<int> reachableNodes=gamestate.board.GetNodeofArea(hero->GetNode());
    int Nodeset;
    for(Fighter * fighter:sidekicks){
        std::cout << "place SideKicks in Hero'S Area "<<std::endl;
        bool flag=false;
        while(true){
            std::cin>>Nodeset;
            for(int node:reachableNodes)
                if(node==Nodeset)flag=true;

            if(!flag)
                std::cout<< " Please Selecte a curroct node"<<std::endl;
            else if(gamestate.board.isOccupied(Nodeset)){
            std::cout<<" in this node exists a fighter allready"<<std::endl;
            }
            else{
                gamestate.board.AddFighter(fighter,Nodeset);
                break;
            }

            
        }
        
    }


}
bool PlaceMentUseCase::finished()const{

}