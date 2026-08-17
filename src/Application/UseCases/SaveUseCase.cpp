#include "Application/UseCases/SaveUseCase.h"
#include <fstream>
#include <iostream>
#include <filesystem>
using namespace std;

void SaveUseCase::Save(DataContext data)const{

    RemoveTxtFiles(folderpathPlayer1);
    RemoveTxtFiles(folderpathPlayer2);
    RemoveTxtFiles(folderpathGame);
    RemoveTxtFiles(foderpathTurnusecase);


    SaveGameState(data.context.context.Gamestate);
    SaveTurnUseCase(data.TURNUSECASE);
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
    if(gamestate->combatsatat){
        SaveCombatContext(gamestate->combatsatat);
    }
    
}

void SaveUseCase::SavePlayer(int numberofPlayer,Player * player)const{

    cout<<"saveed"<<endl;
    // ofstream file("../include/fuck.txt");
    ofstream ofile("../include/Infrastructure/SavedGames/Game1/Player"+to_string(numberofPlayer)+"/Hero.txt");
    if(!ofile.is_open()){
        cout<<" can not open file";
    }
    Hero * hero=player->GetHero();
    ofile<<(int)hero->GetFighterType()<<endl;
    ofile<<hero->GetHP()<<endl;
    ofile<<hero->GetNode()<<endl;
    ofile<<hero->GetMove()<<endl;
    ofile<<hero->GetRemainingAction()<<endl;
    ofile<<hero->GetStartTurnOnfog()<<endl;

    ofstream cfile("../include/Infrastructure/SavedGames/Game1/Player"+to_string(numberofPlayer)+"/Hand.txt");
    for(auto card:hero->GetHand()){
        cfile<<(int)card->GetCardId()<<endl;
    }
    cfile.close();
    ofstream dfile("../include/Infrastructure/SavedGames/Game1/Player"+to_string(numberofPlayer)+"/Deck.txt");

    for(auto cardid:hero->GetDeck().GetCards()){
        dfile<<(int)cardid<<endl;
    }
    dfile.close();
    ofile.close();

    std::vector<Fighter* > sidekcik=hero->GetAllsidekick();
    for(int i{};i<sidekcik.size();i++){
        ofstream sofile("../include/Infrastructure/SavedGames/Game1/Player"+to_string(numberofPlayer)+"/sidekick"+to_string(i)+".txt");
        // sofile<<(int)sidekcik[i]->GetFighterType()<<endl;
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
    ofstream file("../include/Infrastructure/SavedGames/Game1/TurnUseCase/Manever.txt");
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
    ofstream file("../include/Infrastructure/SavedGames/Game1/TurnUseCase/Scheme.txt");
    file<<(int)scheme.GetStep()<<endl;
    
    file<<(int)scheme.GetSelectedCard()->GetCardId()<<endl;
    file.close();

}

void SaveUseCase::SaveAttack(AttackUseCase & attack)const{
    ofstream file("../include/Infrastructure/SavedGames/Game1/TurnUseCase/attack.txt");
    file<<(int)attack.GetStep()<<endl;
    file<<(int)attack.GetStepSetup()<<endl;
    cout<< attack.GetAttackers().size()<<endl;
    for(auto fighter: attack.GetAttackers()){
        file<<fighter->GetName()<<endl;
        file<<fighter->GetNode()<<endl;
    }
    for(auto card : attack.GetAttackerCards()){
        file<<(int)card->GetCardId()<<endl;
    }
    for(auto fighter: attack.GetDeffenders()){
        file<<fighter->GetName()<<endl;
        file<<fighter->GetNode()<<endl;
    }
    for(auto card : attack.GetDeffenderCards()){
        file<<(int)card->GetCardId()<<endl;
    }
    file.close();
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


void SaveUseCase::SaveCombatContext(CombatContext* context)const{
    ofstream file("../include/Infrastructure/SavedGames/Game1/TurnUseCase/CombatContextCurrent.txt");

    file<<context->Current->hero->GetName()<<endl;
    file<<context->Current->fighter->GetName()<<endl;
    file<<context->Current->fighter->GetNode()<<endl;
    file<<context->Current->IsActiveCardEffect<<endl;
    file<<context->Current->Won<<endl;
    file<<context->Current->CanChangeAmountCard<<endl;
    if(context->Current->card){
        file<<(int)context->Current->card->GetCardId()<<endl;
        file<<context->Current->card->GetDamgeOrDeffend()<<endl;
    }
    file.close();
    ofstream ofile("../include/Infrastructure/SavedGames/Game1/TurnUseCase/CombatContextOpponent.txt");

    ofile<<context->Opponent->hero->GetName()<<endl;
    ofile<<context->Opponent->fighter->GetName()<<endl;
    ofile<<context->Opponent->fighter->GetNode()<<endl;
    ofile<<context->Opponent->IsActiveCardEffect<<endl;
    ofile<<context->Opponent->Won<<endl;
    ofile<<context->Opponent->CanChangeAmountCard<<endl;
    if(context->Opponent->card){
        ofile<<(int)context->Opponent->card->GetCardId()<<endl;
        ofile<<context->Opponent->card->GetDamgeOrDeffend()<<endl;
    }
    ofile.close();



}

void SaveUseCase::RemoveTxtFiles(std::string folderpath)const{

    try{
        for(const auto & entry : filesystem::directory_iterator(folderpath)){
            if(entry.is_regular_file()&& entry.path().extension()==".txt")
                filesystem::remove(entry.path());
        }
    }
    catch (const filesystem::filesystem_error & e){
        cout<<" erorr"<<e.what()<<endl;
    }
}
