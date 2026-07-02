#ifndef HERO_H
#define HERO_H
#include <string>
#include <vector>
#include <memory>
#include "Domain/Entities/Card.h"
#include "Domain/Entities/Fighter.h"
class Hero :public Fighter{
  



    std::vector <std::unique_ptr<Card>> Hand;
    std::vector <Card> Deck;

    public:
    Hero(std::string name ,int hp ,int move, FighterType type);
    Card* GetCard(int index);

    void RemoveCardHand(int index);

    void AddCardToHand(std::unique_ptr<Card> card);
    Card GetRandomCard();
    virtual std::vector<Fighter *> GetSideKicks();
    //virtual void SpecialAbility()=0;
    

};



#endif /* HERO_H */