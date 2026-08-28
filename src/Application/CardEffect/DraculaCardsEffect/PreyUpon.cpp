#include "Application/CardEffect/DraculaCardsEffect/PreyUponEffect.h"
#include "Application/interaction/EffectContext.h"

ContinueResult PreyUponEffect::Continue(EffectContext & context){
    Hero* Dracula=context.context.Gamestate->currnetPlayer->GetHero();
    Hero* enemy=context.context.Gamestate->opponentPlayre->GetHero();
    Board board=context.context.Gamestate->board;
    for(auto fighter: enemy->GetSideKicks()){
        if(board.AreAdjacent(fighter->GetNode(),Dracula->GetNode())){
            if(!(board.GetNodeType(fighter->GetNode())==NodeType::SECREST &&
            board.GetNodeType(Dracula->GetNode())==NodeType::SECREST)){
                // context.context.Gamestate->log.Add(fighter->GetName()+" damage 1");
                // context.context.Gamestate->log.Add("Dracula healed 1");
                fighter->TakeDamge(1);
                Dracula->Heal(1);
            }
        }
    }

    if(board.AreAdjacent(enemy->GetNode(),Dracula->GetNode())){
            if(!(board.GetNodeType(enemy->GetNode())==NodeType::SECREST &&
            board.GetNodeType(Dracula->GetNode())==NodeType::SECREST)){
                // context.context.Gamestate->log.Add(enemy->GetName()+" damage 1");
                // context.context.Gamestate->log.Add("Dracula healed 1");
                enemy->TakeDamge(1);
                Dracula->Heal(1);
            }
        }
    
    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;

}
