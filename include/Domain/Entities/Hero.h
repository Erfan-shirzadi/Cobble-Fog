#ifndef HERO_H
#define HERO_H
#include <string>
#include <vector>
#include <memory>
#include "Domain/Entities/Card.h"
#include "Domain/Entities/Deck.h"
#include "Domain/Entities/Fighter.h"
class Hero :public Fighter{
  



    std::vector <std::unique_ptr<Card>> Hand;
    std::vector<std::unique_ptr<Card>> DiscardCards;
    Deck deck;
    int RemainingAction=2;

    public:
    Hero(std::string name ,int hp ,int move, FighterType type);
    Card* GetCard(int index);
    void RemoveCardHand(int index);
    void AddCardToHand(std::unique_ptr<Card> card);
    virtual std::vector<Fighter *> GetSideKicks();
    //virtual void SpecialAbility()=0;
    bool IsExistCardInHand(CardCategory);
    int GetSizeHand()const;
    void DrawCard();
    std::vector<Card * > GetHand()const;
    void AddCardToDeck(std::unique_ptr<Card> card);
    void ShuffelDeck();

    int GetRemainingAction();
    void SetRemainingAction(int );
    void AddAction();
    std::vector<Card* > GetAllCardOf(CardCategory)const;
    virtual bool IsAliveAnySideKick();

};



#endif /* HERO_H */