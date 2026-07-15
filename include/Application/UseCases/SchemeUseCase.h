#ifndef SCHEME_USECASE
#define SCHEME_USECASE
#include "Domain/Game/GameState.h"
#include "Application/interaction/ContinueResult.h"
#include "presentation/console/GameView.h"

enum class Step{
    CHOOSECARD,
    EXECUTECARD,
    FINISHED
};
class SchemeUseCase{

    Step step=Step::CHOOSECARD;
    GameState gamestate;
    Card * card=nullptr;
    ActionContext context;
    GameView view;
    public:
    explicit SchemeUseCase(GameState &);
    bool execute(GameState & gamestate);
    bool CanDoAction(GameState & gamestate);
    Card * CardSelection(Hero * hero);



    ContinueResult Continue(int input=-1);
    ContinueResult ChooseCard(int input);
    ContinueResult ExecuteCard();    
};
#endif /* SCHEME_USECASE */
