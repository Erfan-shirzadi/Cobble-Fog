#include "Application/CardEffect/Move3Effect.h"
#include "Application/interaction/EffectContext.h"

ContinueResult Move3Effect::Continue(EffectContext &context){
    if(context.context.Selected==-1)return BuildReachableNodes(context);

    context.combatcontext->Current->fighter->SetNode(this->rechbleNodes[context.context.Selected]);
    context.context.Selected=-1;
    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}
ContinueResult Move3Effect::BuildReachableNodes(EffectContext & context){
    Board board=context.context.Gamestate->board;
    ContinueResult res;
    this->rechbleNodes=board.reachableNodes(context.combatcontext->Current->hero,
        context.combatcontext->Opponent->hero,
        3,context.combatcontext->Current->fighter->GetNode());

        for(auto x:rechbleNodes){
            res.menu_request.nodes.push_back(x);
        }   
        res.menu_request.title="Nodes";
        res.status=ContinueStatus::NEEDMENU;
        res.menu_request.type=InputType::NODE;

        return res;
}
