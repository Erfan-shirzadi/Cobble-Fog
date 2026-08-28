#include "Domain/Entities/Cards/InvisibleMan/StepLightly.h"

StepLightly::StepLightly(){
    SetBoost(1);
    SetName("StepLightly");
    SetCategory(CardCategory::SCHEME);
    SetId(CardId::STEP_LIGHTLY);

}
FighterType StepLightly::GetOwner()const{
    return FighterType::INVISIBLEMAN;
}
