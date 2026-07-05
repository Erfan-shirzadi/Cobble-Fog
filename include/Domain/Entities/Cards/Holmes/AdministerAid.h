#ifndef ADMINISTERAID_H
#define ADMINISTERAID_H
#include "Domain/Entities/SchemeCard.h"

class AdministerAid: public SchemeCard{

    public:
        void Play(Hero * ,Hero * , Board *);

};

#endif /* ADMINISTERAID_H */
