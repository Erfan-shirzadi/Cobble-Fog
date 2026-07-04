#ifndef BOARD_H
#define BOARD_H
#include "Domain/Entities/Graph.h"
#include "Domain/Entities/Fighter.h"
#include "Domain/Entities/Hero.h"
#include <vector>
#include <unordered_map>
class Board {

    Graph map;
    std::vector<Fighter *> allFighters;
    public:
    void AddFighter(Fighter*,int node);
    bool isOccupied(int node)const;
    void Move(Fighter& fihgter,int node)const;
    std::vector<int> adjacentCells(int node)const;
    std::vector <int> reachableNodes(Hero * fighters, Hero * enemy ,int distance,int HeroNode);
    std::vector<int> GetNodeofArea(int node)const;
    std::vector<int> GetReachableNighbors(int node);
    bool IsAnArea(int node1, int node2)const;
};

#endif /* BOARD_H */
