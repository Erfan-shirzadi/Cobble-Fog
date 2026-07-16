#include "Domain/Entities/Cards/Holmes/EducationNeverEnds.h"
#include "Domain/Combat/CombatContext.h"
#include "Application/interaction/ActionContext.h"
#include "Application/interaction/ContinueResult.h"


EducationNeverEnds::EducationNeverEnds(){
    SetDamageOrDeffend(3);
    SetBoost(1);
    SetName("EducationNeverEnds");
    SetCategory(CardCategory::ATTACKANDDEFFENS);


}
void EducationNeverEnds::Play(CombatContext & combatcontext )const {
    Hero * hero=combatcontext.Opponent->hero;
    if(combatcontext.Current->Won){
        if(hero->DrawCard()){
        for(auto fighter: hero->GetSideKicks())
            fighter->TakeDamge(2);
            hero->TakeDamge(2);
          }
    }
    else {
        hero=combatcontext.Current->hero;
        for(int i{};i<2;i++)
            if(hero->DrawCard()){
              for(auto fighter: hero->GetSideKicks())
                 fighter->TakeDamge(2);
                hero->TakeDamge(2);
            }
    }
}
PlayTiming EducationNeverEnds::GetCardPlayTiming()const {
    return PlayTiming::ATFER_COMBAT;
}
FighterType EducationNeverEnds::GetOwner()const {
    return FighterType::ANY;
}

ContinueResult EducationNeverEnds::Continue(ActionContext &){
    
}