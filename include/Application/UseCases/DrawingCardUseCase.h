#ifndef DRAWINGCARD_USECASE
#define DRAWINGCARD_USECASE
#include "Domain/Entities/Hero.h"

class GameLog;
class DrawingCardUseCase{

    public :
    static void DrawCard(Hero *,GameLog&);
};


#endif /* DRAWINGCARD_USECASE */
