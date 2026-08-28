#include "Domain/Entities/Deck.h"
#include <random>
#include <algorithm>
#include <iostream>


void Deck::Shuffle(){
    std::random_device rd;
    std::mt19937 generator(rd());

    std::shuffle(deck.begin(),deck.end(),generator);
}
void Deck::Add(std::unique_ptr<Card> card){
    this->deck.push_back(std::move(card));
}
std::unique_ptr<Card> Deck::Draw(){
    auto card = std::move(deck.back());
    deck.pop_back();
    return card;
}
bool Deck::Empty()const{
    return this->deck.size()==0;
}
int Deck::Size()const{
    return this->deck.size();
}

std::vector <CardId> Deck::GetCards(){
    std::vector <CardId> res;
    for(int i{};i<deck.size();i++){
        res.push_back(deck[i]->GetCardId());
    }
    return res;
}
 
void Deck::ClearDeck(){
    this->deck.clear();
}