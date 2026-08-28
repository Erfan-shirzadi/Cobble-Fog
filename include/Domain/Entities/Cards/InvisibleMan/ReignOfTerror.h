#ifndef REIGNOF_TERROR
#define REIGNOF_TERROR

#include "Domain/Entities/SchemeCard.h"
class ReignOfTerror: public SchemeCard{

    public:
    ReignOfTerror();
        FighterType GetOwner()const override;


};


#endif /* REIGN_OF_TERROR */
