#include "Application/CardEffect/InvisibleCardsEffect/ReignOfTerorrEffect.h"


ContinueResult ReignOfTerrorEffect::Continue(EffectContext & context){
    Board board=context.context.Gamestate->board;

    if(board.IsFogHere(context.combatcontext->Current->hero->GetNode())){

       Hero * enemy= context.combatcontext->Opponent->hero;

       enemy->TakeDamge(2);

       for(auto sidekick:enemy->GetSideKicks()){
        sidekick->TakeDamge(2);
       }
    }

    ContinueResult result;
    result.status=ContinueStatus::FINISHED;
    return result;
}
