#include "Domain/Entities/Cards/Holmes/EducationNeverEnds.h"

EducationNeverEnds::EducationNeverEnds(){
    SetDamageOrDeffend(3);
    SetBoost(1);
    SetName("EducationNeverEnds");
    SetCategory(CardCategory::ATTACKANDDEFFENS);
        SetId(CardId::EDUCATION_NEVER_ENDS);



}
PlayTiming EducationNeverEnds::GetCardPlayTiming()const {
    return PlayTiming::ATFER_COMBAT;
}
FighterType EducationNeverEnds::GetOwner()const {
    return FighterType::ANY;
}

