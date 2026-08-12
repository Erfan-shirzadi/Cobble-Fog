#include "Domain/Entities/Board.h"
#include  <vector>
#include <map>
#include <queue>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <algorithm>
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

    if(fighter->GetFighterType()==FighterType::INVISIBLEMAN){
        Hero * hero=dynamic_cast<Hero*>(fighter);
        bool flag=false;
        for(auto fog:hero->GetFogs()){
            if(fog->GetNode()==hero->GetNode()){
                flag=true;
            }
        }

        if(flag){
            for(auto fog:hero->GetFogs()){
                if(!isOccupied(fog->GetNode()))
                    res.push_back(fog->GetNode());
            }
        }
    }

    return res;
}


bool Board::IsAnArea(int node1, int node2)const{
     std::vector<Area>Area1=map.GetArea(node1);
     std::vector<Area>Area2=map.GetArea(node2);
     
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
    sort(nodes.begin(),nodes.end());
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

std::multimap<FighterType,int> Board::GetGraph(){
    std::multimap<FighterType,int>res;
    for(auto fog:fogs){
        res.insert(std::make_pair(FighterType::FOG,fog->GetNode()));
        // res[FighterType::FOG]=fog->GetNode();
    }
    for(auto fighter:allFighters){
        res.insert(std::make_pair(fighter->GetFighterType(),fighter->GetNode()));
        // res[fighter->GetFighterType()]=fighter->GetNode();
    }
    return res;

}

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


int Board::Distance(int start, int target){
    return map.Distance(start,target);
}


void Board::ResetBoard(){
    allFighters.clear();
}

void Board::AddFog(Fog* f,int node){
    f->SetNode(node);
    fogs.push_back(f);
    std::cout<<" Push backed\n";
    std::cout<<fogs.size()<<"sizs of fogs in board\n";
}


bool Board::IsFogHere(int ndoe){
    for(auto fog :fogs){
        if (fog->GetNode()==ndoe){
            return true;
        }
    }

    return false;
}

std::vector<int> Board::GetReachbleNodesForFog(int node,int distance){
std::vector <int >res;
    res.push_back(node);
    
    std::vector<int > neighbors= map.GetNeighbors(node);
    std::unordered_map <int,bool > visited(false);

    std::queue<int> q;
    visited[node]=true;
    q.push(node);
    int level=0;
    int maxlevel=distance;

    while (!q.empty() && level<=maxlevel ){
        int levelsize=q.size();

        for(int i{};i<levelsize;i++){
            int curr = q.front();
            q.pop();
            // bool Isreachable=true;
            // for(int node:AllyNodes)
            //     if(curr==node) Isreachable =false;
            // if(Isreachable && (!isOccupied(curr) || (isOccupied(curr) && curr==HeroNode)) )
            if(!IsFogHere(curr))
                res.push_back(curr);

            for (int x:map.GetNeighbors(curr)){
                    if(!visited[x]){
                        visited[x]=true;
                            q.push(x);
                    }
            }
        }
        level++;
    }

   
    return res;

}
