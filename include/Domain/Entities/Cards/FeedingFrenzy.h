#ifndef FEEDING_FRENZY
#define FEEDING_FRENZY
#include "Domain/Entities/CombatCard.h"
#include "Domain/Entities/Heroes/Dracula.h"
#include "Domain/Entities/Graph.h"
class FeedingFrenzy :public CombatCard{

    public:
    FeedingFrenzy();
     void Play(CombatContext & )const;
     PlayTiming GetCardPlayTiming()const;
     FighterType GetOwner()const;



};

#endif /* FEEDING_FRENZY */
