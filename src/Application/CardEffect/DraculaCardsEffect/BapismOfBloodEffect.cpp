#include  "Application/CardEffect/DraculaCardsEffect/BapismOfBloodEffect.h"

ContinueResult BapismOfBloodEffect::Continue(EffectContext &  context){
    switch (this->bapismstep)
    {
    case BapismEffectStep::HEAL_DRACULA:{
        context.context.Gamestate->currnetPlayer->GetHero()->Heal(2);
        ContinueResult res; 
        res.status=ContinueStatus::CONTINUE;
        this->bapismstep=BapismEffectStep::RETURN_SISTER;

    }
    case BapismEffectStep::RETURN_SISTER:
        return ReturnSister(context);
        break;
    case BapismEffectStep::FINISHED:{
        ContinueResult res;
        res.status=ContinueStatus::FINISHED;
        return res;
    }
    }

    ContinueResult res;
        res.status=ContinueStatus::FINISHED;
        return res;
}


ContinueResult BapismOfBloodEffect::ReturnSister(EffectContext & context){
    
    switch (returnstep)
    {
    case ReturnSisterStep::CHOOSEDESTINATION:
        return ChooseDestinationSister(context);
        break;
    case ReturnSisterStep::HEAL_SISITER:
         return HealSister(context);
    }
    ContinueResult res;
     res.status = ContinueStatus::FINISHED;
      return res;
    
}


ContinueResult BapismOfBloodEffect::HealSister(EffectContext & context){
    Hero * hero=context.context.Gamestate->currnetPlayer->GetHero();
    sister=hero->GetDeadSideKick();
    if(sister){
        sister->Heal(1);
        returnstep=ReturnSisterStep::CHOOSEDESTINATION;

        ContinueResult res;
        res.status=ContinueStatus::CONTINUE;

        return res;
    }

    bapismstep=BapismEffectStep::FINISHED;
        ContinueResult res;
    res.status=ContinueStatus::FINISHED;

    return res;


    
}
ContinueResult BapismOfBloodEffect::ChooseDestinationSister(EffectContext& context){
    if(context.context.Selected==-1) return BuildDestinationMenu(context);

    sister->SetNode(reachableNodes[context.context.Selected]);
    ContinueResult res;
     res.status=ContinueStatus::FINISHED;
     bapismstep=BapismEffectStep::FINISHED;

     return res;
}


ContinueResult BapismOfBloodEffect::BuildDestinationMenu(EffectContext context){
    ContinueResult result;
    Hero * hero=context.context.Gamestate->currnetPlayer->GetHero();
    Board board=context.context.Gamestate->board;
    reachableNodes=board.GetNodeofArea(hero->GetNode());

    for(auto x: reachableNodes){
        result.menu_request.options.push_back(std::to_string(x));
    }
    result.menu_request.title=" reachable Nodes ";

    result.status=ContinueStatus::NEEDMENU;

    return result;
    
}
