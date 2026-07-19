#include "Domain/Entities/Cards/Holmes/StudyMethods.h"
#include <vector>
#include <iostream>

StudyMethods::StudyMethods(){

    SetDamageOrDeffend(3);
    SetBoost(2);
    SetName("StudyMethods");
    SetCategory(CardCategory::ATTACKANDDEFFENS);
        SetId(CardId::STUDY_METHODS);


}
PlayTiming StudyMethods::GetCardPlayTiming()const {
    return PlayTiming::ATFER_COMBAT;
}
FighterType StudyMethods::GetOwner()const {
    return FighterType::ANY;
}

