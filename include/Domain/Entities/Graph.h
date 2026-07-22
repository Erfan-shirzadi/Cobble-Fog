#ifndef GRAPH_H
#define GRAPH_H
#include <unordered_map>
#include <vector>
#include "Node.h"

class Graph{
    std::unordered_map<int , Node>Nodes;
    std::unordered_map<int, std::vector<int> > graph;
    public:    
    Graph();
    void SetNodes();
    Node GetNode(int)const;
    NodeType GetNodeType(int )const;
    std::vector<Area> GetArea(int)const;
    std::vector<int> GetNeighbors(int node)const;
    int Distance(int start, int target);


};

#endif /* GRAPH_H */
