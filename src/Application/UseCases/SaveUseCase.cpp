#include "Application/UseCases/SaveUseCase.h"
#include <fstream>
#include <iostream>
#include <filesystem>
using namespace std;

void SaveUseCase::SetFolderPath(){

    std::string folderpathPlayer2="/home/lionborn/programs/projects/PROJECT/Cobble & fog/Cobble-Fog/include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/Player2/";
    std::string folderpathPlayer1="/home/lionborn/programs/projects/PROJECT/Cobble & fog/Cobble-Fog/include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/Player1/";
    std::string foderpathTurnusecase="/home/lionborn/programs/projects/PROJECT/Cobble & fog/Cobble-Fog/include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/TurnUseCase/";
    std::string folderpathGame="/home/lionborn/programs/projects/PROJECT/Cobble & fog/Cobble-Fog/include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"";

}



void SaveUseCase::Save(DataContext data,int session){

    sessionNumber=session;
    SetFolderPath();
    UpdateSessionFile(session);
    RemoveTxtFiles(folderpathPlayer1);
    RemoveTxtFiles(folderpathPlayer2);
    // RemoveTxtFiles(folderpathGame);
    RemoveTxtFiles(foderpathTurnusecase);


    SaveGameState(data.context->context.Gamestate);
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
        ofstream currentplayerCombat("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/TurnUseCase/CurrentCombatPlayer.txt");
        if(gamestate->player1->GetHero()==gamestate->combatsatat->Current->hero){
            currentplayerCombat<<1;
        }else currentplayerCombat<<2;
        currentplayerCombat.close();
    }
    
}

void SaveUseCase::SavePlayer(int numberofPlayer,Player * player)const{

    cout<<"saveed"<<endl;
    // ofstream file("../include/fuck.txt");
    ofstream ofile("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/Player"+to_string(numberofPlayer)+"/Hero.txt");
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

    ofstream cfile("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/Player"+to_string(numberofPlayer)+"/Hand.txt");
    for(auto card:hero->GetHand()){
        cfile<<(int)card->GetCardId()<<endl;
    }
    cfile.close();
    ofstream dfile("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/Player"+to_string(numberofPlayer)+"/Deck.txt");

    for(auto cardid:hero->GetDeck().GetCards()){
        dfile<<(int)cardid<<endl;
    }
    dfile.close();
    ofile.close();

    ofstream dcfile("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/Player"+to_string(numberofPlayer)+"/DiscadCards.txt");
    for(auto card: hero->GetDiscardCards()){
        dcfile<<(int)card->GetCardId()<<std::endl;
    }
    dcfile.close();

    std::vector<Fighter* > sidekcik=hero->GetAllsidekick();
    for(int i{};i<sidekcik.size();i++){
        ofstream sofile("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/Player"+to_string(numberofPlayer)+"/sidekick"+to_string(i)+".txt");
        // sofile<<(int)sidekcik[i]->GetFighterType()<<endl;
        sofile<<sidekcik[i]->GetHP()<<endl;
        sofile<<sidekcik[i]->GetNode()<<endl;
        sofile.close();
    }
    std::vector<Fog*> fogs=hero->GetFogs();
    for(int i{};i<fogs.size();i++){
        ofstream sofile("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/Player"+to_string(numberofPlayer)+"/fog"+to_string(i)+".txt");
        sofile<<fogs[i]->GetNode()<<endl;
        sofile.close();
    }
    
}


void SaveUseCase::SaveCurrentPlayerNumber(int number)const{
    ofstream file("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/CurrentPlayer.txt");
    file<<number;
    file.close();
}


void SaveUseCase::SaveHandViewStatus(HandView handview)const{
    ofstream file("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/HandView.txt");
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
    ofstream file("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/ViewState.txt");
    file<<(int)view;
    file.close();
}

void SaveUseCase::SaveManever(ManeverUseCase & manever)const{
    ofstream file("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/TurnUseCase/Manever.txt");
    file<<(int)manever.GetStep()<<endl;
    
    // for(auto f:manever.GetFighters()){
    //     file<<f->GetName()<<endl;
    //     file<<f->GetNode()<<endl;
    // }

    Fighter* fighter=manever.SelectedFighter();
    if(fighter){
        // file<<fighter->GetName()<<endl;
        file<<fighter->GetNode()<<endl;
    }
    else {
        file<<-1<<endl;

    }

    // for(auto node:manever.GetRechbleNodes()){
    //     file<<node<<endl;
    // }
    file.close();

}

void SaveUseCase::SaveScheme(SchemeUseCase & scheme)const{
    ofstream file("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/TurnUseCase/Scheme.txt");
    file<<(int)scheme.GetStep()<<endl;
    if(scheme.GetSelectedCard())
        file<<(int)scheme.GetSelectedCard()->GetCardId()<<endl;
    file.close();

}

void SaveUseCase::SaveAttack(AttackUseCase & attack)const{
    ofstream file("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/TurnUseCase/attack.txt");
    file<<(int)attack.GetStep()<<endl;
    file<<(int)attack.GetStepSetup()<<endl;
    // cout<< attack.GetAttackers().size()<<endl;
    // for(auto fighter: attack.GetAttackers()){
    //     file<<fighter->GetName()<<endl;
    //     file<<fighter->GetNode()<<endl;
    // }
    // for(auto card : attack.GetAttackerCards()){
    //     file<<(int)card->GetCardId()<<endl;
    // }
    // for(auto fighter: attack.GetDeffenders()){
    //     file<<fighter->GetName()<<endl;
    //     file<<fighter->GetNode()<<endl;
    // }
    // for(auto card : attack.GetDeffenderCards()){
    //     file<<(int)card->GetCardId()<<endl;
    // }
    file.close();
}

void SaveUseCase::SaveTurnUseCaseStep(TurnStep step)const{
    ofstream file("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/TurnUseCase/TurnStep.txt");
    file<<(int)step<<endl;
    file.close();
}

void SaveUseCase::SaveCurrentAction(ActoinType actoin)const{
    ofstream file("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/TurnUseCase/CurrentAction.txt");
    file<<(int)actoin<<endl;
    file.close();
}


void SaveUseCase::SaveCombatContext(CombatContext* context)const{
    ofstream file("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/TurnUseCase/CombatContextCurrent.txt");

    // if(context->Current->hero){
    //     file<<context->Current->hero->GetName()<<endl;
    // }else file<<-1<<endl;
        // file<<context->Current->fighter->GetName()<<endl;
    if(context->Current->fighter){
        file<<context->Current->fighter->GetNode()<<endl;
    }else file<<-1<<endl;
    if(context->Current->card){
        file<<(int)context->Current->card->GetCardId()<<endl;
        file<<context->Current->card->GetDamgeOrDeffend()<<endl;
    }else file<<-1<<endl;
        file<<context->Current->IsActiveCardEffect<<endl;
        file<<context->Current->Won<<endl;
        file<<context->Current->CanChangeAmountCard<<endl;
        
    
    file.close();
    ofstream ofile("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/TurnUseCase/CombatContextOpponent.txt");

    // if(context->Opponent->hero){
    //     ofile<<context->Opponent->hero->GetName()<<endl;
    // }else ofile<<-1<<endl;
    if(context->Opponent->fighter){
        ofile<<context->Opponent->fighter->GetNode()<<endl;
    }else ofile<<-1<<endl;
    if(context->Opponent->card){
            ofile<<(int)context->Opponent->card->GetCardId()<<endl;
            ofile<<context->Opponent->card->GetDamgeOrDeffend()<<endl;
    }else{
        ofile<<-1<<endl;
    }
        ofile<<context->Opponent->IsActiveCardEffect<<endl;
        ofile<<context->Opponent->Won<<endl;
        ofile<<context->Opponent->CanChangeAmountCard<<endl;
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


void SaveUseCase::UpdateSessionFile(int number){
    ifstream file("../include/Infrastructure/SavedGames/Sessions.txt",ios::in);
    ofstream test("../include/Infrastructure/SavedGames/test.txt");
    if(!file){
        ofstream ofile("../include/Infrastructure/SavedGames/Sessions.txt");
        ofile<<0<<endl;
        ofile<<0<<endl;
        ofile<<0<<endl;

        ofile.close();
    }

    int n;
    cout<<number<<endl;
    for(int i{};i<3;i++){
        file>>n;
        cout<<n;
        if(i==number){
            test<<1<<endl;
        }
        else{
            test<<n<<endl;
        }
    }
    
    std::remove("../include/Infrastructure/SavedGames/Sessions.txt");
    std::rename("../include/Infrastructure/SavedGames/test.txt","../include/Infrastructure/SavedGames/Sessions.txt");
    file.close();
    test.close();
}

std::vector<std::string> SaveUseCase::GetSessionStatus()const{
    ifstream file("../include/Infrastructure/SavedGames/Sessions.txt",ios::in);
    vector<string> options;
    if(!file){
        options={"Empty","Empty","Empty"};
        file.close();
        return options;
    }

    int n;
    for(int i{};i<3;i++){
        file>>n;
        if(n==0){
            options.push_back("Empty");
        }
        else if(n==1) options.push_back("Occupied");
        // else options.push_back("Error");
    }
        file.close();

    return options;

}
