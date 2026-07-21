#include "Application/CardEffect/HolmesCardsEffect/MasterOfDeisguseEffect.h"
#include "Application/interaction/EffectContext.h"
#include "Application/UseCases/MoveUseCase.h"

ContinueResult MasterOfDeisGuseEffect::Continue(EffectContext &context){
   Hero * hero= context.context.Gamestate->currnetPlayer->GetHero();
    Hero * enemy=context.context.Gamestate->opponentPlayre->GetHero();
    int HeroNode=hero->GetNode();
    MoveUseCase::Move(hero,enemy->GetNode(),context.context.Gamestate->log);
    MoveUseCase::Move(enemy,HeroNode,context.context.Gamestate->log);

     enemy->TakeDamge(1);
   context.context.Gamestate->log.Add(enemy->GetName()+" Taked Damage 1");
     ContinueResult res;
     res.status = ContinueStatus::FINISHED;

     return res;
}
