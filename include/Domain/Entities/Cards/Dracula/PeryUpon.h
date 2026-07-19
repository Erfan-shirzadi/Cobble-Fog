#ifndef PERYUPON_H
#define PERYUPON_H
#include "Domain/Entities/SchemeCard.h"

class PeryUpon :public SchemeCard{

    public:
    PeryUpon();
        FighterType GetOwner()const override;

};

#endif /* PERYUPON_H */
