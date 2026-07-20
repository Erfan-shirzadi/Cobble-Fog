#include "Domain/Entities/Fighter.h"
#include <iostream>

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

Attack Fighter::GetAttack()const{
   return attack;
}


void Fighter::SetAttack(Attack attack_){
   this->attack=attack_;
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


void Fighter::SetNode(int newNode){
   this->node=newNode;
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


FighterType Fighter::GetFighterType(){
   return this->fightertype;
}

