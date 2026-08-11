#include "Domain/Player.h"
#include <memory>
#include "Domain/Entities/Heroes/Dracula.h"
#include "Domain/Entities/Heroes/Holmes.h"
#include "Domain/Entities/Heroes/InvisibleMan.h"

void Player::SetHero(int index){
    switch (index)
    {
    case 0:
        this->hero=std::make_unique<Dracula>();
        break;
    case 1:
        this->hero=std::make_unique<Holmes>();
        break;
    case 2:
        this->hero=std::make_unique<InvisibleMan>();
        break;
    }
}
Hero * Player::GetHero()const{
    return this->hero.get();
}
void Player::SetAge(int age){
    this->age=age;
}
int Player::GetAge()const{
    return age;
}
