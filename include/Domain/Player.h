#ifndef PLAYER_H
#define PLAYER_H
#include "Domain/Entities/Hero.h"
#include <memory>

class Player{

    std::unique_ptr<Hero>  hero;
    int age=0;
    public:
     
    void SetHero(std::unique_ptr<Hero> );
    Hero * GetHero()const;
    void SetAge(int);
    int GetAge()const;

};

#endif /* PLAYER_H */
