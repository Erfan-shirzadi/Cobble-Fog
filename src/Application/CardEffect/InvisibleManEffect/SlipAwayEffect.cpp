#include "Application/CardEffect/InvisibleCardsEffect/SlipAwayEffect.h"

ContinueResult SlipAwayEffect::Continue(EffectContext & context){

    switch (step)
    {
    case SlipStep::CHOOSE_FOG:
        return ChooseFog(context);
        break;
    case SlipStep::MOVE_FOG:
        return MoveFog(context);
        break;
    }
    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}
ContinueResult SlipAwayEffect::ChooseFog(EffectContext&context){
    ContinueResult result;
    Hero * invisibleman=context.combatcontext->Current->hero;
    if(context.context.Selected==-1){
        for(auto fog: invisibleman->GetFogs()){
            result.menu_request.nodes.push_back(fog->GetNode());
        }
        Nodes=result.menu_request.nodes;
        result.status=ContinueStatus::NEEDMENU;
        result.menu_request.type=InputType::NODE;
        context.context.Gamestate->log.Add("Choose fog to Move ");

        return result;
    }
    fog=invisibleman->GetFogs()[context.context.Selected];
    context.context.Selected=-1;
    step=SlipStep::MOVE_FOG;
    result.status=ContinueStatus::CONTINUE;
    return result;

}
ContinueResult SlipAwayEffect::MoveFog(EffectContext & context){
    ContinueResult result;
    if(context.context.Selected==-1){
        
        Nodes=context.context.Gamestate->board.GetAllNodeWithoutFogAndFighters();
        result.menu_request.nodes=Nodes;
        result.status=ContinueStatus::NEEDMENU;
        result.menu_request.type=InputType::NODE;
        context.context.Gamestate->log.Add("Choose Node to Move fog ");

        return result;
    }

    fog->SetNode(Nodes[context.context.Selected]);
    Hero * invisibleman=context.combatcontext->Current->hero;
    invisibleman->SetNode(Nodes[context.context.Selected]);
        context.context.Selected=-1;

    result.status=ContinueStatus::FINISHED;
    return result;

}

