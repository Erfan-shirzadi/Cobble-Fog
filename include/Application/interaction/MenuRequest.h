#ifndef MENU_REQUEST
#define MENU_REQUEST
#include <vector>
#include <string>

enum class InputType{
    ACTION,
    NODE,
    CARD,
    HERO,
};
struct MenuRequest{
    InputType type;
    std::string title;
    std::vector <std::string> options;
    std::vector<int> nodes;
};


#endif /* MENU_REQUEST */
