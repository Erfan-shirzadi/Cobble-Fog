#ifndef MASTEROFDISGUISE_H
#define MASTEROFDISGUISE_H
#include "Domain/Entities/SchemeCard.h"

class MasterOfDisguise :public SchemeCard{

    public:
        void Play(Hero * ,Hero * , Board *);
        FighterType GetOwner()const;


};

#endif /* MASTEROFDISGUISE_H */
