#ifndef MISTFORM_H
#define MISTFORM_H
#include "Domain/Entities/SchemeCard.h"

class MistForm : public SchemeCard{

    public:
    MistForm();
        void Play(Hero * ,Hero * , Board *)override;
        FighterType GetOwner()const override;


};

#endif /* MISTFORM_H */
