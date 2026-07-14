#ifndef SCHEME_USECASE
#define SCHEME_USECASE
#include "Domain/Game/GameState.h"
#include "Application/interaction/ContinueResult.h"

enum class Step{
    CHOOSECARD,
    EXECUTECARD,
    FINISHED
};
class SchemeUseCase{

    Step step;
    GameState gamestate;
    Card * card=nullptr;
    public:
    explicit SchemeUseCase(GameState &);
    bool execute(GameState & gamestate);
    bool CanDoAction(GameState & gamestate);
    Card * CardSelection(Hero * hero);



    ContinueResult Continue(int input=-1);
    ContinueResult ChooseCard(int input);
    
};
#endif /* SCHEME_USECASE */
