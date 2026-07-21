#include "Application/UseCases/MoveUseCase.h"
void MoveUseCase::Move(Fighter* fighter,int node,GameLog& log){
    log.Add("moved "+fighter->GetName()+ " to "+std::to_string(node));
    fighter->SetNode(node);
}
