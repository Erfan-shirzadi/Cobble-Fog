#ifndef EDUCATIONEVERENDS_H
#define EDUCATIONEVERENDS_H
#include "Domain/Entities/CombatCard.h"

class EducationNeverEnds: public CombatCard{

    public:
    EducationNeverEnds();
     void Play(CombatContext & )const override;
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;
    ContinueResult Continue(ActionContext&);



};


#endif /* EDUCATIONEVERENDS_H */
