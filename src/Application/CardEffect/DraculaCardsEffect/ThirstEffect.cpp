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
    if(rechabenode.empty())res.status=ContinueStatus::FINISHED;

    for(int x: rechabenode){
        res.menu_request.options.push_back(std::to_string(x));
    }
    res.menu_request.title="Reachable Nodes";

    res.status=ContinueStatus::NEEDMENU;

    return res;
     
}
