#ifndef NODE_H
#define NODE_H
#include <vector>
#include "Domain/enums/Area.h"

struct Node{
    int id ;
    std::vector<Area> areas;
    /* data */
};

#endif /* NODE_H */
