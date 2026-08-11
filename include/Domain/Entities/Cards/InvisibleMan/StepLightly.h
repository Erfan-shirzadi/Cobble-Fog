#ifndef STEP_LIGHTLY
#define STEP_LIGHTLY


#include "Domain/Entities/SchemeCard.h"
class StepLightly: public SchemeCard{

    public:
    StepLightly();
        FighterType GetOwner()const override;


};


#endif /* STEP_LIGHTLY */
