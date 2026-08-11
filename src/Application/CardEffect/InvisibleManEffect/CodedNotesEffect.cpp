#include "Application/CardEffect/InvisibleCardsEffect/CodedNotesEffect.h"
#include "Application/UseCases/DrawingCardUseCase.h"
#include <iostream>
ContinueResult CodedNotesEffect::Continue(EffectContext & context ){

    switch (step)
    {
    case CodedStep::DRAW3_CARD:
        return Draw3Card(context);
        break;
    case CodedStep::REUTRN_CARD_TO_DECK:
        return ReturnToDeckCard(context);
        break;
    }
    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}
ContinueResult CodedNotesEffect::Draw3Card(EffectContext & context){
    DrawingCardUseCase::DrawCard(context.combatcontext->Current->hero,context.context.Gamestate->log);
    countofCardDrawed++;
    ContinueResult result;
    std::cout<<context.combatcontext->Current->hero->GetName()<<std::endl;
    if(countofCardDrawed==3){
        context.context.Gamestate->handview=HandView::OPPONENTPLAYER;
        step=CodedStep::REUTRN_CARD_TO_DECK;
    }
    result.status=ContinueStatus::CONTINUE;
    return result;
}
ContinueResult CodedNotesEffect::ReturnToDeckCard(EffectContext & context){
    ContinueResult result;
    Hero * hero=context.combatcontext->Current->hero;
    if(context.context.Selected==-1){
        for(auto card:hero->GetHand()){
            result.menu_request.cards.push_back(card->GetCardId());
        }
        result.status=ContinueStatus::NEEDMENU;
        result.menu_request.type=InputType::CARD;
        return result;
    }
    hero->ReturnCardToDeck(context.context.Selected);
    context.context.Selected=-1;
    countofCardReturned++;
    result.status=ContinueStatus::CONTINUE;

    if(countofCardReturned==2){
        result.status=ContinueStatus::FINISHED;
    }
    
    return result;

}
