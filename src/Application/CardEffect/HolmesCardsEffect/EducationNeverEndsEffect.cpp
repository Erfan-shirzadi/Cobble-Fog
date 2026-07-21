#include "Application/CardEffect/HolmesCardsEffect/EducationNeverEndsEffect.h"
#include "Application/interaction/EffectContext.h"
#include "Application/UseCases/DrawingCardUseCase.h"

ContinueResult EducationNeverEndsEffect::Continue(EffectContext & context){
    if(context.combatcontext->Current->Won){
        Hero * hero=context.combatcontext->Opponent->hero;
        DrawingCardUseCase::DrawCard(hero,context.context.Gamestate->log);
    }
    else{
        Hero * Holmes =context.combatcontext->Current->hero;
        DrawingCardUseCase::DrawCard(Holmes,context.context.Gamestate->log);
        DrawingCardUseCase::DrawCard(Holmes,context.context.Gamestate->log);

    }

    ContinueResult res;
     res.status=ContinueStatus::FINISHED;
     return res;
    
}
