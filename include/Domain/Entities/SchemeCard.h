#ifndef SCHEME_CARD
#define SCHEME_CARD
#include "Domain/Entities/Card.h"
#include "Domain/Entities/Hero.h"
#include "Domain/Entities/Board.h"
class SchemeCard : public Card{

    public:
    virtual FighterType GetOwner()const =0;
    PlayTiming GetCardPlayTiming()const{return PlayTiming::ANY;};



};

#endif /* SCHEME_CARD */
