#ifndef MASTEROFDISGUISE_H
#define MASTEROFDISGUISE_H
#include "Domain/Entities/SchemeCard.h"

class MasterOfDisguise :public SchemeCard{

    public:
    MasterOfDisguise();
        FighterType GetOwner()const override;


};

#endif /* MASTEROFDISGUISE_H */
