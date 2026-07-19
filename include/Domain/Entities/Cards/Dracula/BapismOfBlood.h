#ifndef BAPISMOFBLOOD_H
#define BAPISMOFBLOOD_H
#include "Domain/Entities/SchemeCard.h"

class BapismOfBlood : public SchemeCard{

    public:
    BapismOfBlood();
        FighterType GetOwner()const override;


};

#endif /* BAPISMOFBLOOD_H */
