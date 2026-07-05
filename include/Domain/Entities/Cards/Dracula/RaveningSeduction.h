#ifndef RAVENINGSEDUCTION_H
#define RAVENINGSEDUCTION_H
#include "Domain/Entities/SchemeCard.h"

class RaveningSeduction : public SchemeCard{

    public :
        void Play(Hero * ,Hero * , Board *);
        FighterType GetOwner()const;
        std::vector<Fighter*> GetAllFighter(Hero * hero, Hero * enemy);
        int SelectNode(std::vector<int> ReachbleNodes);
        Fighter * SelectFighter(std::vector<Fighter*> AllFighters);



};


#endif /* RAVENINGSEDUCTION_H */
