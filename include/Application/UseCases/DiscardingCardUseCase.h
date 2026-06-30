#ifndef DISCARDINCARD_USECASE
#define DISCARDINCARD_USECASE
#include "Domain/Entities/Hero.h"

class DiscardingCardUseCase{

    public:
        void execute(Hero &,int card);
};

#endif /*DISCARDINCARD_USECASE */
