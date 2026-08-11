#include "Domain/Entities/Cards/InvisibleMan/CodedNotes.h"

CodedNotes::CodedNotes(){
    SetDamageOrDeffend(3);
    SetBoost(2);
    SetName("CodedNotes");
    SetCategory(CardCategory::DEFFENSE);
    SetId(CardId::CODED_NOTES);

}
PlayTiming CodedNotes::GetCardPlayTiming()const {
    return PlayTiming::ATFER_COMBAT;
}
FighterType CodedNotes::GetOwner()const {
    return FighterType::INVISIBLEMAN;
}
