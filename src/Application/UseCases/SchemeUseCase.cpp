#include "Application/UseCases/SchemeUseCase.h"
#include "Domain/Entities/SchemeCard.h"
#include <iostream>

using namespace std;

bool SchemeUseCase::execute(GameState & gamestate){

    if(!CanDoAction(gamestate))return false;

    Card * card=CardSelection(gamestate.currnetPlayer->GetHero());
    auto CARD=dynamic_cast<SchemeCard *>(card);
    CARD->Play(gamestate.currnetPlayer->GetHero(),gamestate.opponentPlayre->GetHero(),&gamestate.board);
    return true;
}

bool SchemeUseCase::CanDoAction(GameState & gamestate){
    Hero * hero =gamestate.currnetPlayer->GetHero();
    if(!hero->IsExistCardInHand(CardCategory::SCHEME))
        return false;
    
    std::vector<Card *> cards=hero->GetAllCardOf(CardCategory::SCHEME);
    for(auto card:cards){
        if(card->GetOwner()==hero->GetFighterType()){
            return true;
        }
    }

    return hero->IsAliveAnySideKick();
}



Card * SchemeUseCase::CardSelection(Hero * hero){
    std::vector<Card * > cards=hero->GetHand();

    cout<< "Hand : \n";
    cout<< hero->GetHandCards()<<endl;
    int choice;
    while(true){
        cout<< "Enter a number :";
        cin>>choice;
        if(cards[choice]->GetCategory()==CardCategory::SCHEME){
            if(cards[choice]->GetOwner()!=hero->GetFighterType()){
                if(hero->IsAliveAnySideKick()){
                    break;
                }
                else cout<<" you can not use this card "<<endl;
            }
            else break;
        }
        else{
            cout<<" select a scheme card please "<<endl;
        }
    }

    return hero->GetCard(choice);
}
