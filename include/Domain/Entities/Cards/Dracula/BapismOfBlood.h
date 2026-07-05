#ifndef BAPISMOFBLOOD_H
#define BAPISMOFBLOOD_H
#include "Domain/Entities/SchemeCard.h"

class BapismOfBlood : public SchemeCard{

    public:
        void Play(Hero * ,Hero * , Board *);
        FighterType GetOwner()const;

};

#endif /* BAPISMOFBLOOD_H */
