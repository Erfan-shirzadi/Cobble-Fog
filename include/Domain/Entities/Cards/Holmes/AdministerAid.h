#ifndef ADMINISTERAID_H
#define ADMINISTERAID_H
#include "Domain/Entities/SchemeCard.h"

class AdministerAid: public SchemeCard{

    public:
    AdministerAid();
        void Play(Hero * ,Hero * , Board *) override;
        FighterType GetOwner()const override;


};

#endif /* ADMINISTERAID_H */
