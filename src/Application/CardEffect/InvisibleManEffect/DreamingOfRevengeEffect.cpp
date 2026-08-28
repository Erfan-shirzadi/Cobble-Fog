#include "Application/CardEffect/InvisibleCardsEffect/DreamingOfRevengeEffect.h"
ContinueResult DreamingOfRevengeEffect::Continue(EffectContext & context ){
    Hero *hero=context.combatcontext->Current->hero;
    Board board=context.context.Gamestate->board;
   

    if(board.IsFogHere(hero->GetNode())){
        Hero * enemy=context.combatcontext->Opponent->hero;
        
            if(board.IsFogHere(enemy->GetNode())){
                enemy->TakeDamge(1);
            }
            for(auto sidekick: enemy->GetSideKicks()){
                if(board.IsFogHere(sidekick->GetNode())){
                    sidekick->TakeDamge(1);
                }
            }
        
    }

    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}
