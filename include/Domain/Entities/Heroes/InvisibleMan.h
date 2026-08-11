#ifndef INVISIBLE_MAN
#define INVISIBLE_MAN

#include "Domain/Entities/Hero.h"
#include "Domain/Entities/Fog.h"
#include <vector>
#include <memory>


class InvisibleMan :public Hero{

    std::vector<std::unique_ptr <Fog>>fogs;

    public:
    InvisibleMan();

    std::vector<Fighter *> GetSideKicks() override;
    Fighter * GetDeadSideKick()const override;
    virtual void Ability(GameState&);
    bool CanUseCability(GameState);
    std::vector<Fog *> GetFogs()override;


};


#endif /* INVISIBLE_MAN */
