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
   
    Card GetCard(int index);

    void RemoveCardHand(int index);


    void AddCardToHand(Card);
    Card GetRandomCard();
    

};



#endif /* HERO_H */