#include "Application/UseCases/AttackUseCase.h"
#include "Application/UseCases/CombatUseCase.h"
#include <iostream>
using namespace std;

// bool AttackUseCase::execute(GameState & GameState){

//     if(!CanAttack(GameState))return false;
//     // cout<<" Here Com?"<<endl;
//     // try{
//     // context.Opponent->hero=GameState.opponentPlayre->GetHero();
//     // }
//     // catch (...){
//     //     std::cout<<"Fuuuuuuuuuuuck it"<<endl;
//     // }
//     // cout<<" this is a problem?"<<endl;
//      combatcontext.board=&GameState.board;

//     FighterSelection(GameState.currnetPlayer->GetHero(),
//     GameState.opponentPlayre->GetHero(),GameState.board);

//     ChooseCardAttaker();
//     combatcontext.Opponent=std::make_unique<CombatParticipant>();
//     combatcontext.Opponent->hero=GameState.opponentPlayre->GetHero();
//     TargetSelection(GameState.opponentPlayre->GetHero());
//     cout<<combatcontext.Opponent->fighter->GetName()<<endl;

//     ChooseCardDeffender();
//     CombatUseCase combat;
//     combat.execute(combatcontext);
    
//     return true;




// }


// void AttackUseCase::ChooseCardAttaker(){
//     Hero * hero=combatcontext.Current->hero;
//     std::vector<Card *>cards=hero->GetHand();
//     for(int i{};i<cards.size();i++)
//         cout<<i<< ".  "<<cards[i]->GetName()<<endl;

//     int choose;
//     while (true){
//         cout<<" Enter: ";
//         std::cin>>choose;

//         if(choose<0 || choose>=cards.size()){
//             cout<<" Enter A Correct number Please"<<endl;
//         }
//         else if(!(cards[choose]->GetCategory()==CardCategory::ATTACK ||
//                 cards[choose]->GetCategory()==CardCategory::ATTACKANDDEFFENS)){
//                     cout<<" Please Enter A Attack card or Attack and Deffens "<<endl;
//         }
//         else if( cards[choose]->GetOwner()!=FighterType::ANY && cards[choose]->GetOwner()!=combatcontext.Current->fighter->GetFighterType()){
//             cout<<" you cann't Use this Card its for another fighter "<<endl;
//         }
//         else break;
        
//     }

//     combatcontext.Current->card=dynamic_cast<CombatCard *>(hero->GetCard(choose));
    
//}

bool AttackUseCase::CanAttack(GameState & gamestate)const{
    Hero * hero=gamestate.currnetPlayer->GetHero();

    if(!(hero->IsExistCardInHand(CardCategory::ATTACK) ||
    hero->IsExistCardInHand(CardCategory::ATTACKANDDEFFENS)))return false;
    std::vector<Card *> Attackcards=hero->GetAllCardOf(CardCategory::ATTACK);
    std::vector<Card *> AttackAndDeffenscards=hero->GetAllCardOf(CardCategory::ATTACKANDDEFFENS);
    Hero * enemy=gamestate.opponentPlayre->GetHero();

    for(auto card : Attackcards){
        if(card->GetOwner()==hero->GetFighterType()|| card->GetOwner()==FighterType::ANY){
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
        if(card->GetOwner()==hero->GetFighterType() || card->GetOwner()==FighterType::ANY){
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

bool AttackUseCase::IsInChanceAttack(Fighter * fighter,Hero * enemy ,Board & borad)const{
    Attack type=fighter->GetAttack();
    std::vector<Fighter*> enemies=enemy->GetSideKicks();
    enemies.push_back(dynamic_cast<Fighter*>(enemy));

    int nodeFighter=fighter->GetNode();
    if(type==Attack::MELEE){
        for(auto ENEMY:enemies){
            if(borad.AreAdjacent(nodeFighter,ENEMY->GetNode())){
                if(!(borad.GetNodeType(nodeFighter)==NodeType::SECREST &&
                    borad.GetNodeType(ENEMY->GetNode())==NodeType::SECREST)){
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
                            return true;
                    }
            }
                
        }
    }
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



ContinueResult AttackUseCase::Continue(EffectContext& context){
    
    switch (attackstep)
    {
    case AttackStep::SETUP:
        return SetUp(context);
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

void AttackUseCase::Start(EffectContext& context){
    context.context.Selected=-1;
    setupstep=SetUpStep::CHOOSE_ATTACKER;
    attackstep=AttackStep::SETUP;
}


ContinueResult AttackUseCase::SetUp(EffectContext&context){

    switch (setupstep)
    {
    case SetUpStep::CHOOSE_ATTACKER:
        return ChooseAttaker(context);
        break;
    case SetUpStep::CHOOSE_ATTACKER_CARD:
        return ChooseAttckerCard(context);
        break;
    case SetUpStep::CHOOSE_DEFFENDER:
        return ChooseDeffender(context);
    case SetUpStep::ASK_FOR_DEFFEND:
        return AskForDeffend(context);
        break;
    case SetUpStep::CHOOSE_DEFFENDER_CARD:
        return ChooseDeffenderCard(context);
        break;

    default:{
        ContinueResult res;
        res.status=ContinueStatus::FINISHED;
        return res;
    }
    }

}
ContinueResult Finished(ActionContext&){


}

ContinueResult Combat(ActionContext&){
    
}


ContinueResult AttackUseCase::BuildAttakerMenu(EffectContext & context){
    ContinueResult result;
    Hero* attaker=context.context.Gamestate->currnetPlayer->GetHero();
    Hero * Deffender=context.context.Gamestate->opponentPlayre->GetHero();
    std::vector<Fighter*> allattacker;
    allattacker.push_back(dynamic_cast<Fighter*>(attaker));
    for(auto sidekick:attaker->GetSideKicks()){
        allattacker.push_back(sidekick);
    }

    for(auto fighter: allattacker){
        if(IsInChanceAttack(fighter,Deffender,context.context.Gamestate->board)){
            Attacker.push_back(fighter);
            result.menu_request.options.push_back(fighter->GetName());
        }
    }
    result.status=ContinueStatus::NEEDMENU;
    result.menu_request.title="Fighters in Chance";

    return result;

    
} 

ContinueResult AttackUseCase::ChooseAttaker(EffectContext & context ){
    if(context.context.Selected==-1) return BuildAttakerMenu(context);

    
    combatcontext.Current=std::make_unique<CombatParticipant>();
    combatcontext.Opponent=std::make_unique<CombatParticipant>();
    combatcontext.Opponent->hero=context.context.Gamestate->opponentPlayre->GetHero();
    combatcontext.Current->hero=context.context.Gamestate->currnetPlayer->GetHero();
    combatcontext.Current->fighter=Attacker[context.context.Selected];
    context.context.Selected=-1;
    ContinueResult result;
    result.status=ContinueStatus::CONTINUE;
    setupstep=SetUpStep::CHOOSE_ATTACKER_CARD;

    return result;
}

ContinueResult AttackUseCase::BuildAttackerCardMenu(EffectContext & ){
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

ContinueResult AttackUseCase::ChooseAttckerCard(EffectContext & context ){
    if(context.context.Selected==-1) return BuildAttackerCardMenu(context);

    combatcontext.Current->card=dynamic_cast<CombatCard*>(AttackerCards[context.context.Selected]);
    setupstep=SetUpStep::CHOOSE_DEFFENDER;
    context.context.Selected=-1;
    ContinueResult result;
    result.status=ContinueStatus::CONTINUE;

    return result;


}

void AttackUseCase::GetFighterCanAttackIt(Board & board){
    Fighter * fighter=combatcontext.Current->fighter;
    Hero * enemy=combatcontext.Opponent->hero;
    Attack type=fighter->GetAttack();
    std::vector<Fighter*> enemies=enemy->GetSideKicks();
    enemies.push_back(dynamic_cast<Fighter*>(enemy));

    int nodeFighter=fighter->GetNode();
    if(type==Attack::MELEE){
        for(auto ENEMY:enemies){
            if(board.AreAdjacent(nodeFighter,ENEMY->GetNode())){
                if(!(board.GetNodeType(nodeFighter)==NodeType::SECREST &&
                    board.GetNodeType(ENEMY->GetNode())==NodeType::SECREST)){
                        this->enemiescanAttack.push_back(ENEMY);
                    }
                        
            }
        }
    }
    else if(type==Attack::RANGED){
        for(auto ENEMY: enemies){
            if(board.IsAnArea(ENEMY->GetNode(),nodeFighter)){
                this->enemiescanAttack.push_back(ENEMY);
            }
            else if(board.AreAdjacent(ENEMY->GetNode(),nodeFighter)){
                    if(!(board.GetNodeType(nodeFighter)==NodeType::SECREST &&
                           board.GetNodeType(ENEMY->GetNode())==NodeType::SECREST)){
                        this->enemiescanAttack.push_back(ENEMY);
                    }
            }
                
        }
    }

}

ContinueResult AttackUseCase::ChooseDeffender(EffectContext & context){
    if(context.context.Selected==-1) return BuildDeffenderMenu(context);

    combatcontext.Opponent->fighter=enemiescanAttack[context.context.Selected];
    context.context.Selected=-1;
    ContinueResult result;
    if(CanDeffendDffender())
        setupstep=SetUpStep::ASK_FOR_DEFFEND;
    else{
        attackstep=AttackStep::COMBAT;
    }
    result.status=ContinueStatus::CONTINUE;
    return result;

}


ContinueResult AttackUseCase::BuildDeffenderMenu(EffectContext & context){
    ContinueResult result;
    this->GetFighterCanAttackIt(context.context.Gamestate->board);
    for(auto fihgter:this->enemiescanAttack){
        result.menu_request.options.push_back(fihgter->GetName());
    }
    result.status=ContinueStatus::NEEDMENU;
    result.menu_request.title="Enemies";
    return result;
}

ContinueResult AttackUseCase::ChooseDeffenderCard(EffectContext & context){
    if(context.context.Selected==-1) return BuildDeffenerCardMenu(context) ;

    combatcontext.Opponent->card=dynamic_cast<CombatCard*>(DeffenderCards[context.context.Selected]);
    ContinueResult result;
    context.context.Selected=-1;
    result.status=ContinueStatus::CONTINUE;
    this->attackstep=AttackStep::COMBAT;

    return result;

}


ContinueResult AttackUseCase::BuildDeffenerCardMenu(EffectContext& context){
    ContinueResult result;
    for(auto card: DeffenderCards){
        result.menu_request.options.push_back(card->GetName());
    }
    result.menu_request.title="cards";
    result.status=ContinueStatus::NEEDMENU;
    return result;

}

void AttackUseCase::SetDeffenderCards(){

    Hero * hero=combatcontext.Opponent->hero;

    for(auto card: hero->GetHand()){
        if(combatcontext.Opponent->fighter->GetFighterType()==card->GetOwner() ||
            card->GetOwner()==FighterType::ANY){
            if(card->GetCategory()==CardCategory::DEFFENSE ||card->GetCategory()==CardCategory::ATTACKANDDEFFENS)
                DeffenderCards.push_back(card);
            
        }
    }
}

bool AttackUseCase::CanDeffendDffender(){
    SetDeffenderCards();
    return DeffenderCards.size()>0;
}


ContinueResult AttackUseCase::AskForDeffend(EffectContext & context){
    if(context.context.Selected==-1) return BuildAskDeffendMenu();
    
    if(context.context.Selected==0)
        setupstep=SetUpStep::CHOOSE_DEFFENDER_CARD;
    else if(context.context.Selected==1) attackstep=AttackStep::COMBAT;

    context.context.Selected=-1;
    ContinueResult res;
    res.status=ContinueStatus::CONTINUE;

    return res;
}


ContinueResult AttackUseCase::BuildAskDeffendMenu(){
    ContinueResult res;
    res.menu_request.options.push_back("Deffend");
    res.menu_request.options.push_back("Continue");
    res.status=ContinueStatus::NEEDMENU;
    return res;
}



ContinueResult AttackUseCase::Finished(EffectContext & context){
    context.context.Selected=-1;
    this->Attacker.clear();
    this->AttackerCards.clear();
    this->DeffenderCards.clear();
    this->enemiescanAttack.clear();
    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
    
}
