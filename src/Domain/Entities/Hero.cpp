#include "Domain/Entities/Hero.h" 
#include <cstdlib>
#include <algorithm>

int Hero::GetHP()const{
   return this->Hp;
}
std::string Hero::GetName()const{
   return this->Name;
}
int Hero::GetMove()const{
   return this->Move;
}


void Hero::SetName(std::string name){
   this->Name=name;
}
void Hero::SetHP(int hp){
   this->Hp=hp;
   this->MaxHp=hp;

}

void Hero::SetMove(int move){
   this->Move=move;
}

void Hero::SetRange(int range){
   this->Range=range;
}



void Hero::SetNode(int newNode){
   this->node=newNode;
}


void Hero::SetBoost(int boost){
   this->CurrentBoost=boost;
}


int Hero::GetBoost()const{
   return CurrentBoost;
}

Card Hero::GetCard(int index){
      return this->Hand[index-1];
}

void Hero::RemoveCardHand(int index){
      std::swap(Hand[index-1],Hand[Hand.size()-1]);
      this->Hand.pop_back();
}


int Hero::GetNode()const{
   return this->node;
}
    

void Hero::TakeDamge(int damage){
   this->Hp-=damage;
   if(Hp<0)
      this->Hp=0;
}
void Hero::Heal(int heal){
   this->Hp+=heal;
   if(this->Hp>this->MaxHp)
      this->Hp=this->MaxHp;
}


bool Hero::IsAlive()const{
   return this-> Hp > 0;
}


void Hero::AddCardToHand(Card card){
   this->Hand.push_back(card);
}
Card Hero::GetRandomCard(){
   int RandomIndex=rand()%this->Deck.size();
   Card card=Deck[RandomIndex];

   std::swap(Deck[RandomIndex],Deck[Deck.size()-1]);
   Deck.pop_back();
   return card;
}


