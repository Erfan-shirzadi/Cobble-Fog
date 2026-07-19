#ifndef FEEDING_FRENZY
#define FEEDING_FRENZY
#include "Domain/Entities/CombatCard.h"
#include "Domain/Entities/Heroes/Dracula.h"
#include "Domain/Entities/Graph.h"
class FeedingFrenzy :public CombatCard{

    public:
    FeedingFrenzy();
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;



};

#endif /* FEEDING_FRENZY */
