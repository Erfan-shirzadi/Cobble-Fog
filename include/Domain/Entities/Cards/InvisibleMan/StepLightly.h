#ifndef STEPLIGHTLY
#define STEPLIGHTLY


#include "Domain/Entities/SchemeCard.h"
class StepLightly: public SchemeCard{

    public:
    StepLightly();
        FighterType GetOwner()const override;


};


#endif /* STEP_LIGHTLY */
