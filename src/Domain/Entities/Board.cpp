#include "Domain/Entities/Board.h"
#include  <vector>
#include <unordered_map>
#include <queue>

void Board::Move(Fighter& fihgter,int node)const{

}
std::vector<int> Board::adjacentCells(int node)const{

}
std::vector <int> Board::reachableNodes(Hero & fighter, Hero & enemy ,int distance,int HeroNode)const{
    std::vector <int >res;
    std::vector<int> EnemiesNode;
    std::vector<int> AllyNodes;
    if(fighter.GetNode()!=HeroNode)
        AllyNodes.push_back(fighter.GetNode());
    for(Fighter * f:fighter.GetSideKicks())
        if(fighter.GetNode()!=HeroNode)
            AllyNodes.push_back(f->GetNode());

    EnemiesNode.push_back(enemy.GetNode());
    for(Fighter * f:enemy.GetSideKicks())
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
            if(Isreachable)
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
     for(Area area:Area1)
        for(Area items:Area2)
            if(area==items)
                return true;

    return false;

}
