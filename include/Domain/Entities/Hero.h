#ifndef HERO_H
#define HERO_H
#include <string>
#include <vector>
#include "Domain/Entities/Card.h"
#include "Domain/Entities/Fighter.h"
class Hero :public Fighter{
  



    std::vector <Card> Hand;
    std::vector <Card> Deck;

    public:
    Hero(std::string name ,int hp ,int move, FighterType type);
    Card GetCard(int index);

    void RemoveCardHand(int index);

    void AddCardToHand(Card);
    Card GetRandomCard();
    virtual Fighter * GetSideKick();
    //virtual void SpecialAbility()=0;
    

};



#endif /* HERO_H */