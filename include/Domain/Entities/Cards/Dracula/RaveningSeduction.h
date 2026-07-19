#ifndef RAVENINGSEDUCTION_H
#define RAVENINGSEDUCTION_H
#include "Domain/Entities/SchemeCard.h"

class RaveningSeduction : public SchemeCard{

    public :
    RaveningSeduction();
        FighterType GetOwner()const override;

};


#endif /* RAVENINGSEDUCTION_H */
