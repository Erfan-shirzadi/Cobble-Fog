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
std::vector<CardCategory> Card::GetCategories()const{
    return this->category;
}
void Card::AddCategory(CardCategory cat){
    category.push_back(cat);
}
