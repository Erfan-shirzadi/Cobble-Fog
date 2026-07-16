#ifndef BAPISMOFBLOOD_H
#define BAPISMOFBLOOD_H
#include "Domain/Entities/SchemeCard.h"

class BapismOfBlood : public SchemeCard{

    public:
    BapismOfBlood();
        void Play(Hero * ,Hero * , Board *) override;
        FighterType GetOwner()const override;
        ContinueResult Continue(ActionContext&);


};

#endif /* BAPISMOFBLOOD_H */
