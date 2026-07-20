#ifndef FA55802B_203B_46CD_A482_E120D2355B66
#define FA55802B_203B_46CD_A482_E120D2355B66
#include <memory>
#include "Application/Ability/IAbility.h"

class HeroAbilityFactory{
    public:
    static std::unique_ptr<IAbility> CeateAbility(FighterType);
};

#endif /* FA55802B_203B_46CD_A482_E120D2355B66 */
