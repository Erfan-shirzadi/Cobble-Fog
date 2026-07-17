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
     combatcontext.board=&GameState.board;

    FighterSelection(GameState.currnetPlayer->GetHero(),
    GameState.opponentPlayre->GetHero(),GameState.board);

    ChooseCardAttaker();
    combatcontext.Opponent=std::make_unique<CombatParticipant>();
    combatcontext.Opponent->hero=GameState.opponentPlayre->GetHero();
    TargetSelection(GameState.opponentPlayre->GetHero());
    cout<<combatcontext.Opponent->fighter->GetName()<<endl;

    ChooseCardDeffender();
    CombatUseCase combat;
    combat.execute(combatcontext);
    
    return true;




}


void AttackUseCase::ChooseCardAttaker(){
    Hero * hero=combatcontext.Current->hero;
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
        else if( cards[choose]->GetOwner()!=FighterType::ANY && cards[choose]->GetOwner()!=combatcontext.Current->fighter->GetFighterType()){
            cout<<" you cann't Use this Card its for another fighter "<<endl;
        }
        else break;
        
    }

    combatcontext.Current->card=dynamic_cast<CombatCard *>(hero->GetCard(choose));
    
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
            if(borad.IsAnArea(ENEMY->GetNode(),nodeFighter)){
                return true;
            }
            else if(borad.AreAdjacent(ENEMY->GetNode(),nodeFighter)){
                    if(!(borad.GetNodeType(nodeFighter)==NodeType::SECREST &&
                           borad.GetNodeType(ENEMY->GetNode())==NodeType::SECREST)){
                            cout<<" returned true"<<endl;
                            return true;
                    }
            }
                
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
    combatcontext.Current=std::make_unique<CombatParticipant>();
    this->combatcontext.Current->fighter=fighters[choice];
    this->combatcontext.Current->hero=hero;

}

void AttackUseCase::TargetSelection(Hero *enemy){

    // Hero * enemy=c;
    Board * board=combatcontext.board;
    Fighter * fighter=combatcontext.Current->fighter;

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
    combatcontext.Opponent->fighter=enemies[choice];
    cout<< " end of Terget selection"<<endl;
}



void AttackUseCase::ChooseCardDeffender(){
    cout<< " Enter : ppppppp;lewaseesssee"<<endl;
    Hero * hero=combatcontext.Opponent->hero;
    if(!(hero->IsExistCardInHand(CardCategory::DEFFENSE )|| hero->IsExistCardInHand(CardCategory::ATTACKANDDEFFENS))){
        cout<<" Deffend broken . you havenot any card for deffend "<<endl;
    }else{
            bool canDeffend=false;
            std::vector<Card *> Deffensecards=hero->GetAllCardOf(CardCategory::DEFFENSE);
            std::vector<Card *> AttackAndDeffenscards=hero->GetAllCardOf(CardCategory::ATTACKANDDEFFENS);
            for(auto card:Deffensecards){
                if(card->GetOwner()==combatcontext.Opponent->fighter->GetFighterType()||card->GetOwner()==FighterType::ANY)
                    canDeffend=true;
            }
            for(auto card: AttackAndDeffenscards){
                if(card->GetOwner()==combatcontext.Opponent->fighter->GetFighterType()||card->GetOwner()==FighterType::ANY)
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
                else if( cards[choose]->GetOwner()!=FighterType::ANY && cards[choose]->GetOwner()!=combatcontext.Opponent->fighter->GetFighterType()){
                    cout<<" you cann't Use this Card its for another fighter "<<endl;
                }
                else break;
                
            }

            combatcontext.Opponent->card=dynamic_cast<CombatCard *>(hero->GetCard(choose));
            }
        }
        else {
            std::cout<< " you Dont have for deffend that belong to you "<<std::endl;
        }
    }

}



ContinueResult AttackUseCase::Continue(ActionContext&){
    
    switch (attackstep)
    {
    case AttackStep::SETUP:
        /* code */
        break;
    case AttackStep::COMBAT:

        break;
    case AttackStep::FINISHED:

        break;
    }
    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}

void AttackUseCase::Start(ActionContext& context){
    context.Selected=-1;
    setupstep=SetUpStep::CHOOSE_ATTACKER;
    attackstep=AttackStep::SETUP;
}


ContinueResult AttackUseCase::SetUp(ActionContext&context){

    switch (setupstep)
    {
    case SetUpStep::CHOOSE_ATTACKER:
        return BuildAttakerMenu(context);
        break;
    case SetUpStep::CHOOSE_ATTACKER_CARD:
        /* code */
        break;
    case SetUpStep::CHOOSE_DEFFENDER:
        /* code */
        break;
    case SetUpStep::CHOOSE_DEFFENDER_CARD:
        /* code */
        break;

    default:
        break;
    }

}
ContinueResult Finished(ActionContext&);
ContinueResult Combat(ActionContext&);


ContinueResult AttackUseCase::BuildAttakerMenu(ActionContext & context){
    ContinueResult result;
    Hero* attaker=context.Gamestate->currnetPlayer->GetHero();
    Hero * Deffender=context.Gamestate->opponentPlayre->GetHero();
    std::vector<Fighter*> allattacker;
    allattacker.push_back(dynamic_cast<Fighter*>(attaker));
    for(auto sidekick:attaker->GetSideKicks()){
        allattacker.push_back(sidekick);
    }

    for(auto fighter: allattacker){
        if(IsInChanceAttack(fighter,Deffender,context.Gamestate->board)){
            Attacker.push_back(fighter);
            result.menu_request.options.push_back(fighter->GetName());
        }
    }
    result.status=ContinueStatus::NEEDMENU;
    result.menu_request.title="Fighters in Chance";

    return result;

    
} 

ContinueResult AttackUseCase::ChooseAttaker(ActionContext & context ){
    if(context.Selected==-1) return BuildAttakerMenu(context);

    
    combatcontext.Current=std::make_unique<CombatParticipant>();
    combatcontext.Current->hero=context.Gamestate->currnetPlayer->GetHero();
    combatcontext.Current->fighter=Attacker[context.Selected];
    context.Selected=-1;
    ContinueResult result;
    result.status=ContinueStatus::CONTINUE;
    setupstep=SetUpStep::CHOOSE_ATTACKER_CARD;

    return result;
}

ContinueResult AttackUseCase::BuildAttackerCardMenu(ActionContext & ){
    Hero * hero=combatcontext.Current->hero;
    ContinueResult result;
    for(auto card: hero->GetHand()){
        if(card->GetCategory()==CardCategory::ATTACK || card->GetCategory()==CardCategory::ATTACKANDDEFFENS)
            if(card->GetOwner()==combatcontext.Current->fighter->GetFighterType()||card->GetOwner()==FighterType::ANY){
                result.menu_request.options.push_back(card->GetName());
                AttackerCards.push_back(card);
            }
    }
    result.menu_request.title="Cards";
    result.status=ContinueStatus::NEEDMENU;
    return result;
}

ContinueResult AttackUseCase::ChooseAttckerCard(ActionContext & context ){
    if(context.Selected==-1) return BuildAttackerCardMenu(context);

    combatcontext.Current->card=dynamic_cast<CombatCard*>(AttackerCards[context.Selected]);
    setupstep=SetUpStep::CHOOSE_DEFFENDER;
    context.Selected=-1;
    ContinueResult result;
    result.status=ContinueStatus::CONTINUE;

    return result;


}
