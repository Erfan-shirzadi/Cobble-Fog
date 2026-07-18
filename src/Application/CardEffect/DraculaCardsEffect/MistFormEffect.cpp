#include "Application/CardEffect/DraculaCardsEffect/MistFormEffect.h"

ContinueResult MistFormEffect::Continue(EffectContext &){

    switch (step)
    {
    case MistFormEffectStep::MOVE_DRACULA:
        /* code */
        break;
    case MistFormEffectStep::GAIN_ACTION:
        /* code */
        break;
    case MistFormEffectStep::FINISHED:
        /* code */
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

    context.combatcontext->Current->hero->SetNode(emptyNodes[context.context.Selected]);
    ContinueResult res;
    res.status=ContinueStatus::CONTINUE;
    step=MistFormEffectStep::GAIN_ACTION;

}
ContinueResult MistFormEffect::GainAction(EffectContext& context){
    context.combatcontext->Current->hero->AddAction();
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
        result.menu_request.options.push_back(std::to_string(x));
    }
    result.status=ContinueStatus::NEEDMENU;
    result.menu_request.title="Move Dracula ";
    return result;
}
