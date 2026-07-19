#ifndef EDUCATIONEVERENDS_H
#define EDUCATIONEVERENDS_H
#include "Domain/Entities/CombatCard.h"

class EducationNeverEnds: public CombatCard{

    public:
    EducationNeverEnds();
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;



};


#endif /* EDUCATIONEVERENDS_H */
