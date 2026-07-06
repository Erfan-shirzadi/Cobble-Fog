#ifndef ELIMINATETHEIMPOSSIBLE_H
#define ELIMINATETHEIMPOSSIBLE_H
#include "Domain/Entities/SchemeCard.h"

class EliminateTheImpossible : public SchemeCard{

    public:
    EliminateTheImpossible();
        void Play(Hero * ,Hero * , Board *) override;
        FighterType GetOwner()const override;

};

#endif /* ELIMINATETHEIMPOSSIBLE_H */
