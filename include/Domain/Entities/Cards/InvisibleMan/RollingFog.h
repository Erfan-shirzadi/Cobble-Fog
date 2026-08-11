#ifndef ROLLING_FOG
#define ROLLING_FOG

#include "Domain/Entities/SchemeCard.h"
class RollingFog: public SchemeCard{

    public:
    RollingFog();
        FighterType GetOwner()const override;


};

#endif /* ROLLING_FOG */
