#include "Domain/Entities/Heroes/Holmes.h"
#include "Domain/Entities/Cards/Holmes/AdministerAid.h"
#include "Domain/Entities/Cards/Holmes/CounterPunch.h"
#include "Domain/Entities/Cards/Holmes/DeduceStrategy.h"
#include "Domain/Entities/Cards/Holmes/EducationNeverEnds.h"
#include "Domain/Entities/Cards/Holmes/EliminateTheImpossible.h"
#include "Domain/Entities/Cards/Holmes/FixedPointInAChangingAge.h"
#include "Domain/Entities/Cards/Holmes/MasterOfDisguise.h"
#include "Domain/Entities/Cards/Holmes/ServiceRevolver.h"
#include "Domain/Entities/Cards/Holmes/StudyMethods.h"
#include "Domain/Entities/Cards/Holmes/TheGameIsAfoot.h"
#include "Domain/Entities/Cards/Dracula/Feint.h"
#include "Domain/Game/GameState.h"

Holmes::Holmes():Hero("Sherlock Holmes",16,2,FighterType::SHERLOCK){

    this->DrWatson=std::make_unique<Fighter>("Dr Watson",8,2,FighterType::DR_WATSON);
    DrWatson->SetAttack(Attack::RANGED);
    this->SetAttack(Attack::MELEE);
    
    AddCardToDeck(std::make_unique<AdministerAid>());
        AddCardToDeck(std::make_unique<AdministerAid>());

    AddCardToDeck(std::make_unique<CounterPunch>());
    AddCardToDeck(std::make_unique<CounterPunch>());
    AddCardToDeck(std::make_unique<CounterPunch>());

    AddCardToDeck(std::make_unique<DeduceStrategy>());
        AddCardToDeck(std::make_unique<DeduceStrategy>());
    AddCardToDeck(std::make_unique<DeduceStrategy>());

    AddCardToDeck(std::make_unique<EducationNeverEnds>());
        AddCardToDeck(std::make_unique<EducationNeverEnds>());

    AddCardToDeck(std::make_unique<EliminateTheImpossible>());
        AddCardToDeck(std::make_unique<EliminateTheImpossible>());

    AddCardToDeck(std::make_unique<Feint>());
        AddCardToDeck(std::make_unique<Feint>());
    AddCardToDeck(std::make_unique<Feint>());

    AddCardToDeck(std::make_unique<FixedPointInAChangingAge>());
        AddCardToDeck(std::make_unique<FixedPointInAChangingAge>());

    AddCardToDeck(std::make_unique<MasterOfDisguise>());
        AddCardToDeck(std::make_unique<MasterOfDisguise>());

    AddCardToDeck(std::make_unique<ServiceRevolver>());
        AddCardToDeck(std::make_unique<ServiceRevolver>());

    AddCardToDeck(std::make_unique<StudyMethods>());
        AddCardToDeck(std::make_unique<StudyMethods>());

    AddCardToDeck(std::make_unique<TheGameIsAfoot>());
        AddCardToDeck(std::make_unique<TheGameIsAfoot>());

                AddCardToDeck(std::make_unique<AdministerAid>());

    AddCardToDeck(std::make_unique<EliminateTheImpossible>());






}

std::vector<Fighter *>  Holmes::GetSideKicks(){
        std::vector<Fighter *>sidekick{};
        if(this->DrWatson->IsAlive())
            sidekick.push_back(DrWatson.get());

        return sidekick;
}

bool Holmes::IsAliveAnySideKick(){
    return this->DrWatson->IsAlive();
}

void Holmes::Ability(GameState&){

}

bool Holmes::CanUseCability(GameState){
    return false;
}
