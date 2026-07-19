#include "Domain/Entities/CombatCard.h"
void CombatCard::SetDamageOrDeffend(int amount ){
    this->DamageOrDeffend=amount;
}
int CombatCard::GetDamgeOrDeffend()const{
    return DamageOrDeffend;
}
void CombatCard::IncreseDamageOfDeffend(int amount){
    this->DamageOrDeffend+=amount;
}
