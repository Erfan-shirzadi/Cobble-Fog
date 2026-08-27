#include "Application/UseCases/LoadUseCase.h"
#include "Application/UseCases/CreatCard.h"
#include "Application/CardEffect/CardEffectFactory.h"
#include <fstream>
#include <iostream>
#include <memory>
using namespace std;
void LoadUseCase::Load (DataContext & data, int session){
    sessionNumber=session;
    cout<<"session number :"<<session<<endl;
    LoadGameState(data.context->context.Gamestate);
    
    LoadTurnUseCase(data.TURNUSECASE,data.context->context.Gamestate);
    
    data.context->context.Selected=-1;
    data.context->combatcontext=data.context->context.Gamestate->combatsatat;
}

void LoadUseCase::LoadGameState(GameState * gamestate){
   
    LoadPlayer(1,gamestate->player1);
    LoadPlayer(2,gamestate->player2);
    ifstream ifile("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/CurrentPlayer.txt");
    int n;
    ifile>>n;
    if(n==1){
        gamestate->currnetPlayer=gamestate->player1;
        gamestate->opponentPlayre=gamestate->player2;

    }else {
        gamestate->currnetPlayer=gamestate->player2;
        gamestate->opponentPlayre=gamestate->player1;

    }
    ifile.close();
    ifstream handviewfile("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/HandView.txt");
    handviewfile>>n;
    gamestate->handview=static_cast<HandView>(n);
    handviewfile.close();

    Board & board=gamestate->board;
    board.AddFighter(dynamic_cast<Fighter*>(gamestate->player1->GetHero()),gamestate->player1->GetHero()->GetNode());
    board.AddFighter(dynamic_cast<Fighter*>(gamestate->player2->GetHero()),gamestate->player2->GetHero()->GetNode());

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

   


}
void LoadUseCase::LoadPlayer(int number,Player* player){
    ifstream file("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/Player"+to_string(number)+"/Hero.txt");
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
    ifstream hfile("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/Player"+to_string(number)+"/Hand.txt");
    while (hfile>>n){
        hero->AddCardToHand(std::move(CreatCard::CreatCardid(static_cast<CardId>(n))));
    }
    hfile.close();
    ifstream dfile("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/Player"+to_string(number)+"/Deck.txt");
    Deck& deck=hero->GetDeck();
    deck.ClearDeck();
    while (dfile>>n){
        deck.Add(std::move(CreatCard::CreatCardid(static_cast<CardId>(n))));
    }
    dfile.close();
    ifstream dcfile("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/Player"+to_string(number)+"/DiscadCards.txt");
    
    while (dcfile>>n){
        hero->AddCardToDiscardCards(std::move(CreatCard::CreatCardid(static_cast<CardId>(n))));
    }
    dcfile.close();

    std::vector<Fighter*> sidekick=hero->GetAllsidekick();

    for(int i{};i<sidekick.size();i++){
        ifstream sifile("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/Player"+to_string(number)+"/sidekick"+to_string(i)+".txt");
        sifile>>n;
        sidekick[i]->SetHP(n);
        sifile>>n;
        sidekick[i]->SetNode(n);
        sifile.close();
    }
    std::vector<Fog*>fogs=hero->GetFogs();
    for(int i{};i<fogs.size();i++){
        ifstream sifile("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/Player"+to_string(number)+"/fog"+to_string(i)+".txt");
        sifile>>n;
        fogs[i]->SetNode(n);
        sifile.close();
    }


    
}

void LoadUseCase::LoadTurnUseCase(TurnUseCase* turnusecase,GameState* gamestate){
    ifstream ifile("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/TurnUseCase/TurnStep.txt");
    
    int n;
    ifile>>n;
    
    turnusecase->SetStep(static_cast<TurnStep>(n));
    ifile.close();

    ifstream afile("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/TurnUseCase/CurrentAction.txt");
    afile>>n;
    turnusecase->SetUseCase(n);
    afile.close();


    switch (turnusecase->CurrentAction())
    {
    case ActoinType::MANEVER:
        LoadManever(turnusecase->GetManeverUseCase(),gamestate->currnetPlayer);
        break;
    case ActoinType::SCHEME:
        LoadScheme(turnusecase->GetSchemeUseCase(),gamestate->currnetPlayer);
        break;
    case ActoinType::ATTACK:
        LoadAttck(turnusecase->GetAttackUseCase(),gamestate);
        break;
    
    default:
        break;
    }

}

void LoadUseCase::LoadManever(ManeverUseCase & manever ,Player* player){
    ifstream ifile ("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/TurnUseCase/Manever.txt");
    int n;
    ifile>>n;
    manever.SetStep(static_cast<ManeverStep>(n));
    ifile>>n;
    if(n!=-1){
        for(auto sidekick:player->GetHero()->GetSideKicks()){
            if(n==sidekick->GetNode()){
                manever.SetSelectedFighter(sidekick);
            }
        }
        if(player->GetHero()->GetNode()==n){
            manever.SetSelectedFighter(dynamic_cast<Fighter*>(player->GetHero()));
        }
    }
    ifile.close();

}
void LoadUseCase::LoadScheme(SchemeUseCase & scheme,Player* currentplayer){
    ifstream ifile("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/TurnUseCase/Scheme.txt");
    Hero * hero=currentplayer->GetHero();
    int n;
    ifile>>n;
    scheme.SetStep(static_cast<SchemeStep>(n));
    ifile>>n;
    int cardid=n;
    scheme.SetSelectedCard(hero->GetCardOfDiscardCards(static_cast<CardId>(n)));
    ifile>>n;
    scheme.SetCardEffect(CardEffectFactory::CreatCardEffect(static_cast<CardId>(cardid)),n);
    
    ifile.close();

}
void LoadUseCase::LoadAttck(AttackUseCase & attack,GameState* gamestate){
    ifstream ifile("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/TurnUseCase/attack.txt");
    int n;
    
    ifile>>n;
    attack.SetStep(static_cast<AttackStep>(n));
    ifile>>n;
    attack.SetSetupStep(static_cast<SetUpStep>(n));
    ifile.close();
    LoadCommbatContext(attack.GetCombatcontext(),gamestate);

}
void LoadUseCase::LoadCommbatContext(CombatContext& context,GameState* gamestate){
    ifstream CurrentPlayerfile("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/TurnUseCase/CombatContextCurrent.txt");

    if(!CurrentPlayerfile.is_open())return ;

    Hero* Heroplayer1=gamestate->player1->GetHero();
    Hero * Heroplayer2=gamestate->player2->GetHero();

    context.Current=std::make_unique<CombatParticipant>();
    context.Opponent=std::make_unique<CombatParticipant>();

    ifstream NumberCurrentPlayerfile("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/TurnUseCase/CurrentCombatPlayer.txt");

    int number;
    NumberCurrentPlayerfile>>number;
    if(number==1){
        context.Current->hero=Heroplayer1;
        context.Opponent->hero=Heroplayer2;
    }else {
        context.Current->hero=gamestate->player2->GetHero();
        context.Opponent->hero=gamestate->player1->GetHero();

    }
    NumberCurrentPlayerfile.close();

    CurrentPlayerfile>>number;

    if(context.Current->hero->GetNode()==number){
        context.Current->fighter=dynamic_cast<Fighter*>(context.Current->hero);
    }
    else {
        
        for(auto fighter:context.Current->hero->GetSideKicks()){
           
            if(fighter->GetNode()==number)
                context.Current->fighter=fighter;
        }
    }
   
    

    CurrentPlayerfile>>number;
    if(number!=-1){
        context.Current->card=dynamic_cast<CombatCard*>(context.Current->hero->GetCardOfDiscardCards(static_cast<CardId>(number)));
        context.Current->effect=CardEffectFactory::CreatCardEffect(static_cast<CardId>(number));
        CurrentPlayerfile>>number;
        context.Current->card->SetDamageOrDeffend(number);
    }
    CurrentPlayerfile>>number;
    context.Current->IsActiveCardEffect=static_cast<bool>(number);
    CurrentPlayerfile>>number;
    context.Current->Won=static_cast<bool>(number);
    CurrentPlayerfile>>number;
    context.Current->CanChangeAmountCard=static_cast<bool>(number);
    CurrentPlayerfile.close();


    ifstream OpponentPlayerfile("../include/Infrastructure/SavedGames/Game"+to_string(sessionNumber)+"/TurnUseCase/CombatContextOpponent.txt");
    OpponentPlayerfile>>number;

     if(context.Opponent->hero->GetNode()==number){
        context.Opponent->fighter=dynamic_cast<Fighter*>(context.Opponent->hero);
    }
    else {
        for(auto fighter:context.Opponent->hero->GetSideKicks()){
            if(fighter->GetNode()==number)
                context.Opponent->fighter=fighter;
        }
    }

    OpponentPlayerfile>>number;

    if(number!=-1){
        context.Opponent->effect=CardEffectFactory::CreatCardEffect(static_cast<CardId>(number));
        OpponentPlayerfile>>number;
    }
    OpponentPlayerfile>>number;
    context.Opponent->IsActiveCardEffect=static_cast<bool>(number);
    OpponentPlayerfile>>number;
    context.Opponent->Won=static_cast<bool>(number);
    OpponentPlayerfile>>number;
    context.Opponent->CanChangeAmountCard=static_cast<bool>(number);
    OpponentPlayerfile.close();

    gamestate->combatsatat=&context;


}
