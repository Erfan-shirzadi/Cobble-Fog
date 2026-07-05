#ifndef PERYUPON_H
#define PERYUPON_H
#include "Domain/Entities/SchemeCard.h"

class PeryUpon :public SchemeCard{

    public:
        void Play(Hero * ,Hero * , Board *);
        FighterType GetOwner()const;

};

#endif /* PERYUPON_H */
