#include "Domain/Entities/Card.h"
void Card::SetBoost(int amount){
    this->Boost=amount;
}
     
int Card::GetBoost()const{
    return this->Boost;
}



void Card::SetName(std::string  name){
    this->Name=name;
}
std::string Card::GetName()const{
    return this->Name;
}
CardCategory Card::GetCategory()const{
    return this->category;
}
void Card::SetCategory(CardCategory cat){
    this->category=cat;
}

void Card::SetId(CardId id){
    this->id=id;
}
CardId Card::GetCardId()const{
    return this->id;
}
