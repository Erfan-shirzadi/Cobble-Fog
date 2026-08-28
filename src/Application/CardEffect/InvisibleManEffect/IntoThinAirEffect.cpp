#include "Application/CardEffect/InvisibleCardsEffect/IntoThinAirEffect.h"

ContinueResult IntoThinAirEffect::Continue(EffectContext & context ){

    switch (step)
    {
    case IntoThinStep::MOVE_INISIBLEMAN:
        return MoveHero(context);
        break;
    case IntoThinStep::CHOOSE_FOG:
        return ChooseFog(context);
        break;
    case IntoThinStep::MOVE_FOG:
        return MoveFog(context);
        break;
    }
    ContinueResult result;
    result.status=ContinueStatus::FINISHED;
    return result;
}


ContinueResult IntoThinAirEffect::MoveHero(EffectContext & context){
    ContinueResult result;
    if(context.context.Selected==-1){
        rechbleNodes=context.context.Gamestate->board.reachableNodes(
            context.combatcontext->Current->hero,context.combatcontext->Opponent->hero,1,
            context.combatcontext->Current->hero->GetNode());
        result.menu_request.nodes=rechbleNodes;
        result.menu_request.type=InputType::NODE;
        context.context.Gamestate->log.Add("Choose Node To Move Invisible Man");
        result.status=ContinueStatus::NEEDMENU;
        return result;
    }
    context.combatcontext->Current->hero->SetNode(rechbleNodes[context.context.Selected]);
    context.context.Selected=-1;
    rechbleNodes.clear();
    result.status=ContinueStatus::CONTINUE;
    step=IntoThinStep::CHOOSE_FOG;
    SetStep(static_cast<int>(step));

    return result;

}
ContinueResult IntoThinAirEffect::ChooseFog(EffectContext & context){
        ContinueResult result;
    if(context.context.Selected==-1){
        for(auto fog:context.combatcontext->Current->hero->GetFogs()){
            result.menu_request.nodes.push_back(fog->GetNode());
        }
        result.menu_request.type=InputType::NODE;
        context.context.Gamestate->log.Add("Choose Fog ");

        result.status=ContinueStatus::NEEDMENU;

        return result;
    }

    fog=context.combatcontext->Current->hero->GetFogs()[context.context.Selected];
    context.context.Selected=-1;
    result.status=ContinueStatus::CONTINUE;
    step=IntoThinStep::MOVE_FOG;
    SetStep(static_cast<int>(step));


    return result;
}
ContinueResult IntoThinAirEffect::MoveFog(EffectContext & context){
            ContinueResult result;
    if(context.context.Selected==-1){
        rechbleNodes=context.context.Gamestate->board.GetReachbleNodesForFog(fog->GetNode(),3);
        result.menu_request.nodes=rechbleNodes;
        result.menu_request.type=InputType::NODE;
        result.status=ContinueStatus::NEEDMENU;
        context.context.Gamestate->log.Add("Choose Fog To Move");


        return result;
    }
    fog->SetNode(rechbleNodes[context.context.Selected]);
    context.context.Selected=-1;

    result.status=ContinueStatus::FINISHED;
    return result;

}
