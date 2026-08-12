#include "Application/CardEffect/InvisibleCardsEffect/LurkingEffect.h"
#include "Application/UseCases/DrawingCardUseCase.h"
#include <iostream>

ContinueResult LurkingEffect::Continue(EffectContext & context ){
    switch (step)
    {
    case LurkingStep::DRAW_CARD:{
        DrawingCardUseCase::DrawCard(context.combatcontext->Current->hero,context.context.Gamestate->log);
        ContinueResult result;
        result.status=ContinueStatus::CONTINUE;
        step=LurkingStep::CHOOSE_EFFECT;
        return result;
        break;
    }
    case LurkingStep::CHOOSE_EFFECT:
        return ChooseEffect(context);
        break;
    case LurkingStep::MOVE_INVISIBLEMAN_TO_FOG:
        return MoveInvisibleMan(context);
        break;
    case LurkingStep::CHOOSE_FOG:
        return ChooseFog(context);
        break;
    case LurkingStep::MOVE3_FOG:
        return MoveFog(context);
        break;
    }
    ContinueResult reusult;
    reusult.status=ContinueStatus::FINISHED;
    return reusult;
}
ContinueResult LurkingEffect::ChooseEffect(EffectContext &context){
    ContinueResult result;
    if(context.context.Selected==-1){
        result.status=ContinueStatus::NEEDMENU;
        result.menu_request.type=InputType::QUESTION;
        result.menu_request.options.push_back("Move InvisibleMan to fog ");
        result.menu_request.options.push_back("Move 3 a Fog ");
        return result;
    }

    if(context.context.Selected==0){
        step=LurkingStep::MOVE_INVISIBLEMAN_TO_FOG;
    }
    else if(context.context.Selected==1){
        step=LurkingStep::CHOOSE_FOG;        
    }
    result.status=ContinueStatus::CONTINUE;

    context.context.Selected=-1;

    return result;

}
ContinueResult LurkingEffect::MoveInvisibleMan(EffectContext &context){
    ContinueResult result;
    if(context.combatcontext->Current->hero)
        std::cout<<" Invisible man\n";
     Hero * invisibleman=context.combatcontext->Current->hero;
     std::cout<<invisibleman->GetName()<<std::endl;
    if(context.context.Selected==-1){
        for(auto fog: invisibleman->GetFogs()){
            result.menu_request.nodes.push_back(fog->GetNode());
        }
        if(result.menu_request.nodes.empty()){
            std::cout<<"Fucccck it is empty !!!!!!!!\n";
        }
        Nodes=result.menu_request.nodes;
        result.status=ContinueStatus::NEEDMENU;
        result.menu_request.type=InputType::NODE;
        return result;
    }

    invisibleman->SetNode(Nodes[context.context.Selected]);
    
    context.context.Selected=-1;
    result.status=ContinueStatus::FINISHED;
    return result;

}
ContinueResult LurkingEffect::ChooseFog(EffectContext & context){
    ContinueResult result;
    Hero * invisibleman=context.combatcontext->Current->hero;
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

    std::cout<<"Fog taht selected at "<<fog->GetNode()<<std::endl;

    step=LurkingStep::MOVE3_FOG;
    result.status=ContinueStatus::CONTINUE;
    return result;

}
ContinueResult LurkingEffect::MoveFog(EffectContext & context){
    ContinueResult result;
    if(context.context.Selected==-1){
        
        Nodes=context.context.Gamestate->board.GetReachbleNodesForFog(fog->GetNode(),3);
        result.status=ContinueStatus::NEEDMENU;
        result.menu_request.nodes=Nodes;
        // for(auto n:Nodes){
        //     std::cout<<"Nodes"<<n<<std::endl;
        // }
        result.menu_request.type=InputType::NODE;
        return result;
    }

    fog->SetNode(Nodes[context.context.Selected]);
        context.context.Selected=-1;

    result.status=ContinueStatus::FINISHED;
    return result;
}
