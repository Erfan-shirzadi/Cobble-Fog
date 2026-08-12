#include "Domain/Entities/Hero.h" 
#include <cstdlib>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>

 Hero::Hero(std::string name,int hp, int move,FighterType type):Fighter(name,hp,move,type){
 }

Card* Hero::GetCard(int index){
      if(index<0 ||index>=Hand.size())
            throw std::runtime_error("Enter a correct number ");
      RemoveCardHand(index);
      return DiscardCards.back().get();
}

void Hero::RemoveCardHand(int index){
      if(index<0 ||index>=Hand.size())
            throw std::runtime_error("Enter a correct number ");
      std::swap(Hand[index],Hand.back());
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


bool Hero::DrawCard(){
      
      this->Hand.push_back(std::move(deck.Draw()));
      return true;
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
void Hero::reduceRemainingAction(){
      --this->RemainingAction;
}


std::string Hero::GetHandCards()const{
      std::stringstream out;
      for(int i{};i<Hand.size();i++){
            out <<"  "<<Hand[i]->GetName()<<std::endl;
      }

      return out.str();
}     

Fighter * Hero::GetDeadSideKick()const{
      return nullptr;
}

int Hero::GetDeckSize(){
      return deck.Size();
}


bool Hero::IsExistCardOfFighterInhandForAttack(FighterType fighter){
      for(int i{};i<Hand.size();i++){
            if(Hand[i]->GetCategory()==CardCategory::ATTACK || Hand[i]->GetCategory()==CardCategory::ATTACKANDDEFFENS)
                  if(Hand[i]->GetOwner()==fighter ||Hand[i]->GetOwner()==FighterType::ANY)
                        return true;
      }

      return false;
}


void Hero::DiscardCard(Card * card){

      for(int i{};i<Hand.size();i++){
            if(Hand[i].get()==card){
                  std::swap(Hand[i],Hand.back());
                  this->DiscardCards.push_back(std::move(Hand.back()));
                  this->Hand.pop_back();
                  return;
            }
      }
}
std::vector<Fog*> Hero::GetFogs(){
      std::vector<Fog*> f;
      return f;
}


void Hero::ReturnCardToDeck(int index){
      AddCardToDeck(std::move(Hand[index]));
      std::swap(Hand[index],Hand.back());
      Hand.pop_back();
}

void Hero::SetPositionOnStartTurn(){
      nodeOnStartTurn=this->GetNode();
}
int Hero::GetPositionOnStartTurn()const{
      return nodeOnStartTurn;
}
