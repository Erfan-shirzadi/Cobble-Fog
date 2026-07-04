#include "Domain/Entities/Hero.h" 
#include <cstdlib>
#include <algorithm>
#include <stdexcept>

 Hero::Hero(std::string name,int hp, int move,FighterType type):Fighter(name,hp,move,type){
 }

Card* Hero::GetCard(int index){
      if(index<1 ||index>Hand.size())
            throw std::runtime_error("Enter a correct number ");
      return this->Hand[index-1].get();
}

void Hero::RemoveCardHand(int index){
      std::swap(Hand[index-1],Hand[Hand.size()-1]);
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
