#include "Application/CardEffect/InvisibleCardsEffect/EmergeFromMistEffect.h"

ContinueResult EmergeFromMistEffect::Continue(EffectContext& context){
    ContinueResult result;
    Board board=context.context.Gamestate->board;
    Hero * hero=context.combatcontext->Current->hero;

    if(board.IsFogHere(hero->GetPositionOnStartTurn())){
        context.combatcontext->Current->card->IncreseDamageOfDeffend(2);
    }
    result.status =ContinueStatus::FINISHED;
    return result;
}