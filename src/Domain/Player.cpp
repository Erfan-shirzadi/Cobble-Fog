#include "Domain/Player.h"
#include <memory>
void Player::SetHero(std::unique_ptr<Hero>  hero_){
    this->hero=std::move(hero_);
}
Hero * Player::GetHero()const{
    return this->hero.get();
}
