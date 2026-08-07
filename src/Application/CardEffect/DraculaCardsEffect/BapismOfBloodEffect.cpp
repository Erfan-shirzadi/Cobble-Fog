#include  "Application/CardEffect/DraculaCardsEffect/BapismOfBloodEffect.h"
#include "Application/interaction/EffectContext.h"
#include "Application/UseCases/MoveUseCase.h"

ContinueResult BapismOfBloodEffect::Continue(EffectContext &  context){
    switch (this->bapismstep)
    {
    case BapismEffectStep::HEAL_DRACULA:{
        context.context.Gamestate->currnetPlayer->GetHero()->Heal(2);
        context.context.Gamestate->log.Add("Healed 2 Dracula ");
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
        context.context.Gamestate->log.Add("Sister 1 Healed");
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
    context.context.Gamestate->log.Add("Sister return");
    MoveUseCase::Move(sister,reachableNodes[context.context.Selected],context.context.Gamestate->log);
    context.context.Selected=-1;
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
        result.menu_request.nodes.push_back(x);
    }
    result.menu_request.title=" reachable Nodes ";

    result.status=ContinueStatus::NEEDMENU;
    result.menu_request.type=InputType::NODE;

    return result;
    
}
