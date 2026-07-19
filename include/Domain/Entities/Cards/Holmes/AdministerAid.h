#ifndef ADMINISTERAID_H
#define ADMINISTERAID_H
#include "Domain/Entities/SchemeCard.h"
class AdministerAid: public SchemeCard{

    public:
    AdministerAid();
        FighterType GetOwner()const override;


};

#endif /* ADMINISTERAID_H */
