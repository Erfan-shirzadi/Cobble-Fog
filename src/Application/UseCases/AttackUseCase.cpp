#include "Application/UseCases/AttackUseCase.h"
#include "Application/UseCases/CombatUseCase.h"
#include <iostream>
using namespace std;

bool AttackUseCase::execute(GameState & GameState){

    if(!CanAttack(GameState))return false;
    // cout<<" Here Com?"<<endl;
    // try{
    // context.Opponent->hero=GameState.opponentPlayre->GetHero();
    // }
    // catch (...){
    //     std::cout<<"Fuuuuuuuuuuuck it"<<endl;
    // }
    // cout<<" this is a problem?"<<endl;
     context.board=&GameState.board;

    FighterSelection(GameState.currnetPlayer->GetHero(),
    GameState.opponentPlayre->GetHero(),GameState.board);

    ChooseCardAttaker();
    context.Opponent=std::make_unique<CombatParticipant>();
    context.Opponent->hero=GameState.opponentPlayre->GetHero();
    TargetSelection(GameState.opponentPlayre->GetHero());
    cout<<context.Opponent->fighter->GetName()<<endl;

    ChooseCardDeffender();
    CombatUseCase combat;
    combat.execute(context);
    
    return true;




}


void AttackUseCase::ChooseCardAttaker(){
    Hero * hero=context.Current->hero;
    std::vector<Card *>cards=hero->GetHand();
    for(int i{};i<cards.size();i++)
        cout<<i<< ".  "<<cards[i]->GetName()<<endl;

    int choose;
    while (true){
        cout<<" Enter: ";
        std::cin>>choose;

        if(choose<0 || choose>=cards.size()){
            cout<<" Enter A Correct number Please"<<endl;
        }
        else if(!(cards[choose]->GetCategory()==CardCategory::ATTACK ||
                cards[choose]->GetCategory()==CardCategory::ATTACKANDDEFFENS)){
                    cout<<" Please Enter A Attack card or Attack and Deffens "<<endl;
        }
        else if( cards[choose]->GetOwner()!=FighterType::ANY && cards[choose]->GetOwner()!=context.Current->fighter->GetFighterType()){
            cout<<" you cann't Use this Card its for another fighter "<<endl;
        }
        else break;
        
    }

    context.Current->card=dynamic_cast<CombatCard *>(cards[choose]);
    
}

bool AttackUseCase::CanAttack(GameState & gamestate)const{
    Hero * hero=gamestate.currnetPlayer->GetHero();

    if(!(hero->IsExistCardInHand(CardCategory::ATTACK) ||
    hero->IsExistCardInHand(CardCategory::ATTACKANDDEFFENS)))return false;
    std::cout<<" in hand have attack or attack and deffend card"<<std::endl;
    std::vector<Card *> Attackcards=hero->GetAllCardOf(CardCategory::ATTACK);
    std::vector<Card *> AttackAndDeffenscards=hero->GetAllCardOf(CardCategory::ATTACKANDDEFFENS);
    Hero * enemy=gamestate.opponentPlayre->GetHero();

    cout<<" %%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
    for(auto card : Attackcards){
        if(card->GetOwner()==hero->GetFighterType()|| card->GetOwner()==FighterType::ANY){
            if(IsInChanceAttack(dynamic_cast<Fighter*>(hero),enemy,gamestate.board))
                return true;
        }
    }
    cout<<"*****************"<<endl;
    for(auto card : Attackcards)
    {
        if(card->GetOwner()!=hero->GetFighterType())
            for(auto fighter: hero->GetSideKicks())
                if(IsInChanceAttack(fighter,enemy,gamestate.board))
                    return true;
    }
    cout<<" ########################"<<endl;
    
    for(auto card : AttackAndDeffenscards){
        if(card->GetOwner()==hero->GetFighterType() || card->GetOwner()==FighterType::ANY){
            if(IsInChanceAttack(dynamic_cast<Fighter*>(hero),enemy,gamestate.board))
                return true;
        }
    }
    cout<<" &&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
    for(auto card : AttackAndDeffenscards){
        if(card->GetOwner()!=hero->GetFighterType()){
            for(auto fighter: hero->GetSideKicks())
                if(IsInChanceAttack(fighter,enemy,gamestate.board))
                    return true;
        }
    }
    cout<<" )))))))))))))))))))))))))))))"<<endl;
    return false;

}

bool AttackUseCase::IsInChanceAttack(Fighter * fighter,Hero * enemy ,Board & borad)const{
    Attack type=fighter->GetAttack();
    std::vector<Fighter*> enemies=enemy->GetSideKicks();
    enemies.push_back(dynamic_cast<Fighter*>(enemy));

    std::cout<< " cheking chance attack "<<fighter->GetName()<<endl;
    int nodeFighter=fighter->GetNode();
    if(type==Attack::MELEE){
        for(auto ENEMY:enemies){
            if(borad.AreAdjacent(nodeFighter,ENEMY->GetNode())){
                cout<<fighter->GetName()<< " and "<<ENEMY->GetName()<<"are hamsaye"<<endl;
                if(!(borad.GetNodeType(nodeFighter)==NodeType::SECREST &&
                    borad.GetNodeType(ENEMY->GetNode())==NodeType::SECREST)){
                        cout<<" returned true"<<endl;
                        return true;
                    }
                        
            }
        }
    }
    else if(type==Attack::RANGED){
        for(auto ENEMY: enemies){
            if(borad.IsAnArea(ENEMY->GetNode(),nodeFighter))
                return true;
        }
    }
    cout<<" This is a test "<<endl;
    return false;
}



void AttackUseCase::FighterSelection(Hero * hero ,Hero * enemy ,Board & borad){

    std::vector<Fighter * > fighters=hero->GetSideKicks();
    fighters.push_back(dynamic_cast<Fighter *>(hero));

    cout<<" your Fighters :"<<endl;
    for( int i{};i<fighters.size();i++){
        cout<< i <<".  "<<fighters[i]->GetName()<<endl;
    }
    int choice ;

    while(true){
        cout<<"Enter :";
        cin>>choice;
        if(choice<0 ||choice>=fighters.size())
            cout<<" Entetr a correct number please "<<endl;
        else if(!IsInChanceAttack(fighters[choice],enemy,borad)){
            cout<<" can not attack with this Fighter "<<endl;
        }
        else break;
    }
    context.Current=std::make_unique<CombatParticipant>();
    this->context.Current->fighter=fighters[choice];
    this->context.Current->hero=hero;

}

void AttackUseCase::TargetSelection(Hero *enemy){

    // Hero * enemy=c;
    Board * board=context.board;
    Fighter * fighter=context.Current->fighter;

    std::vector<Fighter *> enemies=enemy->GetSideKicks();
    enemies.push_back(dynamic_cast<Fighter *>(enemy));
    cout<<" Enemies: "<<endl;
    for(int i{};i<enemies.size();i++){
        cout<<i<< ".  "<<enemies[i]->GetName();
    }
    int choice;
    while(true){
        cout<<"Enter:";
        cin>>choice;

        if(choice<0 || choice>=enemies.size())
            cout<<" ENter A correct number Please "<<endl;
        else if(!board->AreAdjacent(fighter->GetNode(),enemies[choice]->GetNode())){
            cout<<" you can not attack this fighter "<<endl;
        }
        else if(board->AreAdjacent(fighter->GetNode(),enemies[choice]->GetNode())){
            if(board->GetNodeType(fighter->GetNode())==NodeType::SECREST &&
            board->GetNodeType(enemies[choice]->GetNode())==NodeType::SECREST)
            cout<<" You can not attack from secrect path "<<endl;
            else{
                cout<<" breaked"<<endl;
                break;
            }
        }
    }
    context.Opponent->fighter=enemies[choice];
    cout<< " end of Terget selection"<<endl;
}



void AttackUseCase::ChooseCardDeffender(){
    cout<< " Enter : ppppppp;lewaseesssee"<<endl;
    Hero * hero=context.Opponent->hero;
    if(!(hero->IsExistCardInHand(CardCategory::DEFFENSE )|| hero->IsExistCardInHand(CardCategory::ATTACKANDDEFFENS))){
        cout<<" Deffend broken . you havenot any card for deffend "<<endl;
    }else{
            bool canDeffend=false;
            std::vector<Card *> Deffensecards=hero->GetAllCardOf(CardCategory::DEFFENSE);
            std::vector<Card *> AttackAndDeffenscards=hero->GetAllCardOf(CardCategory::ATTACKANDDEFFENS);
            for(auto card:Deffensecards){
                if(card->GetOwner()==context.Opponent->fighter->GetFighterType())
                    canDeffend=true;
            }
            for(auto card: AttackAndDeffenscards){
                if(card->GetOwner()==context.Opponent->fighter->GetFighterType())
                    canDeffend=true;
            }
        if(canDeffend){
            std::string temp;
            cout<< " Do you wnat deffend ? (Y/N)";
            cin>> temp;

            if(temp=="Y"){
    
            std::vector<Card *>cards=hero->GetHand();
            for(int i{};i<cards.size();i++)
                cout<<i<< ".  "<<cards[i]->GetName()<<endl;

            int choose;
            while (true){
                cout<<" Enter: ";
                std::cin>>choose;

                if(choose<0 || choose>=cards.size()){
                    cout<<" Enter A Correct number Please"<<endl;
                }
                else if(!(cards[choose]->GetCategory()==CardCategory::DEFFENSE ||
                        cards[choose]->GetCategory()==CardCategory::ATTACKANDDEFFENS)){
                            cout<<" Please Enter A Deffens card or Attack and Deffens "<<endl;
                }
                else if( cards[choose]->GetOwner()!=FighterType::ANY && cards[choose]->GetOwner()!=context.Current->fighter->GetFighterType()){
                    cout<<" you cann't Use this Card its for another fighter "<<endl;
                }
                else break;
                
            }

            context.Opponent->card=dynamic_cast<CombatCard *>(cards[choose]);
            }
        }
        else {
            std::cout<< " you Dont have for deffend that belong to you "<<std::endl;
        }
    }

}



