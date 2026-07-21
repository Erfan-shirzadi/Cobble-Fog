#ifndef F46906F6_7378_4E36_AD20_7FD7040075DD
#define F46906F6_7378_4E36_AD20_7FD7040075DD
#include "Domain/Game/GameState.h"
#include "Domain/Game/GameLog.h"

class MoveUseCase{
    public :
    static void Move(Fighter*,int node,GameLog&);
};

#endif /* F46906F6_7378_4E36_AD20_7FD7040075DD */
