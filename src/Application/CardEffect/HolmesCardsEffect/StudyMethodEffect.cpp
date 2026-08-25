#include "Application/CardEffect/HolmesCardsEffect/StudyMethod.h"
#include "Application/interaction/EffectContext.h"

ContinueResult StudyMethod::Continue(EffectContext & context){
    
    ContinueResult res;

    if(context.context.Selected==-1){
        context.context.Gamestate->handview=HandView::OPPONENTPLAYER;
        res.menu_request.options.push_back("End turn");
        res.menu_request.type=InputType::QUESTION;
        context.context.Gamestate->log.Add("Answer Questoin");
        res.status=ContinueStatus::NEEDMENU;
        return res;
    }
    
    if(context.context.Selected==0)
        res.status=ContinueStatus::FINISHED;

    context.context.Gamestate->handview=HandView::CURRENTPLAYER;
    res.status=ContinueStatus::FINISHED;

    return res;
}
