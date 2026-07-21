#include "Application/CardEffect/HolmesCardsEffect/FixedAPointInChangingAgeEffect.h"
#include "Application/interaction/EffectContext.h"

ContinueResult FixedAPointInChangingAgeEffect::Continue(EffectContext & context){
    Hero * holmes=context.context.Gamestate->currnetPlayer->GetHero();
    // std::vector<Fighter*> watson=holmes->GetSideKicks();
    Fighter * watson=context.combatcontext->Current->fighter;
    Board board=context.context.Gamestate->board;
    if(board.AreAdjacent(holmes->GetNode(),watson->GetNode())){
        context.context.Gamestate->log.Add("Holmes Heal 1");
        context.context.Gamestate->log.Add("Watson Heal 1");

        holmes->Heal(1);
        watson->Heal(1);
    }

    ContinueResult res;
     res.status=ContinueStatus::FINISHED;
     return res;

}
