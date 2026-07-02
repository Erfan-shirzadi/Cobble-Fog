#include "Domain/Entities/Hero.h" 
#include <cstdlib>
#include <algorithm>


 Hero::Hero(std::string name,int hp, int move,FighterType type):Fighter(name,hp,move,type){
 }

Card* Hero::GetCard(int index){
      return this->Hand[index-1].get();
}

void Hero::RemoveCardHand(int index){
      std::swap(Hand[index-1],Hand[Hand.size()-1]);
      this->Hand.pop_back();
}




void Hero::AddCardToHand(std::unique_ptr<Card> card){
      this->Hand.push_back(std::move(card));
}
// Card  Hero::GetRandomCard(){
//    int RandomIndex=rand()%this->Deck.size();
//    Card * card=&Deck[RandomIndex];

//    std::swap(Deck[RandomIndex],Deck[Deck.size()-1]);
//    Deck.pop_back();
//    return card;
// }

std::vector<Fighter *> Hero::GetSideKicks(){
      return {nullptr};
 }
