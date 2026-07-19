#include "Application/CardEffect/HolmesCardsEffect/DeduceStrategyEffect.h"
#include "Application/interaction/EffectContext.h"

ContinueResult DeduceStrategyEffect::Continue(EffectContext & context){

    ContinueResult result;
    CombatCard * card=context.combatcontext->Opponent->card;
    if(context.context.Selected==-1){
        result.menu_request.options.push_back("Change "
            +std::to_string(card->GetDamgeOrDeffend())+"to "+
            std::to_string(card->GetBoost()));
        result.menu_request.options.push_back("stay "+std::to_string(card->GetDamgeOrDeffend()));
        result.menu_request.title="Change amount Enemy Card:";
        result.status=ContinueStatus::NEEDMENU;
        return result;
            
    }

    if(context.context.Selected==0){
        card->SetDamageOrDeffend(card->GetBoost());
    }
    result.status=ContinueStatus::FINISHED;
    context.context.Selected=-1;
    return result;
}
