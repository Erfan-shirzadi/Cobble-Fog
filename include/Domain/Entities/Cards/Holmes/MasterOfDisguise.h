#ifndef MASTEROFDISGUISE_H
#define MASTEROFDISGUISE_H
#include "Domain/Entities/SchemeCard.h"

class MasterOfDisguise :public SchemeCard{

    public:
    MasterOfDisguise();
        void Play(Hero * ,Hero * , Board *) override;
        FighterType GetOwner()const override;


};

#endif /* MASTEROFDISGUISE_H */
