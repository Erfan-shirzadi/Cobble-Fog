#ifndef ELIMINATETHEIMPOSSIBLE_H
#define ELIMINATETHEIMPOSSIBLE_H
#include "Domain/Entities/SchemeCard.h"

class EliminateTheImpossible : public SchemeCard{

    public:
    EliminateTheImpossible();
        FighterType GetOwner()const override;


};

#endif /* ELIMINATETHEIMPOSSIBLE_H */
