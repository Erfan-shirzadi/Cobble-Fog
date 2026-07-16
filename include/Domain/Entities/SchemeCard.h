#ifndef SCHEME_CARD
#define SCHEME_CARD
#include "Domain/Entities/Card.h"
#include "Domain/Entities/Hero.h"
#include "Domain/Entities/Board.h"
class SchemeCard : public Card{

    public:
    virtual void Play(Hero * ,Hero * , Board *)=0;
    virtual FighterType GetOwner()const =0;
    PlayTiming GetCardPlayTiming()const{return PlayTiming::ANY;};
    virtual ContinueResult Continue(ActionContext&)=0;



};

#endif /* SCHEME_CARD */
