#include "Domain/Entities/Fighter.h"


Fighter::Fighter(std::string name,int Hp, int move ,FighterType Type):Name(name),
    MaxHp(Hp),Move(move),fightertype(Type){}


int Fighter::GetHP()const{
   return this->Hp;
}
std::string Fighter::GetName()const{
   return this->Name;
}
int Fighter::GetMove()const{
   return this->Move;
}


void Fighter::SetName(std::string name){
   this->Name=name;
}
void Fighter::SetHP(int hp){
   this->Hp=hp;
   this->MaxHp=hp;

}

void Fighter::SetMove(int move){
   this->Move=move;
}

void Fighter::SetRange(int range){
   this->Range=range;
}



void Fighter::SetNode(int newNode){
   this->node=newNode;
}


void Fighter::SetBoost(int boost){
   this->CurrentBoost=boost;
}


int Fighter::GetBoost()const{
   return CurrentBoost;
}


int Fighter::GetNode()const{
   return this->node;
}
    

void Fighter::TakeDamge(int damage){
   this->Hp-=damage;
   if(Hp<0)
      this->Hp=0;
}
void Fighter::Heal(int heal){
   this->Hp+=heal;
   if(this->Hp>this->MaxHp)
      this->Hp=this->MaxHp;
}


bool Fighter::IsAlive()const{
   return this-> Hp > 0;
}
