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


};


#endif /* INVISIBLE_MAN */
