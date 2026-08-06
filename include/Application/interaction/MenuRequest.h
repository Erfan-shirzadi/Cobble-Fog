#ifndef MENU_REQUEST
#define MENU_REQUEST
#include <vector>
#include <string>
#include "Domain/Entities/Cards/CardId.h"

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
    std::vector<CardId> cards;
};


#endif /* MENU_REQUEST */
