#include "Application/CardEffect/HolmesCardsEffect/AdministerAidEffect.h"
#include "Application/interaction/EffectContext.h"

ContinueResult AdministerAidEffect::Continue(EffectContext & context){

    switch (step)
    {
    case AdministerEffectStep::CHOOSE_DESTINATION:
        return ChooseDestination(context);
        break;
    case AdministerEffectStep::HEAL_HOLMES:{
            Hero* holmes=context.context.Gamestate->currnetPlayer->GetHero();
            holmes->Heal(1);

            ContinueResult res;
            res.status=ContinueStatus::CONTINUE;
            return res;
    }
    case AdministerEffectStep::DRAW_CARD:{
            Hero* holmes=context.context.Gamestate->currnetPlayer->GetHero();
            holmes->DrawCard();
            ContinueResult res;
            res.status=ContinueStatus::FINISHED;
            return res;
    }
    }
    ContinueResult res;
            res.status=ContinueStatus::FINISHED;
            return res;
}


ContinueResult AdministerAidEffect::ChooseDestination(EffectContext & context){
    if(context.context.Selected==-1)return BuildReachableNodes(context);

    std::vector<Fighter*>watson=context.context.Gamestate->currnetPlayer->GetHero()->GetSideKicks();
    watson[0]->SetNode(rechableNodes[context.context.Selected]);
    context.context.Selected=-1;

    ContinueResult res;
    res.status=ContinueStatus::CONTINUE;
    step=AdministerEffectStep::HEAL_HOLMES;
    return res;

}
ContinueResult AdministerAidEffect::BuildReachableNodes(EffectContext & context){
    Hero* holmes=context.context.Gamestate->currnetPlayer->GetHero();
    Board board=context.context.Gamestate->board;
    this->rechableNodes=board.GetReachableNighbors(holmes->GetNode());

    ContinueResult result;
    for(auto x: rechableNodes){
        result.menu_request.options.push_back(std::to_string(x));
    }
    result.status=ContinueStatus::NEEDMENU;
    result.menu_request.title="Move Watson To Node :";

    return result;

}
