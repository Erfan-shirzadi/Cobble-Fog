#ifndef DRACULA_H
#define DRACULA_H
#include "Domain/Entities/Hero.h"
#include <vector>
#include <memory>

class Dracula :public Hero{

    std::vector<std::unique_ptr<Fighter>> SideKicks;

    public:
    Dracula();
    virtual void Ability(GameState&);
    bool CanUseCability(GameState);

    std::vector<Fighter *> GetSideKicks() override;
    bool IsAliveAnySideKick()override;
    Fighter * GetDeadSideKick()const override;


};


#endif /* DRACULA_H */
