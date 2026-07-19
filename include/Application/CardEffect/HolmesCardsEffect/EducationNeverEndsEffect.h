#ifndef EDUCATION_NEVER_ENDS_EFFECT
#define EDUCATION_NEVER_ENDS_EFFECT
#include "Application/CardEffect/CardEffect.h"

class EducationNeverEndsEffect :public CardEffect{

    public : 
    ContinueResult Continue(EffectContext &);
};

#endif /* EDUCATION_NEVER_ENDS_EFFECT */
