#include "Application/CardEffect/InvisibleCardsEffect/DreamingOfRevengeEffect.h"
ContinueResult DreamingOfRevengeEffect::Continue(EffectContext & context ){
    Hero *hero=context.combatcontext->Current->hero;
    bool flag=false;
    for(auto fog: hero->GetFogs()){
        if(hero->GetNode()==fog->GetNode())flag=true;
    }

    if(flag){
        Hero * enemy=context.combatcontext->Opponent->hero;
        for(auto fog: hero->GetFogs()){
            if(enemy->GetNode()==fog->GetNode()){
                enemy->TakeDamge(1);
            }
            for(auto sidekick: enemy->GetSideKicks()){
                if(sidekick->GetNode()==fog->GetNode()){
                    sidekick->TakeDamge(1);
                }
            }
        }
    }

    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}
