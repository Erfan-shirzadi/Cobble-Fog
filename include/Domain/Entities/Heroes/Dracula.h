#ifndef DRACULA_H
#define DRACULA_H
#include "Domain/Entities/Hero.h"
#include <vector>
#include <memory>

class Dracula :public Hero{

    std::vector<std::unique_ptr<Fighter>> SideKicks;

    public:
    Dracula();
    //void SpecialAbility()override{};
    Fighter * GetSideKicks(int index)const;

};


#endif /* DRACULA_H */
