#ifndef ROLLINGFOG
#define ROLLINGFOG

#include "Domain/Entities/SchemeCard.h"
class RollingFog: public SchemeCard{

    public:
    RollingFog();
        FighterType GetOwner()const override;


};

#endif /* ROLLING_FOG */
