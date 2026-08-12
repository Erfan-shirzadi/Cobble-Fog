#include "Application/CardEffect/InvisibleCardsEffect/ReignOfTerorrEffect.h"


ContinueResult ReignOfTerrorEffect::Continue(EffectContext & context){
    Board board=context.context.Gamestate->board;

    if(board.IsFogHere(context.context.Gamestate->currnetPlayer->GetHero()->GetNode())){

       Hero * enemy= context.context.Gamestate->opponentPlayre->GetHero();

       enemy->TakeDamge(2);

       for(auto sidekick:enemy->GetSideKicks()){
        sidekick->TakeDamge(2);
       }
    }

    ContinueResult result;
    result.status=ContinueStatus::FINISHED;
    return result;
}
