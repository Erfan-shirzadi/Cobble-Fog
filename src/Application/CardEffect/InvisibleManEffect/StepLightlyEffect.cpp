#include "Application/CardEffect/InvisibleCardsEffect/StepLightlyEffect.h"

ContinueResult StepLightlyEffect::Continue(EffectContext & context){
   switch (step)
   {
   case StepStepLightly::DAMAGE_ENMEY:
    return DamageEnemy(context);
    break;
    case StepStepLightly::CHOOSE_FOG:
    return ChooseFog(context);
    break;
    case StepStepLightly::MOVE_FOG:
    return MoveFog(context);
    break;
   }
   ContinueResult res;
   res.status=ContinueStatus::FINISHED;
   return res;
}

ContinueResult StepLightlyEffect::DamageEnemy(EffectContext & context){
    ContinueResult result;
    Hero * InvisibleMan=context.context.Gamestate->currnetPlayer->GetHero();
    Board board=context.context.Gamestate->board;

    if(context.context.Selected==-1){
        Hero * enemy=context.context.Gamestate->opponentPlayre->GetHero();
        if(board.AreAdjacent(enemy->GetNode(),InvisibleMan->GetNode())){
            enemies.push_back(dynamic_cast<Fighter*>(enemy));
        }

        for(auto fighter:enemy->GetSideKicks()){
            if(board.AreAdjacent(fighter->GetNode(),InvisibleMan->GetNode()))
                enemies.push_back(fighter);
        }

        if(enemies.empty()){
            step=StepStepLightly::CHOOSE_FOG;
            SetStep(static_cast<int>(step));

            result.status=ContinueStatus::CONTINUE;
            return result;
        }

        for(auto fighter:enemies){
            result.menu_request.nodes.push_back(fighter->GetNode());
        }
        result.menu_request.type=InputType::NODE;
        result.status=ContinueStatus::NEEDMENU;

        return result;

    }

    if(board.IsFogHere(InvisibleMan->GetNode())){
        enemies[context.context.Selected]->TakeDamge(3);
    }
    else enemies[context.context.Selected]->TakeDamge(1);

    context.context.Selected=-1;
    result.status=ContinueStatus::CONTINUE;
    step=StepStepLightly::CHOOSE_FOG;
        SetStep(static_cast<int>(step));


    return result;


}
ContinueResult StepLightlyEffect::ChooseFog(EffectContext &context){
    ContinueResult result;
    Hero * invisibleman=context.context.Gamestate->currnetPlayer->GetHero();
    if(context.context.Selected==-1){
        for(auto fog: invisibleman->GetFogs()){
            result.menu_request.nodes.push_back(fog->GetNode());
        }
        Nodes=result.menu_request.nodes;
        result.status=ContinueStatus::NEEDMENU;
        result.menu_request.type=InputType::NODE;
        return result;
    }
    fog=invisibleman->GetFogs()[context.context.Selected];
    context.context.Selected=-1;


    step=StepStepLightly::MOVE_FOG;
        SetStep(static_cast<int>(step));

    result.status=ContinueStatus::CONTINUE;
    return result;

}
ContinueResult StepLightlyEffect::MoveFog(EffectContext &context){
    ContinueResult result;
    if(context.context.Selected==-1){
        
        Nodes=context.context.Gamestate->board.GetReachbleNodesForFog(fog->GetNode(),2);
        result.menu_request.nodes=Nodes;
        result.status=ContinueStatus::NEEDMENU;
        result.menu_request.type=InputType::NODE;
        return result;
    }

    fog->SetNode(Nodes[context.context.Selected]);
        context.context.Selected=-1;
    result.status=ContinueStatus::FINISHED;
    return result;
}
