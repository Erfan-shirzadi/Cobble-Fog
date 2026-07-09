#ifndef NODE_H
#define NODE_H
#include <vector>
#include "Domain/enums/Area.h"
#include "Domain/enums/NodeType.h"

struct Node{
    int id ;
    NodeType nodetype;
    std::vector<Area> areas;

    /* data */
};

#endif /* NODE_H */
