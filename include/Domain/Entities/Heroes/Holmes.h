#ifndef HOLMES_H
#define HOLMES_H
#include "Domain/Entities/Hero.h"
#include <memory>
class Holmes : public Hero{

    std::unique_ptr<Fighter> DrWatson;
    public:
    Holmes();
    virtual void Ability(GameState&);
    bool CanUseCability(GameState);


    std::vector<Fighter *> GetSideKicks()override;
    bool IsAliveAnySideKick()override;

};

#endif /* HOLMES_H */
