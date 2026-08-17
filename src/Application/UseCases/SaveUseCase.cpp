#include "Application/UseCases/SaveUseCase.h"
#include <fstream>
#include <iostream>
using namespace std;

void SaveUseCase::Save(DataContext data)const{

    SaveGameState(data.context.context.Gamestate);
}

void SaveUseCase::SaveGameState(GameState * gamestate)const{

    SavePlayer(1,gamestate->player1);
    SavePlayer(2,gamestate->player2);
    
}

void SaveUseCase::SavePlayer(int numberofPlayer,Player * player)const{

    cout<<"saveed"<<endl;
    // ofstream file("../include/fuck.txt");
    ofstream ofile("../include/Infrastructure/SavedGames/Game1/Player"+to_string(numberofPlayer)+"/Hero.txt");
    if(!ofile.is_open()){
        cout<<" can not open file";
    }
    Hero * hero=player->GetHero();
    ofile<<hero->GetName()<<endl;
    ofile<<hero->GetHP()<<endl;
    ofile<<hero->GetNode()<<endl;
    ofile<<hero->GetMove()<<endl;
    ofile<<hero->GetRemainingAction()<<endl;
    ofile<<hero->GetStartTurnOnfog()<<endl;

    for(auto card:hero->GetHand()){
        ofile<<(int)card->GetCardId()<<endl;
    }
    for(auto cardid:hero->GetDeck().GetCards()){
        ofile<<(int)cardid<<endl;
    }

    ofile.close();

    std::vector<Fighter* > sidekcik=hero->GetAllsidekick();
    for(int i{};i<sidekcik.size();i++){
        ofstream sofile("../include/Infrastructure/SavedGames/Game1/Player"+to_string(numberofPlayer)+"/sidekick"+to_string(i)+".txt");
        sofile<<sidekcik[i]->GetName()<<endl;
        sofile<<sidekcik[i]->GetHP()<<endl;
        sofile<<sidekcik[i]->GetNode()<<endl;
        sofile.close();
    }
    
}


    void SaveTurnUseCase();
