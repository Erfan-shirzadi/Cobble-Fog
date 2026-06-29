#ifndef HERO_H
#define HERO_H
#include <string>
#include <vector>

class Hero {
  
    int MaxHp;
    int Hp=MaxHp;
    std::string Name ;
    int Move;
    int Range;
    int Boost;
    int node;


    public:
    void SetName(std::string);
    void SetHP(int );
    void SetRange(int);
    void SetMove(int);
    int GetHP()const;
    std::string GetName()const;
    int GetMove()const;

    void SetNode(int);
    int GetNode()const;
    

    void TakeDamge(int damage);
    void Heal(int heal);
    bool IsAlive()const;
    

};



#endif /* HERO_H */