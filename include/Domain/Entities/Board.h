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
    std::vector <int> reachableNodes(Hero * fighters, Hero * enemy ,int distance,int HeroNode);
    std::vector<int> GetNodeofArea(int node)const;
    std::vector<int> GetReachableNighbors(int node);
    bool IsAnArea(int node1, int node2)const;
    bool AreAdjacent(int node1,int node2)const;
    std::vector<int> AllFullNodes();

    std::string GetGraph();

    NodeType GetNodeType(int node);
    std::vector<int> GetAllEmptyNodes();
    void ResetMovment(Hero *);
    int Distance(int start, int target);


};

#endif /* BOARD_H */
