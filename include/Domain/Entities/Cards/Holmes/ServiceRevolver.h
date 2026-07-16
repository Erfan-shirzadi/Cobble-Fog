#ifndef SERVICEREVOLVER_H
#define SERVICEREVOLVER_H
#include "Domain/Entities/CombatCard.h"

class ServiceRevolver : public CombatCard{

    public:
    ServiceRevolver();
     void Play(CombatContext & )const override;
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;
     ContinueResult Continue(ActionContext&);


};

#endif /* SERVICEREVOLVER_H */
