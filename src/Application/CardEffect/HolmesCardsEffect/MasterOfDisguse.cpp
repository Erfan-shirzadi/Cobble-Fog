#include "Application/CardEffect/HolmesCardsEffect/MasterOfDeisguseEffect.h"
#include "Application/interaction/EffectContext.h"

ContinueResult MasterOfDeisGuseEffect::Continue(EffectContext &context){
   Hero * hero= context.context.Gamestate->currnetPlayer->GetHero();
    Hero * enemy=context.context.Gamestate->opponentPlayre->GetHero();
    int HeroNode=hero->GetNode();
     hero->SetNode(enemy->GetNode());
     enemy->SetNode(HeroNode);
     enemy->TakeDamge(1);
    
     ContinueResult res;
     res.status = ContinueStatus::FINISHED;

     return res;
}
