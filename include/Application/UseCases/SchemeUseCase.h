#ifndef SCHEME_USECASE
#define SCHEME_USECASE
#include "Domain/Game/GameState.h"
#include "Application/interaction/ContinueResult.h"
#include "presentation/console/GameView.h"
#include "Application/interaction/ActionContext.h"
#include "Application/UseCases/IUseCase.h"
enum class SchemeStep{
    CHOOSECARD,
    EXECUTECARD,
    FINISHED
};
class SchemeUseCase : public IUseCase{

    SchemeStep step=SchemeStep::CHOOSECARD;
    Card * SelectedCard=nullptr;

    std::unique_ptr<CardEffect> cardEffect=nullptr;
    
    public:
    // explicit SchemeUseCase(GameState &);
    bool execute(GameState & gamestate);
    bool CanDoAction(GameState & gamestate);
    Card * CardSelection(Hero * hero);


    ContinueResult Continue(EffectContext&)override;

    // ContinueResult Continue(int input=-1);
    ContinueResult ChooseCard(EffectContext&);
    ContinueResult ExecuteCard(EffectContext&); 
    ContinueResult Finished(EffectContext &);  
    MenuRequest BuildCardMenu(EffectContext&); 
    void Start(EffectContext& );
};
#endif /* SCHEME_USECASE */
