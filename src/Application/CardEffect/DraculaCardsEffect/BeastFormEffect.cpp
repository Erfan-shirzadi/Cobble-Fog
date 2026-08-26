#include "Application/CardEffect/DraculaCardsEffect/BeastFormEffect.h"
#include "Application/interaction/EffectContext.h"
ContinueResult BeastFormEffect::Continue(EffectContext & context){

    switch (step)
    {
    case BeastFormStep::ASK_FOR_DISCADINGCARD:
        return AskForDiscardinCard(context);
        break;
    case BeastFormStep::CHOOSE_CARD:
        return ChooseCard(context);
        break;
    }
    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}

ContinueResult BeastFormEffect::AskForDiscardinCard(EffectContext & context){
    if(context.combatcontext->Current->hero->GetSizeHand()==0){
        ContinueResult res;
        res.status=ContinueStatus::FINISHED;
        return res;
    }

    if(context.context.Selected==-1){
        ContinueResult res;
        res.menu_request.options.push_back("DisCard ");
        res.menu_request.options.push_back("Skip ");
        res.menu_request.title="Do you Want Remove?";
        res.status=ContinueStatus::NEEDMENU;
        res.menu_request.type=InputType::QUESTION;
        context.context.Gamestate->log.Add("Answer to Questoin");
        return res;
    }

    if(context.context.Selected==0){
        step=BeastFormStep::CHOOSE_CARD;
        // SetStep(static_cast<int>(step));
        ContinueResult res;
        res.status =ContinueStatus::CONTINUE;
        context.context.Selected=-1;
        return res;
    }

    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}
ContinueResult BeastFormEffect::ChooseCard(EffectContext & context){
    if(context.context.Selected==-1)return BuildCardMenu(context);

    context.combatcontext->Current->hero->GetCard(context.context.Selected);
    if(context.combatcontext->Current->CanChangeAmountCard)
        context.combatcontext->Current->card->IncreseDamageOfDeffend(1);
    context.context.Selected=-1;
    ContinueResult res;
     
     step=BeastFormStep::ASK_FOR_DISCADINGCARD;
     return Continue(context);
}

ContinueResult BeastFormEffect::BuildCardMenu(EffectContext & context){

    Hero * dracual=context.combatcontext->Current->hero;
    ContinueResult res;
    for(auto card: dracual->GetHand()){
        res.menu_request.cards.push_back(card->GetCardId());
    }


    res.menu_request.title="Cards ";
    res.status=ContinueStatus::NEEDMENU;
    context.context.Gamestate->log.Add("Select a card to remove it");
    res.menu_request.type=InputType::CARD;
    return res;
}
