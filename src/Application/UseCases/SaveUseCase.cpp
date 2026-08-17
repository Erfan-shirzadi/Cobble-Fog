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
    if(gamestate->currnetPlayer==gamestate->player1){
        SaveCurrentPlayerNumber(1);
    }
    else{
        SaveCurrentPlayerNumber(2);
    }
    SaveHandViewStatus(gamestate->handview);
    
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
    std::vector<Fog*> fogs=hero->GetFogs();
    for(int i{};i<fogs.size();i++){
        ofstream sofile("../include/Infrastructure/SavedGames/Game1/Player"+to_string(numberofPlayer)+"/fog"+to_string(i)+".txt");
        sofile<<fogs[i]->GetNode()<<endl;
        sofile.close();
    }
    
}


void SaveUseCase::SaveCurrentPlayerNumber(int number)const{
    ofstream file("../include/Infrastructure/SavedGames/Game1/CurrentPlayer.txt");
    file<<number;
    file.close();
}


void SaveUseCase::SaveHandViewStatus(HandView handview)const{
    ofstream file("../include/Infrastructure/SavedGames/Game1/HandView.txt");
    file<<(int)handview;
    file.close();
}

void SaveUseCase::SaveTurnUseCase(TurnUseCase* turnusecase)const{

    SaveTurnUseCaseStep(turnusecase->GetTurnUseCaseStep());
    SaveCurrentAction(turnusecase->CurrentAction());
    switch (turnusecase->CurrentAction())
    {
    case ActoinType::MANEVER:
        SaveManever(turnusecase->GetManeverUseCase());
        break;
    case ActoinType::SCHEME:
        SaveScheme(turnusecase->GetSchemeUseCase());
        break;
    case ActoinType::ATTACK:
        SaveAttack(turnusecase->GetAttackUseCase());
        break;
    default:
        break;
    }

}


void SaveUseCase::SaveGameViewState(ViewState view)const{
    ofstream file("../include/Infrastructure/SavedGames/Game1/ViewState.txt");
    file<<(int)view;
    file.close();
}

void SaveUseCase::SaveManever(ManeverUseCase & manever)const{
    ofstream file("../include/Infrastructure/SavedGames/Game1/Manever.txt");
    file<<(int)manever.GetStep()<<endl;
    
    for(auto f:manever.GetFighters()){
        file<<f->GetName()<<endl;
        file<<f->GetNode()<<endl;
    }

    Fighter* fighter=manever.SelectedFighter();
    if(fighter){
    file<<fighter->GetName()<<endl;
    file<<fighter->GetNode()<<endl;
    }
    for(auto node:manever.GetRechbleNodes()){
        file<<node<<endl;
    }
    file.close();

}

void SaveUseCase::SaveScheme(SchemeUseCase & scheme)const{
    ofstream file("../include/Infrastructure/SavedGames/Game1/Scheme.txt");
    file<<(int)scheme.GetStep()<<endl;
    
    file<<(int)scheme.GetSelectedCard()->GetCardId()<<endl;
    file.close();

}

void SaveUseCase::SaveAttack(AttackUseCase &)const{

}

void SaveUseCase::SaveTurnUseCaseStep(TurnStep step)const{
    ofstream file("../include/Infrastructure/SavedGames/Game1/TurnUseCase/TurnStep.txt");
    file<<(int)step<<endl;
    file.close();
}

void SaveUseCase::SaveCurrentAction(ActoinType actoin)const{
    ofstream file("../include/Infrastructure/SavedGames/Game1/TurnUseCase/CurrentAction.txt");
    file<<(int)actoin<<endl;
    file.close();
}
