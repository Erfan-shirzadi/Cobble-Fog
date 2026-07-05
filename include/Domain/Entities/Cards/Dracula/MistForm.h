#ifndef MISTFORM_H
#define MISTFORM_H
#include "Domain/Entities/SchemeCard.h"

class MistForm : public SchemeCard{

    public:
        void Play(Hero * ,Hero * , Board *);
        FighterType GetOwner()const;


};

#endif /* MISTFORM_H */
