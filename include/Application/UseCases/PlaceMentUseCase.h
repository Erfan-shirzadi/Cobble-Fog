#ifndef PLACEMENT_USECASE
#define PLACEMENT_USECASE
#include "Domain/Game/GameState.h"

class PlaceMentUseCase{

    public:
    void PlaceHero(GameState & );
    void PlaceSideKicks(GameState &);
    bool finished()const;
};

#endif /* PLACEMENT_USECASE */
