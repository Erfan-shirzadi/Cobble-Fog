#ifndef HERO_H
#define HERO_H
#include <string>
#include <vector>
#include <memory>
#include "Domain/Entities/Card.h"
#include "Domain/Entities/Deck.h"
#include "Domain/Entities/Fighter.h"
#include "Domain/Entities/Fog.h"
struct GameState;
class Hero :public Fighter{
  



    std::vector <std::unique_ptr<Card>> Hand;
    std::vector<std::unique_ptr<Card>> DiscardCards;
    Deck deck;
    int RemainingAction=2;
    bool OnFoginStartTurn=false;

    public:
    Hero(std::string name ,int hp ,int move, FighterType type);
    Card* GetCard(int index);
    void RemoveCardHand(int index);
    void AddCardToHand(std::unique_ptr<Card> card);
    virtual std::vector<Fighter *> GetSideKicks();
    virtual void Ability(GameState&)=0;
    virtual bool CanUseCability(GameState)=0;
    bool IsExistCardInHand(CardCategory);
    bool IsExistCardOfFighterInhandForAttack(FighterType);
    int GetSizeHand()const;
    bool DrawCard();
    std::vector<Card * > GetHand()const;
    void AddCardToDeck(std::unique_ptr<Card> card);
    void ShuffelDeck();

    int GetRemainingAction();
    void SetRemainingAction(int );
    void reduceRemainingAction();
    void AddAction();
    std::vector<Card* > GetAllCardOf(CardCategory)const;
    virtual bool IsAliveAnySideKick();


    std::string GetHandCards()const;

    virtual Fighter * GetDeadSideKick()const;

    int GetDeckSize();
    void DiscardCard(Card *);
    virtual std::vector<Fog *> GetFogs();

    void ReturnCardToDeck(int index);
    void SetStartTurnOnfog(bool);
    bool GetStartTurnOnfog();

};



#endif /* HERO_H */