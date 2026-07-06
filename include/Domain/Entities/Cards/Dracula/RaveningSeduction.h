#ifndef RAVENINGSEDUCTION_H
#define RAVENINGSEDUCTION_H
#include "Domain/Entities/SchemeCard.h"

class RaveningSeduction : public SchemeCard{

    public :
    RaveningSeduction();
        void Play(Hero * ,Hero * , Board *) override;
        FighterType GetOwner()const override;
        std::vector<Fighter*> GetAllFighter(Hero * hero, Hero * enemy);
        int SelectNode(std::vector<int> ReachbleNodes);
        Fighter * SelectFighter(std::vector<Fighter*> AllFighters);



};


#endif /* RAVENINGSEDUCTION_H */
