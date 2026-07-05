#ifndef SCHEME_CARD
#define SCHEME_CARD
#include "Domain/Entities/Card.h"
#include "Domain/Entities/Hero.h"
#include "Domain/Entities/Board.h"
class SchemeCard : public Card{

    public:
    virtual void Play(Hero * ,Hero * , Board *)=0;
    virtual FighterType GetOwner()const =0;

};

#endif /* SCHEME_CARD */
