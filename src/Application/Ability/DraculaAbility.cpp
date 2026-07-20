#include "Application/Ability/DraculaAbility.h"
#include "Application/UseCases/DrawingCardUseCase.h"

ContinueResult DraculaAbility::Continue(EffectContext & context){

    switch (step)
    {
    case DraculaAbilityStep::CHOOSE_TARGET:
        return ChooseTarget(context);
        break;
    case DraculaAbilityStep::DRAW_CARD:{
        DrawingCardUseCase::DrawCard(context.context.Gamestate->currnetPlayer->GetHero());
        step=DraculaAbilityStep::FINISHED;
        ContinueResult result;
        result.status=ContinueStatus::CONTINUE;
    }
        break;
    case DraculaAbilityStep::FINISHED:
    return Finished(context);
    }

    ContinueResult result;
    result.status=ContinueStatus::FINISHED;
    return result;

}
ContinueResult DraculaAbility::BuildTargetMenu(EffectContext& context){
    Hero * dracula=context.context.Gamestate->currnetPlayer->GetHero();
    Hero * enemy=context.context.Gamestate->opponentPlayre->GetHero();
    Board& board=context.context.Gamestate->board;
    if(board.AreAdjacent(dracula->GetNode(),enemy->GetNode())){
        if(!(board.GetNodeType(dracula->GetNode())==NodeType::SECREST 
        && board.GetNodeType(enemy->GetNode())==NodeType::SECREST))
            fighters.push_back(dynamic_cast<Fighter*> (enemy));
    }

    for(auto fighter:dracula->GetSideKicks()){
        if(board.AreAdjacent(dracula->GetNode(),fighter->GetNode())){
            if(!(board.GetNodeType(dracula->GetNode())==NodeType::SECREST 
            && board.GetNodeType(fighter->GetNode())==NodeType::SECREST))
                 fighters.push_back(dynamic_cast<Fighter*> (fighter));
        }
    }

     for(auto fighter:enemy->GetSideKicks()){
        if(board.AreAdjacent(enemy->GetNode(),fighter->GetNode())){
            if(!(board.GetNodeType(enemy->GetNode())==NodeType::SECREST 
            && board.GetNodeType(fighter->GetNode())==NodeType::SECREST))
                 fighters.push_back(dynamic_cast<Fighter*> (fighter));
        }
    }

    ContinueResult result;
    for(auto fighter:fighters){
        result.menu_request.options.push_back(fighter->GetName());

    }
    result.menu_request.title="Choose A Fighter ";
    result.status=ContinueStatus::NEEDMENU;

    return result;

}
ContinueResult DraculaAbility::ChooseTarget(EffectContext &context){
    if(context.context.Selected==-1) return BuildTargetMenu(context);

    fighters[context.context.Selected]->TakeDamge(1);
    context.context.Selected=-1;

    step=DraculaAbilityStep::DRAW_CARD;
    ContinueResult result;
    result.status=ContinueStatus::CONTINUE;

    return result;
}


ContinueResult DraculaAbility::Finished(EffectContext & context){
    ContinueResult result;
    result.status=ContinueStatus::FINISHED;

    context.context.Selected=-1;
    fighters.clear();
    step=DraculaAbilityStep::CHOOSE_TARGET;

    return result;
}
