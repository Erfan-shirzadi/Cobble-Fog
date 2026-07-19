#ifndef SERVICEREVOLVER_H
#define SERVICEREVOLVER_H
#include "Domain/Entities/CombatCard.h"

class ServiceRevolver : public CombatCard{

    public:
    ServiceRevolver();
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;


};

#endif /* SERVICEREVOLVER_H */
