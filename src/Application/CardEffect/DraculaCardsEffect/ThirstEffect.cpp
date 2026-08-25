 #include "Application/CardEffect/DraculaCardsEffect/ThirstEffect.h"
#include "Application/interaction/EffectContext.h"

ContinueResult ThirstEffect::Continue(EffectContext & context ){

    if(context.combatcontext->Current->Won){
        if(context.context.Selected==-1) return BuildReachableNodes(context);

        Hero*hero=context.context.Gamestate->currnetPlayer->GetHero();
        hero->SetNode(rechabenode[context.context.Selected]);
        context.context.Selected=-1;
    }
    ContinueResult res;
    res.status=ContinueStatus::FINISHED;

    return res;


}


ContinueResult ThirstEffect::BuildReachableNodes(EffectContext & context ){
    ContinueResult res;
    Board board=context.context.Gamestate->board;
    Fighter * enemy=context.combatcontext->Opponent->fighter;;

    this->rechabenode=board.GetReachableNighbors(enemy->GetNode());
    if(rechabenode.empty()){
        res.status=ContinueStatus::FINISHED;
        return res;
    }
    
    for(int x: rechabenode){
        res.menu_request.nodes.push_back(x);
    }
    // res.menu_request.title="Reachable Nodes";
    context.context.Gamestate->log.Add("Choose A Node to Move Dracula ");

    res.status=ContinueStatus::NEEDMENU;
    res.menu_request.type=InputType::NODE;

    return res;
     
}
