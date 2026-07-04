#ifndef LOOKINTOMYEYSE_H
#define LOOKINTOMYEYSE_H
#include "Domain/Entities/CombatCard.h"

class LookIntoMyEyes: public CombatCard{

    public:
    LookIntoMyEyes();
     void Play(CombatContext & )const override;
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;


};

#endif /* LOOKINTOMYEYSE_H */
