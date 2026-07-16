#ifndef THIRSTFORSUSTENANCE_H
#define THIRSTFORSUSTENANCE_H
#include "Domain/Entities/CombatCard.h"

class ThirstForSustenance: public CombatCard{

    public:
    ThirstForSustenance();
     void Play(CombatContext & )const override;
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;
     ContinueResult Continue(ActionContext&);

};

#endif /* THIRSTFORSUSTENANCE_H */
