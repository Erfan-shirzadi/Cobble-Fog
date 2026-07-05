#ifndef ELIMINATETHEIMPOSSIBLE_H
#define ELIMINATETHEIMPOSSIBLE_H
#include "Domain/Entities/SchemeCard.h"

class EliminateTheImpossible : public SchemeCard{

    public:
        void Play(Hero * ,Hero * , Board *);
        FighterType GetOwner()const;

};

#endif /* ELIMINATETHEIMPOSSIBLE_H */
