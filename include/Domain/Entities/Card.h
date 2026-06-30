#ifndef CARD_H
#define CARD_H
#include <string>
#include "Domain/enums/FighterType.h"
#include "Domain/enums/CardCategory.h"
#include "Domain/enums/PlayTiming.h"

class Card{

    std::string Name;
    FighterType owner;
    CardCategory category;
    PlayTiming timing;

    int Boost;

    public:

    void SetBoost(int);
     
    int GetBoost()const;

};

#endif /* CARD_H */
