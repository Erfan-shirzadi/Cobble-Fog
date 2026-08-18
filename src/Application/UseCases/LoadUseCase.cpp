#include "Application/UseCases/LoadUseCase.h"
#include "Application/UseCases/CreatCard.h"
#include <fstream>
#include <iostream>
using namespace std;
void LoadUseCase::Load (DataContext & data){
    LoadGameState(data.context.context.Gamestate);
    data.TURNUSECASE=new TurnUseCase;
    
}

void LoadUseCase::LoadGameState(GameState * gamestate){
    gamestate->player1=new Player;
    gamestate->player2=new Player;

    LoadPlayer(1,gamestate->player1);
    LoadPlayer(2,gamestate->player2);
    ifstream ifile("../include/Infrastructure/SavedGames/Game1/CurrentPlayer.txt");
    int n;
    ifile>>n;
    if(n==1){
        gamestate->currnetPlayer=gamestate->player1;
    }else gamestate->opponentPlayre=gamestate->player2;
    ifile.close();
    ifstream handviewfile("../include/Infrastructure/SavedGames/Game1/HandView.txt");
    handviewfile>>n;
    gamestate->handview=static_cast<HandView>(n);
    handviewfile.close();

    Board  board=gamestate->board;
    for(auto fighter:gamestate->player1->GetHero()->GetAllsidekick()){
        board.AddFighter(fighter,fighter->GetNode());
    }
    for(auto fighter:gamestate->player2->GetHero()->GetAllsidekick()){
        board.AddFighter(fighter,fighter->GetNode());
    }
    for(auto fog:gamestate->player2->GetHero()->GetFogs()){
        board.AddFog(fog,fog->GetNode());
    }
    for(auto fog:gamestate->player1->GetHero()->GetFogs()){
        board.AddFog(fog,fog->GetNode());
    }

    cout<< "GAme State Loaded "<<endl;


}
void LoadUseCase::LoadPlayer(int number,Player* player){
    ifstream file("../include/Infrastructure/SavedGames/Game1/Player"+to_string(number)+"/Hero.txt");
    int n;
    file>>n;
    player->SetHero(n);
    Hero * hero=player->GetHero();
    file>>n;
    hero->SetHP(n);
    file>>n;
    hero->SetNode(n);
    file>>n;
    hero->SetMove(n);
    file>>n;
    hero->SetRemainingAction(n);
    file>>n;
    hero->SetStartTurnOnfog(static_cast<bool>(n));
    file.close();
    ifstream hfile("../include/Infrastructure/SavedGames/Game1/Player"+to_string(number)+"/Hand.txt");
    while (hfile>>n){
        hero->AddCardToHand(std::move(CreatCard::CreatCardid(static_cast<CardId>(n))));
    }
    hfile.close();
    ifstream dfile("../include/Infrastructure/SavedGames/Game1/Player"+to_string(number)+"/Deck.txt");
    Deck& deck=hero->GetDeck();
    deck.ClearDeck();
    while (dfile>>n){
        deck.Add(std::move(CreatCard::CreatCardid(static_cast<CardId>(n))));
    }
    dfile.close();

    std::vector<Fighter*> sidekick=hero->GetAllsidekick();

    for(int i{};i<sidekick.size();i++){
        ifstream sifile("../include/Infrastructure/SavedGames/Game1/Player"+to_string(number)+"/sidekick"+to_string(i)+".txt");
        sifile>>n;
        sidekick[i]->SetHP(n);
        sifile>>n;
        sidekick[i]->SetNode(n);
        sifile.close();
    }
    std::vector<Fog*>fogs=hero->GetFogs();
    for(int i{};i<fogs.size();i++){
        ifstream sifile("../include/Infrastructure/SavedGames/Game1/Player"+to_string(number)+"/fog"+to_string(i)+".txt");
        sifile>>n;
        fogs[i]->SetNode(n);
        sifile.close();
    }


    for(auto s: sidekick){
        cout<<s->GetName()<<endl;
    }
    cout<< hero->GetName()<<endl;
}
