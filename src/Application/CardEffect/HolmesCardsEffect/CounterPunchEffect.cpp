#include "Application/CardEffect/HolmesCardsEffect/CounterPunchEffect.h"
#include "Application/interaction/EffectContext.h"

ContinueResult CounterPunchEffect::Continue(EffectContext & context){
        Fighter* fighter=context.combatcontext->Opponent->fighter;
        Hero * holmes=context.combatcontext->Current->hero;
        Board borad=context.context.Gamestate->board;
        
        if(borad.AreAdjacent(fighter->GetNode(),holmes->GetNode())){
            if(!(borad.GetNodeType(fighter->GetNode())==NodeType::SECREST &&borad.GetNodeType(holmes->GetNode())==NodeType::SECREST)){
                fighter->TakeDamge(2);
                context.context.Gamestate->log.Add(fighter->GetName()+" Toke 2 Damage");
            }
        }
        ContinueResult res;
         res.status=ContinueStatus::FINISHED;
         return res;
         
}
