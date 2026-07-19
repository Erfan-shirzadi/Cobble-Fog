#include "Application/CardEffect/HolmesCardsEffect/FixedAPointInChangingAgeEffect.h"
#include "Application/interaction/EffectContext.h"

ContinueResult FixedAPointInChangingAgeEffect::Continue(EffectContext & context){
    Hero * holmes=context.context.Gamestate->currnetPlayer->GetHero();
    std::vector<Fighter*> watson=holmes->GetSideKicks();
    Board board=context.context.Gamestate->board;
    if(board.AreAdjacent(holmes->GetNode(),watson[0]->GetNode())){
        holmes->Heal(1);
        watson[0]->Heal(1);
    }

    ContinueResult res;
     res.status=ContinueStatus::FINISHED;
     return res;

}
