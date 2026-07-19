#include "Application/CardEffect/HolmesCardsEffect/EliminateTheImpossible.h"
#include "Application/interaction/EffectContext.h"

   
ContinueResult EliminateTheImpossibleEffect::Continue(EffectContext& context){
    if(context.context.Selected==-1) return BuildCardMenu(context);

    context.context.Gamestate->opponentPlayre->GetHero()->GetCard(context.context.Selected);

    ContinueResult res;
     res.status= ContinueStatus::FINISHED;

     return res;
}


ContinueResult EliminateTheImpossibleEffect::BuildCardMenu(EffectContext& context){
    ContinueResult result;
    for(auto card : context.context.Gamestate->opponentPlayre->GetHero()->GetHand()){
        result.menu_request.options.push_back(card->GetName());
    }

    result.menu_request.title="Enemy Cards";
    result.status=ContinueStatus::NEEDMENU;

    return result;
}
