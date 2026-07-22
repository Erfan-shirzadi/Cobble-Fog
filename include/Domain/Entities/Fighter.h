#ifndef FIGHTER_H
#define FIGHTER_H
#include <string>
#include "Domain/enums/FighterType.h"
#include "Domain/enums/Attack.h"
class Fighter{

    int MaxHp;
    int Hp=MaxHp;
    std::string Name ;
    int Move=2;
    Attack attack;
    int node=0;
    FighterType fightertype;

    public:
    Fighter(std::string ,int Hp, int move ,FighterType);

    void SetName(std::string);
    void SetHP(int );
    void SetAttack(Attack);
    void SetMove(int);
    

    int GetHP()const;
    std::string GetName()const;
    int GetMove()const;
    Attack GetAttack()const;
    void SetNode(int);
    int GetNode()const;

    void TakeDamge(int damage);
    void Heal(int heal);
    bool IsAlive()const;
    void ReduceMove(int);

    FighterType GetFighterType();

};

#endif /* FIGHTER_H */
