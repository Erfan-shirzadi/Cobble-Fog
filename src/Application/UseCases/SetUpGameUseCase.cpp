#include "Application/UseCases/SetUpGameUseCase.h"
#include <iostream>
#include "Domain/Entities/Heroes/Dracula.h"
#include "Domain/Entities/Heroes/Holmes.h"
#include "Application/UseCases/PlaceMentUseCase.h"

void SetUpGameUseCase::execute(GameState & gamestate){
    PlaceMentUseCase placement;
    for(int i{};i<2;i++){
        CreateHero(gamestate.currnetPlayer);
        ShuffelDecks(gamestate.currnetPlayer->GetHero());
        DrawInitialCards(gamestate.currnetPlayer->GetHero());
        placement.execute(gamestate);
        std::swap(gamestate.currnetPlayer,gamestate.opponentPlayre);
    }

}

void SetUpGameUseCase::CreateHero(Player * player ){
    std::cout<<" Choose Your hero "<<std::endl;
    
    int choice;
    while (true)
    {
        std::cout<< "Enter A number :";
        std::cin>>choice;
        if(choice<0 || choice>=2){
            std::cout<< "Enter a number between 0 , 1";
        }
        else{
            break;
        }
    }
    
    
    switch (choice)
    {
    case 0:
        player->SetHero(std::make_unique<Dracula> ());
        break;
    
    case 1:
        player->SetHero(std::make_unique<Holmes> ());
        break;
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
