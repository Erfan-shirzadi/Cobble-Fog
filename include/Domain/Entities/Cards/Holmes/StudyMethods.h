#ifndef STUDYMETHODS_H
#define STUDYMETHODS_H
#include "Domain/Entities/CombatCard.h"

class StudyMethods : public CombatCard{

    public:
    StudyMethods();
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;


};

#endif /* STUDYMETHODS_H */
