#ifndef COUNTERPUNCH_H
#define COUNTERPUNCH_H
#include "Domain/Entities/CombatCard.h"

class CounterPunch : public CombatCard{

    public:
    CounterPunch();
     void Play(CombatContext & )const override;
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;
     ContinueResult Continue(ActionContext&);



};

#endif /* COUNTERPUNCH_H */
