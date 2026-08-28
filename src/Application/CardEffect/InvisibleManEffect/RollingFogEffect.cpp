#include "Application/CardEffect/InvisibleCardsEffect/RollingFogEffect.h"
#include <iostream>
ContinueResult RollingFogEffect::Continue(EffectContext & context){

    switch (step)
    {
    case RollingStep::CHOOSE_FOG:
        return ChooseFog(context);
        break;
    case RollingStep::MOVE_FOG:
        return MoveFog(context);
        break;
    case RollingStep::GAIN_ACTION:
        return GainAction(context);
        break;
    }
    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}

ContinueResult RollingFogEffect::ChooseFog(EffectContext& context){
ContinueResult result;
    // std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
    Hero * invisibleman=context.context.Gamestate->currnetPlayer->GetHero();
    // std::cout<<"******************\n";
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

    // std::cout<<"Fog taht selected at "<<fog->GetNode()<<std::endl;

    step=RollingStep::MOVE_FOG;
        SetStep(static_cast<int>(step));

    result.status=ContinueStatus::CONTINUE;
    return result;
}
ContinueResult RollingFogEffect::MoveFog(EffectContext & context){
    ContinueResult result;
    if(context.context.Selected==-1){
        
        Nodes=context.context.Gamestate->board.GetAllNodeWithoutFog();
        result.menu_request.nodes=Nodes;
        result.status=ContinueStatus::NEEDMENU;
        result.menu_request.type=InputType::NODE;
        context.context.Gamestate->log.Add("Choose Node to Move fog ");

        return result;
    }

    fog->SetNode(Nodes[context.context.Selected]);
        context.context.Selected=-1;
    step=RollingStep::GAIN_ACTION;
        SetStep(static_cast<int>(step));

    result.status=ContinueStatus::CONTINUE;
    return result;

}

ContinueResult RollingFogEffect::GainAction(EffectContext & context){
    ContinueResult result;
    result.status=ContinueStatus::FINISHED;

    context.context.Gamestate->currnetPlayer->GetHero()->AddAction();
    return result;
}
