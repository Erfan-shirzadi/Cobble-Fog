#include "Domain/Entities/Board.h"
#include  <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <stdexcept>

void Board::Move(Fighter& fihgter,int node)const{

}
std::vector<int> Board::adjacentCells(int node)const{

}
std::vector <int> Board::reachableNodes(Hero * fighter, Hero * enemy ,int distance,int HeroNode){
    std::vector <int >res;
    res.push_back(HeroNode);
    std::vector<int> EnemiesNode;
    std::vector<int> AllyNodes;
    if(fighter->GetNode()!=HeroNode)
        AllyNodes.push_back(fighter->GetNode());
    for(Fighter * f:fighter->GetSideKicks())
        if(fighter->GetNode()!=HeroNode)
            AllyNodes.push_back(f->GetNode());

    EnemiesNode.push_back(enemy->GetNode());
    for(Fighter * f:enemy->GetSideKicks())
        EnemiesNode.push_back(f->GetNode());


    std::vector<int > neighbors= map.GetNeighbors(HeroNode);
    std::unordered_map <int,bool > visited(false);

    std::queue<int> q;
    visited[HeroNode]=true;
    q.push(HeroNode);
    int level=0;
    int maxlevel=distance;

    while (!q.empty() && level<=maxlevel ){
        int levelsize=q.size();

        for(int i{};i<levelsize;i++){
            int curr = q.front();
            q.pop();
            bool Isreachable=true;
            for(int node:AllyNodes)
                if(curr==node) Isreachable =false;
            if(Isreachable && (!isOccupied(curr) || (isOccupied(curr) && curr==HeroNode)) )
                res.push_back(curr);

            for (int x:map.GetNeighbors(curr)){
                    if(!visited[x]){
                        visited[x]=true;
                        bool Cansearch=true;
                        for(int node:EnemiesNode)
                            if(x==node) Cansearch =false;

                        if(Cansearch)
                            q.push(x);
                    }
            }
        }
        level++;
    }

    return res;
}


bool Board::IsAnArea(int node1, int node2)const{
     std::vector<Area>Area1=map.GetArea(node1);
     std::vector<Area>Area2=map.GetArea(node2);
     
    // std::cout<<"size1: "<<Area1.size()<<std::endl;
    // std::cout<<"size2: "<<Area2.size()<<std::endl;

    // for(Area area:Area1)std::cout<<(int)area<<std::endl;
    // std::cout<< "((((()))))"<<std::endl;
    // for(Area area:Area2)std::cout<<(int)area<<std::endl;

     for(Area area:Area1){
        for(Area items:Area2){
            if((int)area==(int)items)
                return true;
        }
    }

    return false;

}


bool Board::isOccupied(int node)const{
    for( Fighter* fighter: this->allFighters)
        if(fighter->GetNode()==node && fighter->IsAlive())
            return true;

    return false;
}

void Board::AddFighter(Fighter* newfighter,int node){
    newfighter->SetNode(node);
    this->allFighters.push_back(newfighter);
}

std::vector<int> Board::GetNodeofArea(int node)const{
    std::vector<int> res;
    for(int i{1};i<=32;i++)
        if(IsAnArea(node,i))
            if(!isOccupied(i))
                res.push_back(i);    

    return res;
}


std::vector<int> Board::GetReachableNighbors(int node){
    std::vector<int> nodes=map.GetNeighbors(node);
    for(int i{};i<nodes.size();i++)
        for(Fighter *  fihgter: this->allFighters)
            if(fihgter->GetNode()==nodes[i] && fihgter->IsAlive()){
                std::swap(nodes[i],nodes[nodes.size()]);
                nodes.pop_back();
            }

    return nodes;
}

bool Board::AreAdjacent(int node1,int node2)const{
   for( int x:map.GetNeighbors(node1)){
        if(x==node2) return true;
   }
   return false;
}



std::vector<int> Board::AllFullNodes(){
   std::vector<int> res;
   for(int i{};i<this->allFighters.size();i++)
        res.push_back(allFighters[i]->GetNode());

    return res;
}

std::string Board::GetGraph(){
    for(int i{1};i<=32;i++){

        int indexFighter;
        for(int j{};j<this->allFighters.size();j++)
            if(i==allFighters[j]->GetNode())
                indexFighter=j;
        if(isOccupied(i)){
            std::cout<< i<<"  ( "<<allFighters[indexFighter]->GetName() <<" )"<<std::endl;
        }
        else {std::cout<< i<<"  ( empty )"<<std::endl;}
    }
    return "";
}

// PathWay Board::GetPathType(int node1,int node2){
//     if(map.GetNodeType(node1)==NodeType::SECREST && map.GetNodeType(node2)==NodeType::SECREST)
//         return PathWay::SECRETPATH;
//     if(map.GetNodeType(node1)==NodeType::SECREST && map.GetNodeType(node2)==NodeType::SIMPLE)
// }


NodeType Board::GetNodeType(int node){
    return map.GetNodeType(node);
}


std::vector<int> Board::GetAllEmptyNodes(){
    std::vector<int> res;
    for(int i{1};i<=32;i++){
        if(!isOccupied(i))
            res.push_back(i);
    }
    return res;
}
