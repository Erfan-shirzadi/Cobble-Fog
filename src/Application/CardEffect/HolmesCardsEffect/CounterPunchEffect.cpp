#include "Application/CardEffect/HolmesCardsEffect/CounterPunchEffect.h"

ContinueResult CounterPunchEffect::Continue(EffectContext & context){
        Fighter* fighter=context.combatcontext->Opponent->fighter;
        Hero * holmes=context.combatcontext->Current->hero;
        Board borad=context.context.Gamestate->board;
        
        if(borad.AreAdjacent(fighter->GetNode(),holmes->GetNode())){
            fighter->TakeDamge(2);
        }
        ContinueResult res;
         res.status=ContinueStatus::FINISHED;
         return res;
         
}
