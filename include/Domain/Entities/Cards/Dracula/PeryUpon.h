#ifndef PERYUPON_H
#define PERYUPON_H
#include "Domain/Entities/SchemeCard.h"

class PeryUpon :public SchemeCard{

    public:
    PeryUpon();
        void Play(Hero * ,Hero * , Board *) override;
        FighterType GetOwner()const override;
        ContinueResult Continue(ActionContext&);

};

#endif /* PERYUPON_H */
