#include "Application/CardEffect/HolmesCardsEffect/EliminateTheImpossible.h"
#include "Application/interaction/EffectContext.h"

   
ContinueResult EliminateTheImpossibleEffect::Continue(EffectContext& context){
    if(context.context.Selected==-1) return BuildCardMenu(context);

    context.context.Gamestate->opponentPlayre->GetHero()->GetCard(context.context.Selected);
    context.context.Selected=-1;
    ContinueResult res;
    context.context.Gamestate->handview=HandView::CURRENTPLAYER;

     res.status= ContinueStatus::FINISHED;

     return res;
}


ContinueResult EliminateTheImpossibleEffect::BuildCardMenu(EffectContext& context){
    ContinueResult result;
    context.context.Gamestate->handview=HandView::OPPONENTPLAYER;
    for(auto card : context.context.Gamestate->opponentPlayre->GetHero()->GetHand()){
        result.menu_request.cards.push_back(card->GetCardId());
    }

    result.menu_request.title="Enemy Cards";
    context.context.Gamestate->log.Add("Choose a Card of enemy hand");
    result.status=ContinueStatus::NEEDMENU;
    result.menu_request.type=InputType::CARD;

    return result;
}
