#include "Domain/Entities/Card.h"

void Card::SetBoost(int amount){
    this->Boost=amount;
}
     
int Card::GetBoost()const{
    return this->Boost;
}
