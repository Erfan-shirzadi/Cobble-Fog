#include "Domain/Game/GameEngine.h"
#include "Application/UseCases/SetUpGameUseCase.h"
#include "Application/UseCases/TurnUseCase.h"
#include "Application/interaction/EffectContext.h"
#include "Domain/Game/DataContext.h"


GameEngine::GameEngine():view(gamestate){
}


void GameEngine::run(){
    
    gamestate.board=board;
    context.context.Gamestate=&gamestate;
    context.context.Selected=-1;

   
    view.SetOnSelection([&](int value){this->OnSelection(value);});
    view.Run();    

}




void GameEngine::Start(){
     this->TURNUSECASE->Start(context);
    Process();
}

void GameEngine::InitialObjects(){
    this->TURNUSECASE=new TurnUseCase;
    state=GameEngineState::HERO_SELECTION;
    
    gamestate.player1=new Player;
    gamestate.player2=new Player;
}


void GameEngine::Process(){
    
    while (true){

       
       
        ContinueResult result=TURNUSECASE->Continue(context);

        

        if(GameOver()){
            state=GameEngineState::GAMEOVER;
            
            Hero* current=gamestate.currnetPlayer->GetHero();
            if(current->IsAlive()){
                if(current->GetFighterType()==FighterType::SHERLOCK){
                    gamestate.gameresult=GameResult::SHERLOCK_WON;
                }
                else gamestate.gameresult=GameResult::DRACULA_WON;
            }
            else{
                if(current->GetFighterType()==FighterType::SHERLOCK){
                    gamestate.gameresult=GameResult::DRACULA_WON;
                }
                else gamestate.gameresult=GameResult::SHERLOCK_WON;
            }
            view.SetState(ViewState::GAMEOVER);
            DeleteObjects();
            return;
        }
        
        if(result.status==ContinueStatus::NEEDMENU){
            view.SetInputRequest(result.menu_request);
            return;
        }

        if(result.status==ContinueStatus::FINISHED){
            std::swap(this->gamestate.currnetPlayer,gamestate.opponentPlayre);
            TURNUSECASE->Start(context);
            continue;
        }
    }
    

}
void GameEngine::OnSelection(int selection){

    context.context.Selected=selection;

    if(selection==-2){
        
        MenuRequest request;
        request.options=saveuseCase.GetSessionStatus();
        request.type=InputType::SAVE;
        view.SetInputRequest(request);
    

        this->state=GameEngineState::SAVE_GAME;
        
        return;
    }
    if(selection==-3){
        
        MenuRequest request;
        request.options=saveuseCase.GetSessionStatus();
        request.type=InputType::LOAD;
        view.SetInputRequest(request);
        view.SetState(ViewState::SESSION);


        this->state=GameEngineState::LOAD_GAME;
       
        return;
    }
    if(selection==-4){
        DeleteObjects();
        return;
    }
    switch (state)
    {
    case GameEngineState::START_GAME:
        InitialObjects();
        break;
    case GameEngineState::HERO_SELECTION:
        gamestate.currnetPlayer->SetHero(selection);
        std::swap(gamestate.currnetPlayer,gamestate.opponentPlayre);
        if(gamestate.player1->GetHero()&&gamestate.player2->GetHero()){
            state=GameEngineState::SETUP;
           
        }
        break;
    case GameEngineState::GAME:
        Process();
        break;
    case GameEngineState::SETUP:
        SetUp();
        break;
    case GameEngineState::GAMEOVER:
        state=GameEngineState::START_GAME;
        break;
    case GameEngineState::SAVE_GAME:
        SaveGame();
        break;
    case GameEngineState::LOAD_GAME:
        LoadGame();
        break;
    }
}

void GameEngine::SetUp(){

    while (true)
    {
        ContinueResult result= setup.Continue(context);
        if(result.status==ContinueStatus::NEEDMENU){
            view.SetInputRequest(result.menu_request);
            return;
        }

        if(result.status==ContinueStatus::FINISHED){
            state=GameEngineState::GAME;
            view.SetState(ViewState::GAME);
            
            TURNUSECASE->Start(context);
               
            return;
        }

    }
    
}


bool GameEngine::GameOver( ){
   
    Hero* current=gamestate.currnetPlayer->GetHero();
    
    if(gamestate.opponentPlayre){
        // std::cout<<"IN game oveeer test 4 "std::endl
    }
    Hero* opponent=gamestate.opponentPlayre->GetHero();
    

    if(!current->IsAlive() || !opponent->IsAlive())
        return true;
    return false;

}

void GameEngine::DeleteObjects(){
    state=GameEngineState::START_GAME;
    
    delete TURNUSECASE;
    gamestate.board.ResetBoard();
    delete gamestate.player1;
    delete gamestate.player2;

    gamestate.combatsatat=nullptr;
    

}

void GameEngine::SaveGame(){

    
    data.gameviewstate=view.GetState();
    data.context=&this->context;
    data.TURNUSECASE=this->TURNUSECASE;

    saveuseCase.Save(data,context.context.Selected);
    context.context.Selected=-1;

    DeleteObjects();
    

    
}

void GameEngine::LoadGame(){
    
    
    InitialObjects();

    data.gameviewstate=view.GetState();
    data.context=&this->context;
    data.TURNUSECASE=this->TURNUSECASE;

    loaduseCase.Load(data,context.context.Selected);
    context.context.Selected=-1;
   
    state=GameEngineState::GAME;
    view.SetState(ViewState::GAME);
}
