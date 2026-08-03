#ifndef MENU_REQUEST
#define MENU_REQUEST
#include <vector>
#include <string>

struct MenuRequest{
    std::string title;
    std::vector <std::string> options;
    std::vector<int> nodes;
};


#endif /* MENU_REQUEST */
