#ifndef STUDYMETHODS_H
#define STUDYMETHODS_H
#include "Domain/Entities/CombatCard.h"

class StudyMethods : public CombatCard{

    public:
    StudyMethods();
     void Play(CombatContext & )const override;
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;
    ContinueResult Continue(ActionContext&);


};

#endif /* STUDYMETHODS_H */
