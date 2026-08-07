#include "Application/CardEffect/DraculaCardsEffect/RaveningSeductoinEffect.h"
#include "Application/interaction/EffectContext.h"

ContinueResult RaveningSeductionEffect::Continue(EffectContext &context){
    switch (step)
    {
    case RaveningStep::CHOOSE_FIGHTER:
        return ChooseFighter(context);
        break;
    case RaveningStep::MOVE_FIGHTER:
        return MoveFighter(context);
        break;
    case RaveningStep::DAMAGE_FIGHTER:
        return DamageFighter(context);
        break;
    }

     ContinueResult result;
     result.status=ContinueStatus::FINISHED;
     return result;
}   


ContinueResult RaveningSeductionEffect::ChooseFighter(EffectContext& context){
    if(context.context.Selected==-1) return BuildFightersMenu(context);

    fighter=Allfighters[context.context.Selected];
    context.context.Selected=-1;

    ContinueResult result;
    result.status=ContinueStatus::CONTINUE;
    step=RaveningStep::MOVE_FIGHTER;

    return result;

}
ContinueResult RaveningSeductionEffect::MoveFighter(EffectContext& context){
    if(context.context.Selected==-1) return BuildDestinationMenu(context);

    fighter->SetNode(this->rechableNodes[context.context.Selected]);
    context.context.Selected=-1;
    ContinueResult result;
    result.status=ContinueStatus::CONTINUE;
    step=RaveningStep::DAMAGE_FIGHTER;

    return result;

}
ContinueResult RaveningSeductionEffect::DamageFighter(EffectContext& context){

    Hero * dracula=context.context.Gamestate->currnetPlayer->GetHero();
    Board board=context.context.Gamestate->board;

    for(auto sister:dracula->GetSideKicks()){
        if(board.AreAdjacent(sister->GetNode(),fighter->GetNode())&& sister->GetNode()!=fighter->GetNode())
            if(!(board.GetNodeType(sister->GetNode())==NodeType::SECREST && board.GetNodeType(fighter->GetNode())==NodeType::SECREST)){
                fighter->TakeDamge(1);
                context.context.Gamestate->log.Add(fighter->GetName()+" damaged 1");
            }
    }
    ContinueResult result ;
    result.status=ContinueStatus::FINISHED;

    return result;
}

ContinueResult RaveningSeductionEffect::BuildFightersMenu(EffectContext& context){
    ContinueResult result;
    Hero* dracula= context.context.Gamestate->currnetPlayer->GetHero();
    Hero * enemy=context.context.Gamestate->opponentPlayre->GetHero();

    for(auto fighter: enemy->GetSideKicks()){
        Allfighters.push_back(fighter);
    }
    for(auto fighter: dracula->GetSideKicks()){
        Allfighters.push_back(fighter);
    }
    Allfighters.push_back(dynamic_cast<Fighter*>(dracula));
    Allfighters.push_back(dynamic_cast<Fighter*>(enemy));

    for(auto fighter: Allfighters){
        result.menu_request.nodes.push_back(fighter->GetNode());
    }
    result.menu_request.title="ALL Fighters";
    result.status=ContinueStatus::NEEDMENU;
    result.menu_request.type=InputType::NODE;

    return result;

}
ContinueResult RaveningSeductionEffect::BuildDestinationMenu(EffectContext& context){
    Board board=context.context.Gamestate->board;

    Hero * hero;
    Hero * enemy;
    if(fighter->GetFighterType()==FighterType::SISTER ||fighter->GetFighterType()==FighterType::DRACULA){
        hero=context.context.Gamestate->currnetPlayer->GetHero();
        enemy=context.context.Gamestate->opponentPlayre->GetHero();
    }
    else {
        hero =context.context.Gamestate->opponentPlayre->GetHero();
            enemy=context.context.Gamestate->opponentPlayre->GetHero();
        }

    rechableNodes=board.reachableNodes(hero,enemy,2,fighter->GetNode());
        ContinueResult res;
        res.status=ContinueStatus::NEEDMENU;
        res.menu_request.type=InputType::NODE;
        for(auto x:rechableNodes)
            res.menu_request.nodes.push_back(x);

        return res;
    
}


