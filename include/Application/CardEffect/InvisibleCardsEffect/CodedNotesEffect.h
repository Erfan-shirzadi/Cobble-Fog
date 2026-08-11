#ifndef CODED_NOTES_EFFECT
#define CODED_NOTES_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"

class CodedNotesEffect: public CardEffect{

    public:
    ContinueResult Continue(EffectContext & );
};


#endif /* CODED_NOTES_EFFECT */
