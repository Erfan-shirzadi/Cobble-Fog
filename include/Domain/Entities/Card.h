#ifndef CARD_H
#define CARD_H
#include <string>
#include "Domain/enums/HeroType.h"
#include "Domain/enums/CardCategory.h"
#include "Domain/enums/PlayTiming.h"

class Card{

    std::string Name;
    HeroType owner;
    CardCategory category;
    PlayTiming timing;

    int Boost;

    public:

    void SetBoost(int);
     
    int GetBoost()const;

};

#endif /* CARD_H */
