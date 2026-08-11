#include "Domain/Entities/Cards/InvisibleMan/ReignOfTerror.h"

ReignOfTerror::ReignOfTerror(){
    SetBoost(1);
    SetName("ReignOfTerror");
    SetCategory(CardCategory::SCHEME);
    SetId(CardId::REIGN_OF_TERROR);

}
FighterType ReignOfTerror::GetOwner()const{
    return FighterType::INVISIBLEMAN;
}
