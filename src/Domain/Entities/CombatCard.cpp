#include "Domain/Entities/CombatCard.h"
#include "Domain/Combat/CombatContext.h"
void CombatCard::SetDamageOrDeffend(int amount ){
    this->DamageOrDeffend=amount;
}
int CombatCard::GetDamgeOrDeffend()const{
    return DamageOrDeffend;
}