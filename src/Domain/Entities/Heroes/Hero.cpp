#include "Domain/Entities/Heroes/Holmes.h"

Holmes::Holmes():Hero("Sherlock Holmes",16,2,FighterType::SHERLOCK){

    this->DrWatson=std::make_unique<Fighter>("Dr Watson",8,2,FighterType::DR_WATSON);
}