#ifndef DECK_H
#define DECK_H
#include "Domain/Entities/Card.h"
#include <vector>
#include <memory>

class Deck{

    std::vector<std::unique_ptr<Card>> deck;

    public:

    void Shuffle();
    void Add(std::unique_ptr<Card>);
    std::unique_ptr<Card> Draw();
    bool Empty()const;
    int Size()const;
    std::vector <CardId> GetCards();
    void ClearDeck();

};

#endif /* DECK_H */
