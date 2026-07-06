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

Holmes::Holmes():Hero("Sherlock Holmes",16,2,FighterType::SHERLOCK){

    this->DrWatson=std::make_unique<Fighter>("Dr Watson",8,2,FighterType::DR_WATSON);

    AddCardToDeck(std::make_unique<AdministerAid>(),2);
    AddCardToDeck(std::make_unique<CounterPunch>(),3);
    AddCardToDeck(std::make_unique<DeduceStrategy>(),3);
    AddCardToDeck(std::make_unique<EducationNeverEnds>(),2);
    AddCardToDeck(std::make_unique<EliminateTheImpossible>(),2);
    AddCardToDeck(std::make_unique<Feint>(),3);
    AddCardToDeck(std::make_unique<FixedPointInAChangingAge>(),2);
    AddCardToDeck(std::make_unique<MasterOfDisguise>(),2);
    AddCardToDeck(std::make_unique<ServiceRevolver>(),2);
    AddCardToDeck(std::make_unique<StudyMethods>(),2);
    AddCardToDeck(std::make_unique<TheGameIsAfoot>(),2);

}

std::vector<Fighter *>  Holmes::GetSideKicks(){
        std::vector<Fighter *>sidekick{};
        if(this->DrWatson->IsAlive())
            sidekick.push_back(DrWatson.get());

        return sidekick;
}
