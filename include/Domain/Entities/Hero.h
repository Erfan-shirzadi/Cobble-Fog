#ifndef HERO_H
#define HERO_H
#include <string>
#include <vector>
#include "Domain/Entities/Card.h"
class Hero {
  
    int MaxHp;
    int Hp=MaxHp;
    std::string Name ;
    int Move;
    int Range;
    int BaseBoost;
    int CurrentBoost;
    int node;


    std::vector <Card> Hand;
    std::vector <Card> Deck;
    public:
    void SetName(std::string);
    void SetHP(int );
    void SetRange(int);
    void SetMove(int);
    void SetBoost(int);
    

    int GetHP()const;
    std::string GetName()const;
    int GetMove()const;
    int GetBoost() const;
    Card GetCard(int index);

    void RemoveCardHand(int index);

    void SetNode(int);
    int GetNode()const;
    

    void TakeDamge(int damage);
    void Heal(int heal);
    bool IsAlive()const;

    void AddCardToHand(Card);
    Card GetRandomCard();
    

};



#endif /* HERO_H */