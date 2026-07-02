#ifndef CARD_H
#define CARD_H
#include <string>
#include <vector>
#include "Domain/enums/FighterType.h"
#include "Domain/enums/CardCategory.h"
#include "Domain/enums/PlayTiming.h"

class Card{

    std::string Name;
    std::vector<CardCategory> category;
    
    int Boost;

    public:
    void SetName(std::string);
    std::string GetName()const;
    std::vector<CardCategory> GetCategories()const;
    void AddCategory(CardCategory);
    void SetBoost(int);
    int GetBoost()const;


    virtual PlayTiming GetCardPlayTiming()const=0;
    virtual FighterType GetOwner()const=0;

};

#endif /* CARD_H */
