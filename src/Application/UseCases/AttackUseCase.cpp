#include "Application/UseCases/AttackUseCase.h"
#include <iostream>
void AttackUseCase::ChooseCardAttaker(GameState & gamestate)const{
    Hero * hero=gamestate.currnetPlayer->GetHero();
    // std::cout<< " show hand : "<<std::endl;
    // int choose;
    // while (true){
    //     std::cin>>choose;
    //     Card * cardd=hero->GetCard(choose);
    //     CombatCard * card=dynamic_cast<CombatCard * > (cardd);
    //     if(card){
    //         if(card->GetCategory()==CardCategory::ATTACK ||card->GetCategory()==CardCategory::ATTACKANDDEFFENS){
    //             this->context.Current->card=cardd;
    //             break;
    //         }
    //         else std::cout<< " Select A Correct card ";
    //     }
    //     else std::cout<< " Select A Correct card ";
        
    // }
    
}
bool AttackUseCase::CanAttack(GameState & gamestate)const{
    Hero * hero=gamestate.currnetPlayer->GetHero();
   std::vector<Card *> cards= gamestate.currnetPlayer->GetHero()->GetHand();

    if(!(hero->IsExistCardInHand(CardCategory::ATTACK) ||
    hero->IsExistCardInHand(CardCategory::ATTACKANDDEFFENS)))return false;

    std::vector<Card *> Attackcards=hero->GetAllCardOf(CardCategory::ATTACK);
    std::vector<Card *> AttackAndDeffenscards=hero->GetAllCardOf(CardCategory::ATTACKANDDEFFENS);
    Hero * enemy=gamestate.opponentPlayre->GetHero();

    for(auto card : Attackcards){
        if(card->GetOwner()==hero->GetFighterType()){
            if(IsInChanceAttack(dynamic_cast<Fighter*>(hero),enemy,gamestate.board))
                return true;
        }
    }
    for(auto card : Attackcards)
    {
        if(card->GetOwner()!=hero->GetFighterType())
            for(auto fighter: hero->GetSideKicks())
                if(IsInChanceAttack(fighter,enemy,gamestate.board))
                    return true;
    }

    
    for(auto card : AttackAndDeffenscards){
        if(card->GetOwner()==hero->GetFighterType()){
            if(IsInChanceAttack(dynamic_cast<Fighter*>(hero),enemy,gamestate.board))
                return true;
        }
    }
    for(auto card : AttackAndDeffenscards){
        if(card->GetOwner()!=hero->GetFighterType()){
            for(auto fighter: hero->GetSideKicks())
                if(IsInChanceAttack(fighter,enemy,gamestate.board))
                    return true;
        }
    }
    return false;

}

bool AttackUseCase::IsInChanceAttack(Fighter * fighter,Hero * enemy ,Board borad)const{
    Attack type=fighter->GetAttack();
    std::vector<Fighter*> enemies=enemy->GetSideKicks();
    enemies.push_back(dynamic_cast<Fighter*>(enemy));

    int nodeFighter=fighter->GetNode();
    if(type==Attack::MELEE){
        for(auto ENEMY:enemies){
            if(borad.AreAdjacent(nodeFighter,ENEMY->GetNode()))
                if(!(borad.GetNodeType(nodeFighter)==NodeType::SECREST &&
                    borad.GetNodeType(ENEMY->GetNode())==NodeType::SECREST))
                        return true;
        }
    }
    else if(type==Attack::RANGED){
        for(auto ENEMY: enemies){
            if(borad.IsAnArea(ENEMY->GetNode(),nodeFighter))
                return true;
        }
    }
    return false;
}
