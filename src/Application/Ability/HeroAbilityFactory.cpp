#include "Application/Ability/HeroAbilityFactory.h"
#include "Application/Ability/DraculaAbility.h"

std::unique_ptr<IAbility> CeateAbility(FighterType hero){

    switch (hero)
    {
    case FighterType::DRACULA:
        return std::make_unique<DraculaAbility>();
        break;
    case FighterType::SHERLOCK:
        return std::make_unique<IAbility>();
        break;
    }

    return nullptr;
}