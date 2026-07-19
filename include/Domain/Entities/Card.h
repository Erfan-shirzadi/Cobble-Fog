#ifndef CARD_H
#define CARD_H
#include <string>
#include <vector>
#include "Domain/enums/FighterType.h"
#include "Domain/enums/CardCategory.h"
#include "Domain/enums/PlayTiming.h"
#include "Domain/Entities/Cards/CardId.h"

class Card{

    std::string Name;
    CardCategory category;
    CardId id;
    
    
    int Boost;
    int DamageOrDeffend=0;

    public:
    void SetName(std::string);
    std::string GetName()const;
    CardCategory GetCategory()const;
    void SetCategory(CardCategory);
    void SetBoost(int);
    int GetBoost()const;
    void SetId(CardId);
    CardId GetCardId()const;

    virtual PlayTiming GetCardPlayTiming()const=0;
    virtual FighterType GetOwner()const=0;

};

#endif /* CARD_H */
