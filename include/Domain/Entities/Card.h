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

    public:

};

#endif /* CARD_H */
