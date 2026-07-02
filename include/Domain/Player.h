#ifndef PLAYER_H
#define PLAYER_H
#include "Domain/Entities/Hero.h"
#include <memory>

class Player{

    std::unique_ptr<Hero>  hero;
    public:
     
    void SetHero(std::unique_ptr<Hero> );
    Hero * GetHero()const;

};

#endif /* PLAYER_H */
