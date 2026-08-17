#include "Application/UseCases/LoadUseCase.h"
#include <fstream>

using namespace std;
void LoadUseCase::Load (DataContext & data){
    LoadGameState(data.context.context.Gamestate);
}

void LoadUseCase::LoadGameState(GameState * gamestate){
    gamestate->player1=new Player;
    gamestate->player2=new Player;

    LoadPlayer(1,gamestate->player1);
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


}
