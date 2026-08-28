#include "Application/UseCases/SetUpGameUseCase.h"

#include "Domain/Entities/Heroes/Dracula.h"
#include "Domain/Entities/Heroes/Holmes.h"
#include "Domain/Entities/Heroes/InvisibleMan.h"



std::unique_ptr <Hero> SetUpGameUseCase::CreateHero(int choice){
    
    switch (choice)
    {
    case 0:
        return std::make_unique<Dracula> ();
        break;
    case 1:
        return std::make_unique<Holmes> ();
        break;
    case 2:
        return std::make_unique<InvisibleMan>();
        break;
    }

    return std::make_unique<InvisibleMan>();

    
}
void SetUpGameUseCase::DrawInitialCards(Hero * hero){
    for(int i{};i<5;i++){
        hero->DrawCard();
    }
}


ContinueResult SetUpGameUseCase::ChooseHero(EffectContext & context){
    ContinueResult result;
    if(context.context.Selected==-1){
        for(auto hero: Heroes)
            result.menu_request.options.push_back(hero);
        result.menu_request.title="Select Your Hero";
        result.status=ContinueStatus::NEEDMENU;
        return result;
    }
    std::swap(this->Heroes[context.context.Selected],this->Heroes.back());
    Heroes.pop_back();
    context.context.Selected=-1;
    
    step=SetUpGameStep::DRAW_5CARD;

    result.status=ContinueStatus::CONTINUE;

    return result;

    
}
ContinueResult SetUpGameUseCase::Continue(EffectContext & context){

    switch (step)
    {
    case SetUpGameStep::CHOOSE_HERO:
        return ChooseHero(context);
        break;
    case SetUpGameStep::DRAW_5CARD:{
       
        Hero * hero=context.context.Gamestate->currnetPlayer->GetHero();
        hero->ShuffelDeck();
        DrawInitialCards(hero);
        step=SetUpGameStep::PLACEMENT;
        ContinueResult result;
        result.status=ContinueStatus::CONTINUE;

        return result;
        
    }
    case SetUpGameStep::PLACEMENT:
        return PlaceMent(context);
        break;
    }
    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    return res;
}
ContinueResult SetUpGameUseCase::PlaceMent(EffectContext & context){

    switch (placementstep)
    {
    case PlaceMentStep::SET_HERO:
        return HeroPlaceMent(context);
        break;
    case PlaceMentStep::SET_SIDEKICKS:
        return SideKickPlaceMent(context);
    case PlaceMentStep::FINISHED:
        return Finished(context);
    }
    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    
    return res;
}

ContinueResult SetUpGameUseCase::HeroPlaceMent(EffectContext & context){
    ContinueResult result;
    if(context.context.Selected==-1){
        for(auto x:this->ReachbleHeroesNodes){
           result.menu_request.nodes.push_back(x);
           
        }
        result.status=ContinueStatus::NEEDMENU;

        return result;
    }
    Board& board =context.context.Gamestate->board;
    Hero* hero=context.context.Gamestate->currnetPlayer->GetHero();
    
    board.AddFighter(dynamic_cast<Fighter*>(hero),ReachbleHeroesNodes[context.context.Selected]);
    std::swap(ReachbleHeroesNodes[context.context.Selected],ReachbleHeroesNodes.back());
    ReachbleHeroesNodes.pop_back();
     this->sidekicks=hero->GetSideKicks();
     this->fogs=hero->GetFogs();

     context.context.Selected=-1;
     if(sidekicks.empty() && fogs.empty()){
        placementstep=PlaceMentStep::FINISHED;
    }else {
        placementstep=PlaceMentStep::SET_SIDEKICKS;
        Board & board=context.context.Gamestate->board;
        this->ReachbleSidekickNods=board.GetNodeofArea(hero->GetNode());
    }
     result.status=ContinueStatus::CONTINUE;

     return result;
}

ContinueResult SetUpGameUseCase::SideKickPlaceMent(EffectContext & context){
    if(context.context.Selected==-1) return SetRechbleSideKickNodes(context);

    Board& board =context.context.Gamestate->board;

    if(fogs.empty()){
        board.AddFighter(dynamic_cast<Fighter*>(sidekicks[index_sideKick]),ReachbleSidekickNods[context.context.Selected]);
            index_sideKick++;
    }
    else if(sidekicks.empty())
    {
        // std::cout<<fogs.size()<<std::endl;
        board.AddFog(fogs[index_sideKick],ReachbleSidekickNods[context.context.Selected]);
            index_sideKick++;

    }

    // std::cout<<sidekicks[index_sideKick]->GetName()<<" Set at "<<ReachbleSidekickNods[context.context.Selected]<<std::endl;
    std::swap(ReachbleSidekickNods[context.context.Selected],ReachbleSidekickNods.back());
    ReachbleSidekickNods.pop_back();
    context.context.Selected=-1;
    
    
    // index_sideKick++;
    if(fogs.empty()){
        if(index_sideKick >= sidekicks.size()){
            placementstep=PlaceMentStep::FINISHED;

        }
    }
    else{
        if(index_sideKick>=fogs.size()){
            placementstep=PlaceMentStep::FINISHED;
        }
    }
    ContinueResult result;
    result.status=ContinueStatus::CONTINUE;

    return result;

}



ContinueResult SetUpGameUseCase::SetRechbleSideKickNodes(EffectContext & context){
    ContinueResult result;
    Hero * hero=context.context.Gamestate->currnetPlayer->GetHero();
    for(auto x: ReachbleSidekickNods){
        result.menu_request.nodes.push_back(x);
    }
    result.status=ContinueStatus::NEEDMENU;
    
   
    return result;

}


ContinueResult SetUpGameUseCase::Finished(EffectContext & context){
    context.context.Selected=-1;
    this->countplayerWhoSetuped++;
    this->index_sideKick=0;
    this->sidekicks.clear();
    this->placementstep=PlaceMentStep::SET_HERO;
    this->step=SetUpGameStep::DRAW_5CARD;
    this->ReachbleSidekickNods.clear();
    ContinueResult result;
    std::swap(context.context.Gamestate->currnetPlayer,context.context.Gamestate->opponentPlayre);

    if(countplayerWhoSetuped==2){
    result.status=ContinueStatus::FINISHED;
    Heroes={"Dracula","Holmes"};
    ReachbleHeroesNodes={1,26};
    countplayerWhoSetuped=0;
    }

    return result;
}

