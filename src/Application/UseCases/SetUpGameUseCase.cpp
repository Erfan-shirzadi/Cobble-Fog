#include "Application/UseCases/SetUpGameUseCase.h"
#include <iostream>
#include "Domain/Entities/Heroes/Dracula.h"
#include "Domain/Entities/Heroes/Holmes.h"
#include "Application/UseCases/PlaceMentUseCase.h"


std::unique_ptr <Hero> SetUpGameUseCase::CreateHero(int choice){
    
    switch (choice)
    {
    case 0:
        return std::make_unique<Dracula> ();
    case 1:
        return std::make_unique<Holmes> ();
    }

}
void SetUpGameUseCase::ShuffelDecks(Hero * hero){
    hero->ShuffelDeck();
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
    context.context.Gamestate->currnetPlayer->SetHero(CreateHero(context.context.Selected));
    std::swap(this->Heroes[context.context.Selected],this->Heroes.back());
    Heroes.pop_back();
    context.context.Selected=-1;

    step=SetUpStep::DRAW_5CARD;

    result.status=ContinueStatus::CONTINUE;

    return result;

    
}
ContinueResult SetUpGameUseCase::Continue(EffectContext & context){

    switch (step)
    {
    case SetUpStep::CHOOSE_HERO:
        return ChooseHero(context);
        break;
    case SetUpStep::DRAW_5CARD:{
        Hero * hero=context.context.Gamestate->currnetPlayer->GetHero();
        hero->ShuffelDeck();
        DrawInitialCards(hero);
        step=SetUpStep::PLACEMENT;
        ContinueResult result;
        result.status=ContinueStatus::CONTINUE;

        return result;
        
    }
    case SetUpStep::PLACEMENT:
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
        
        break;
    case PlaceMentStep::SET_SIDEKICKS:

        break;
    }
    ContinueResult res;
    res.status=ContinueStatus::FINISHED;
    
    return res;
}

ContinueResult SetUpGameUseCase::HeroPlaceMent(EffectContext & context){
    ContinueResult result;
    if(context.context.Selected==-1){
        for(auto x:this->ReachbleHeroesNodes){
            result.menu_request.options.push_back(std::to_string(x));
        }
        result.status=ContinueStatus::NEEDMENU;

        return result;
    }
    
     Hero* hero=context.context.Gamestate->currnetPlayer->GetHero();
     hero->SetNode(ReachbleHeroesNodes[context.context.Selected]);

     this->sidekicks=hero->GetSideKicks();
     context.context.Selected=-1;
     if(!this->sidekicks[index_sideKick]){
        placementstep=PlaceMentStep::FINISHED;
    }else placementstep=PlaceMentStep::SET_SIDEKICKS;
     result.status=ContinueStatus::CONTINUE;

     return result;
}

ContinueResult SetUpGameUseCase::SideKickPlaceMent(EffectContext & context){
    if(context.context.Selected==-1) return SetRechbleSideKickNodes(context);

    sidekicks[index_sideKick]->SetNode(ReachbleSidekickNods[context.context.Selected]);
    context.context.Selected=-1;
    index_sideKick++;
     if(!this->sidekicks[index_sideKick]){
        placementstep=PlaceMentStep::FINISHED;
    }
    ContinueResult result;
    result.status=ContinueStatus::CONTINUE;

    return result;

}



ContinueResult SetUpGameUseCase::SetRechbleSideKickNodes(EffectContext & context){
    ContinueResult result;
    Board board=context.context.Gamestate->board;
    Hero * hero=context.context.Gamestate->currnetPlayer->GetHero();
    this->ReachbleSidekickNods=board.GetNodeofArea(hero->GetNode());

    for(auto x: ReachbleSidekickNods){
        result.menu_request.options.push_back(std::to_string(x));
    }
    result.status=ContinueStatus::NEEDMENU;
    
   
    return result;

}


ContinueResult SetUpGameUseCase::Finished(EffectContext & context){
    context.context.Selected=-1;
    this->index_sideKick=0;
    this->sidekicks.clear();
    this->placementstep=PlaceMentStep::SET_HERO;
    this->step=SetUpStep::CHOOSE_HERO;
    this->ReachbleSidekickNods.clear();
    this->ReachbleHeroesNodes.clear();

    ContinueResult result;
    result.status=ContinueStatus::FINISHED;

    return result;
}
