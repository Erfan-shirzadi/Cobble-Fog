#ifndef INVISIBLE_MAN
#define INVISIBLE_MAN

#include "Domain/Entities/Hero.h"
#include <vector>
#include <memory>


class InvisibleMan :public Hero{

    std::vector<std::unique_ptr<Fighter> > SideKicks;

    public:
    InvisibleMan();

    std::vector<Fighter *> GetSideKicks() override;
    Fighter * GetDeadSideKick()const override;
    virtual void Ability(GameState&);
    bool CanUseCability(GameState);


};


#endif /* INVISIBLE_MAN */
