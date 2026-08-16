#ifndef DATA_CONTEXT
#define DATA_CONTEXT
#include "Domain/Game/GameState.h"
#include "presentation/console/GameView.h"
#include "Application/UseCases/TurnUseCase.h"
#include "Application/interaction/ActionContext.h"


struct DataContext{

    // GameState gamestate;
    ViewState gameviewstate;
    EffectContext context;
    // TurnUseCase * TURNUSECASE;

};
#endif /* DATA_CONTEXT */
