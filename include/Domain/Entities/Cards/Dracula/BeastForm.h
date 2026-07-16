#ifndef BEASTFORM_H
#define BEASTFORM_H
#include "Domain/Entities/CombatCard.h"

class BestForm :public CombatCard{
    
    public:
    BestForm();
     void Play(CombatContext & )const override;
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;
     ContinueResult Continue(ActionContext&);


};

#endif /* BEASTFORM_H */
