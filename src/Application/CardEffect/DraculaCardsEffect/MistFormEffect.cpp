#include "Application/CardEffect/DraculaCardsEffect/MistFormEffect.h"
#include "Application/interaction/EffectContext.h"
#include "Application/UseCases/MoveUseCase.h"

ContinueResult MistFormEffect::Continue(EffectContext &context){

    switch (step)
    {
    case MistFormEffectStep::MOVE_DRACULA:
        return MoveDracula(context);
        break;
    case MistFormEffectStep::GAIN_ACTION:
        return GainAction(context);
        break;
    case MistFormEffectStep::FINISHED:
        return Finished(context);
        break; 
    default:{
        ContinueResult res;
        res.status=ContinueStatus::FINISHED;
        return res;
    }
    }

}
ContinueResult MistFormEffect::MoveDracula(EffectContext& context){
    if(context.context.Selected==-1) return BuildDestinationsMunu(context);
    MoveUseCase::Move(dynamic_cast<Fighter*>(context.context.Gamestate->currnetPlayer->GetHero()),
    emptyNodes[context.context.Selected],context.context.Gamestate->log);
    ContinueResult res;
    res.status=ContinueStatus::CONTINUE;
    step=MistFormEffectStep::GAIN_ACTION;

    return res;

}
ContinueResult MistFormEffect::GainAction(EffectContext& context){
    context.context.Gamestate->log.Add("added 1 actoin for dracula ");
    context.context.Gamestate->currnetPlayer->GetHero()->AddAction();
    step=MistFormEffectStep::FINISHED;
    ContinueResult res;
    res.status=ContinueStatus::CONTINUE;
    return res;
}
ContinueResult MistFormEffect::Finished(EffectContext & context){
    context.context.Selected=-1;
    emptyNodes.clear();

    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}   


ContinueResult MistFormEffect::BuildDestinationsMunu(EffectContext& effectcontext){
    ContinueResult result;
    Board board=effectcontext.context.Gamestate->board;
    this->emptyNodes=board.GetAllEmptyNodes();
    for(int x:emptyNodes){
        result.menu_request.nodes.push_back(x);
    }
    result.status=ContinueStatus::NEEDMENU;
    result.menu_request.type=InputType::NODE;
    result.menu_request.title="Move Dracula ";
    return result;
}
