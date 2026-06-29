#include "Application/UseCases/ManeverUseCase.h"
#include  <vector>
#include <unordered_map>
#include <queue>
void ManeverUseCase::execute(Hero & hero,int newnode,std::vector<int> reachableNodes){   
        bool ReachableNodetarget=false;
        for(int nodes:reachableNodes)
            if(newnode==nodes) ReachableNodetarget=true;

        if(ReachableNodetarget)hero.SetNode(newnode);

}

std::vector<int> ManeverUseCase::reachableNodesCurrentHero(Graph map,Hero hero,int Enemynode)const{

     std::vector <int >res;

    int HeroNode=hero.GetNode();    
    std::vector<int > neighbors= map.GetNeighbors(HeroNode);
    std::unordered_map <int,bool > visited(false);

    std::queue<int> q;
    visited[HeroNode]=true;
    q.push(HeroNode);
    int level=0;
    int maxlevel=hero.GetMove();

    while (!q.empty() && level<=maxlevel ){
        int levelsize=q.size();

        for(int i{};i<levelsize;i++){
            int curr = q.front();
            q.pop();
        
            res.push_back(curr);

            for (int x:map.GetNeighbors(curr)){
                    if(!visited[x]){
                        visited[x]=true;
                        if(x!=Enemynode)
                            q.push(x);
                    }
            }
        }
        level++;
    }

    return res;
}