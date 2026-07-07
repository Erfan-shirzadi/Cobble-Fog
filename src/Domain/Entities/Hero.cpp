#include "Domain/Entities/Hero.h" 
#include <cstdlib>
#include <algorithm>
#include <stdexcept>

 Hero::Hero(std::string name,int hp, int move,FighterType type):Fighter(name,hp,move,type){
 }

Card* Hero::GetCard(int index){
      if(index<1 ||index>Hand.size())
            throw std::runtime_error("Enter a correct number ");
      RemoveCardHand(index);
      return DiscardCards.back().get();
}

void Hero::RemoveCardHand(int index){
      if(index<1 ||index>Hand.size())
            throw std::runtime_error("Enter a correct number ");
            
      std::swap(Hand[index-1],Hand[Hand.size()-1]);
      this->DiscardCards.push_back(std::move(Hand.back()));
      this->Hand.pop_back();
}

int Hero::GetSizeHand()const{
      return Hand.size();
}

void Hero::AddCardToHand(std::unique_ptr<Card> card){
      this->Hand.push_back(std::move(card));
}

std::vector<Fighter *> Hero::GetSideKicks(){
      return {nullptr};
 }


bool Hero::IsExistCardInHand(CardCategory askcategory){
      for(int i{};i<Hand.size();i++){
            if(Hand[i].get()->GetCategory()==askcategory)
                  return true;
      }

      return false;
}


void Hero::DrawCard(){
     this->Hand.push_back(std::move(deck.Draw()));
}

std::vector<Card * > Hero::GetHand()const{
      std::vector<Card *> hand;
      for(int i{};i<Hand.size();i++){
            hand.push_back(Hand[i].get());
      }
      return hand;
}

std::vector<Card* > Hero::GetAllCardOf(CardCategory cardcategory)const{
      std::vector<Card *> res;
      for(int i{};i<Hand.size();i++){
            if(Hand[i].get()->GetCategory()==cardcategory)
                  res.push_back(Hand[i].get());
      }
      return res;
}

void Hero::AddCardToDeck(std::unique_ptr<Card> card){
      this->deck.Add(std::move(card));
}

void Hero::ShuffelDeck(){
      this->deck.Shuffle();
}


int Hero::GetRemainingAction(){
      return this->RemainingAction;
}
void Hero::SetRemainingAction(int amount ){
      this->RemainingAction=amount;
}
void Hero::AddAction(){
      ++this->RemainingAction;
}

bool Hero::IsAliveAnySideKick(){
      return false;
}
