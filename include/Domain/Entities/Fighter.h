#ifndef FIGHTER_H
#define FIGHTER_H
#include <string>
#include "Domain/enums/FighterType.h"
class Fighter{

    int MaxHp;
    int Hp=MaxHp;
    std::string Name ;
    int Move;
    int Range;
    int BaseBoost;
    int CurrentBoost;
    int node=0;

    FighterType fightertype;

    public:
    Fighter(std::string ,int Hp, int move ,FighterType);

    void SetName(std::string);
    void SetHP(int );
    void SetRange(int);
    void SetMove(int);
    void SetBoost(int);
    

    int GetHP()const;
    std::string GetName()const;
    int GetMove()const;
    int GetBoost() const;

    void SetNode(int);
    int GetNode()const;

    void TakeDamge(int damage);
    void Heal(int heal);
    bool IsAlive()const;

    FighterType GetFighterType();

};

#endif /* FIGHTER_H */
