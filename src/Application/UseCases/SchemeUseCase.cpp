#include "Application/UseCases/SchemeUseCase.h"
#include "Domain/Entities/SchemeCard.h"
#include "Domain/Entities/Cards/Holmes/AdministerAid.h"
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


// ContinueResult SchemeUseCase::Continue(int input){

//     switch (this->step)
//     {
    
//     case Step::CHOOSECARD:
//       return ChooseCard(input);
        
//     case Step::EXECUTECARD:
//         return ExecuteCard();
//     break;
        
//     case Step::FINISHED:{
//         ContinueResult a;
//         a.status=ContinueStatus::FINISHED;
//         return a;
//     }

//     break;
//     }
    

// }


// ContinueResult SchemeUseCase::ChooseCard(int input){
//      ContinueResult result;
//      Hero * hero=gamestate.currnetPlayer->GetHero();
//      if(input==-1){
//         result.status=ContinueStatus::NEEDMENU;
//         result.menu_request.title="Choose Shceme Card";

//         for(auto card: hero->GetHand()){
//             result.menu_request.options.push_back(card->GetName());
//         }
//         return result;

//     }
    
//     this->card=hero->GetCard(input);
//     step=Step::EXECUTECARD;
//     // return Continue();

// }


// SchemeUseCase::SchemeUseCase(GameState & gamestate):gamestate(gamestate){}

// ContinueResult SchemeUseCase::ExecuteCard(){
    
//     AdministerAid * card=dynamic_cast<AdministerAid *>(this->card);
//     ContinueResult result=card->Continue(this->context);

//     if(result.status==ContinueStatus::FINISHED){

//         this->step=Step::FINISHED;
//         return Continue();
//     }

//     return result;
// } 

ContinueResult SchemeUseCase::Continue(ActionContext&context){

    switch (step)
    {
    case SchemeStep::CHOOSECARD:
        return ChooseCard(context);
        break;

    case SchemeStep::EXECUTECARD:
        return ExecuteCard(context);
        break;

    case SchemeStep::FINISHED:
        return Finished(context);
        break;
    
    }
}


ContinueResult SchemeUseCase::ChooseCard(ActionContext& context){

    if(context.Selected==-1){
        ContinueResult result;
        result.status=ContinueStatus::NEEDMENU;
        result.menu_request=BuildCardMenu(context);
        return result;
    }

    SelectedCard=context.Gamestate->currnetPlayer->GetHero()->GetCard(context.Selected);
    context.Selected=-1;
    step=SchemeStep::EXECUTECARD;

    ContinueResult res;
    res.status=ContinueStatus::CONTINUE;
    return res;

}


MenuRequest SchemeUseCase::BuildCardMenu(ActionContext& context){
    MenuRequest request;
    std::vector<string> options;
    for(auto card : context.Gamestate->currnetPlayer->GetHero()->GetHand()){
        options.push_back(card->GetName());
    }
    request.options=options;
    request.title="Scheme Card ";
    return request;
}

ContinueResult SchemeUseCase::ExecuteCard(ActionContext& context){
     ContinueResult result=SelectedCard->Continue(context);
     if(result.status == ContinueStatus::FINISHED){
        step=SchemeStep::FINISHED;
        return result;
     }
     return result;
}   

ContinueResult SchemeUseCase::Finished(ActionContext &context){
    this->SelectedCard=nullptr;
    context.Selected=-1;
    ContinueResult result;
    result.status=ContinueStatus::FINISHED;
    return result;
}

void SchemeUseCase::Start(ActionContext& context ){
        context.Selected=-1;
        step=SchemeStep::CHOOSECARD;
        SelectedCard=nullptr;
}
