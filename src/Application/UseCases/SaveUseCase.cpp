#include "Application/UseCases/SaveUseCase.h"
#include <fstream>
using namespace std;

void SaveUseCase::Save(DataContext data)const{

    SaveGameState(data.context.context.Gamestate);
}

void SaveUseCase::SaveGameState(GameState * gamestate)const{

    
}

void SaveUseCase::SavePlayer(int numberofPlayer,Player * player)const{

    ofstream ofile("../include/Infrastructure/SavedGame/Game1/Player"+to_string(numberofPlayer)+"/Hero.txt");
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

}


    void SaveTurnUseCase();
