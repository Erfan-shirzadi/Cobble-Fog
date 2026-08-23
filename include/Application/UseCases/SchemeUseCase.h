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
    bool CanDoAction(GameState * gamestate);


    ContinueResult Continue(EffectContext&)override;

    ContinueResult ChooseCard(EffectContext&);
    ContinueResult ExecuteCard(EffectContext&); 
    ContinueResult Finished(EffectContext &);  
    MenuRequest BuildCardMenu(EffectContext&); 
    void Start(EffectContext& );

    SchemeStep GetStep();
    int GetEffectStep();
    Card* GetSelectedCard();
    void SetStep(SchemeStep);
    void SetSelectedCard(Card*);
    void SetCardEffect(std::unique_ptr<CardEffect>,int effectStep);
    

};
#endif /* SCHEME_USECASE */
