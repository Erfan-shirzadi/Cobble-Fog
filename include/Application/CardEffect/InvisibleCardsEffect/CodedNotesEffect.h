#ifndef CODED_NOTES_EFFECT
#define CODED_NOTES_EFFECT
#include "Application/CardEffect/CardEffect.h"
#include "Application/interaction/EffectContext.h"

enum class CodedStep{
    DRAW3_CARD,
    REUTRN_CARD_TO_DECK
};
class CodedNotesEffect: public CardEffect{

    CodedStep step=CodedStep::DRAW3_CARD;
    int countofCardReturned=0;
    int countofCardDrawed=0;
    public:
    ContinueResult Continue(EffectContext & );
    ContinueResult Draw3Card(EffectContext &);
    ContinueResult ReturnToDeckCard(EffectContext &);
};


#endif /* CODED_NOTES_EFFECT */
