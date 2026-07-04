#include "Domain/Entities/Cards/Holmes/EducationNeverEnds.h"
#include "Domain/Combat/CombatContext.h"
EducationNeverEnds::EducationNeverEnds(){
    SetDamageOrDeffend(3);
    SetBoost(1);
    SetName("EducationNeverEnds");
    SetCategory(CardCategory::ATTACKANDDEFFENS);


}
void EducationNeverEnds::Play(CombatContext & combatcontext )const {

    if(combatcontext.Current->Won){
        combatcontext.Opponent->hero->DrawCard();
    }
    else {
        combatcontext.Current->hero->DrawCard();
        combatcontext.Current->hero->DrawCard();
    }
}
PlayTiming EducationNeverEnds::GetCardPlayTiming()const {
    return PlayTiming::ATFER_COMBAT;
}
FighterType EducationNeverEnds::GetOwner()const {
    return FighterType::ANY;
}

