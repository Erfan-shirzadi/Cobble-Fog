#include "Application/UseCases/SchemeUseCase.h"
#include "Domain/Entities/SchemeCard.h"
#include "Domain/Entities/Cards/Holmes/AdministerAid.h"
#include <iostream>
#include "Application/interaction/EffectContext.h"
#include "Application/CardEffect/CardEffectFactory.h"

using namespace std;


bool SchemeUseCase::CanDoAction(GameState * gamestate){
    Hero * hero =gamestate->currnetPlayer->GetHero();
    // cout<<" herreiiiiiiiiiiiiii"<<endl;
    if(!hero->IsExistCardInHand(CardCategory::SCHEME))
        return false;
    
    std::vector<Card *> cards=hero->GetAllCardOf(CardCategory::SCHEME);
    for(auto card:cards){
        if(card->GetOwner()==hero->GetFighterType() ||card->GetOwner()==FighterType::ANY){
            return true;
        }
    }

    return hero->IsAliveAnySideKick();
}



ContinueResult SchemeUseCase::Continue(EffectContext &context){

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

    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}


ContinueResult SchemeUseCase::ChooseCard(EffectContext& context){

    if(context.context.Selected==-1){
        ContinueResult result;
        cout<<"In choose card Scheme"<<endl;
        result.status=ContinueStatus::NEEDMENU;
        result.menu_request.type=InputType::CARD;
        result.menu_request=BuildCardMenu(context);
        return result;
    }

    SelectedCard=context.context.Gamestate->currnetPlayer->GetHero()->GetCard(context.context.Selected);
    cardEffect=CardEffectFactory::CreatCardEffect(SelectedCard->GetCardId());
    context.context.Selected=-1;
    step=SchemeStep::EXECUTECARD;
    cout<<"Card Choosed"<<endl;
    cout<<SelectedCard->GetName()<<endl;
    ContinueResult res;
    res.status=ContinueStatus::CONTINUE;
    return res;

}


MenuRequest SchemeUseCase::BuildCardMenu(EffectContext& context){
    MenuRequest request;
    // std::vector<string> options;
    if(context.context.Gamestate->currnetPlayer){
        cout<<"Buidl menu cardds"<<endl;
    }
    for(auto card : context.context.Gamestate->currnetPlayer->GetHero()->GetAllCardOf(CardCategory::SCHEME)){
        // options.push_back(card->GetName());
        request.cards.push_back(card->GetCardId());
    }
    // request.options=options;
    cout<<"bbbbbbbbbbbiuld cardddddmenu"<<endl;
    request.type=InputType::CARD;
    request.title="Scheme Card ";
    return request;
}

ContinueResult SchemeUseCase::ExecuteCard(EffectContext& context){
     ContinueResult result=cardEffect->Continue(context);
     if(result.status == ContinueStatus::FINISHED){
        step=SchemeStep::FINISHED;
        return result;
     }
     return result;
}   

ContinueResult SchemeUseCase::Finished(EffectContext &context){
    this->SelectedCard=nullptr;
    context.context.Selected=-1;
    cardEffect=nullptr;
    ContinueResult result;
    result.status=ContinueStatus::FINISHED;
    return result;
}

void SchemeUseCase::Start(EffectContext& context ){
        context.context.Selected=-1;
        step=SchemeStep::CHOOSECARD;
        SelectedCard=nullptr;
}

SchemeStep SchemeUseCase::GetStep(){
    return this->step;
}
Card* SchemeUseCase::GetSelectedCard(){
    return this->SelectedCard;
}

void SchemeUseCase::SetStep(SchemeStep step){
    this->step=step;
}
void SchemeUseCase::SetSelectedCard(Card* card){
    this->SelectedCard=card;
}
void SchemeUseCase::SetCardEffect(std::unique_ptr<CardEffect> effect){
    this->cardEffect=std::move(effect);
}
