#ifndef MISTFORM_H
#define MISTFORM_H
#include "Domain/Entities/SchemeCard.h"

class MistForm : public SchemeCard{

    public:
    MistForm();
        FighterType GetOwner()const override;


};

#endif /* MISTFORM_H */
