#include "Domain/Entities/Cards/Holmes/StudyMethods.h"
#include "Domain/Combat/CombatContext.h"
#include <vector>
#include <iostream>

StudyMethods::StudyMethods(){

    SetDamageOrDeffend(3);
    SetBoost(2);
    SetName("StudyMethods");
    SetCategory(CardCategory::ATTACKANDDEFFENS);

}
void StudyMethods::Play(CombatContext & combatcontext)const{
    if(combatcontext.Current->Won){
        Hero * hero=combatcontext.Opponent->hero;
        std::vector<Card *> hand =hero->GetHand();
        for(int i{};i<hand.size();i++){
            std::cout<< i <<". "<<hand[i]->GetName();
        }
    }
}
PlayTiming StudyMethods::GetCardPlayTiming()const {
    return PlayTiming::ATFER_COMBAT;
}
FighterType StudyMethods::GetOwner()const {
    return FighterType::ANY;
}

