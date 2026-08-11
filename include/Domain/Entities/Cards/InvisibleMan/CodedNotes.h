#ifndef CODEDNOTES
#define CODEDNOTES

#include "Domain/Entities/CombatCard.h"

class CodedNotes : public CombatCard{

    public:
    CodedNotes();
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;



};



#endif /* CODED_NOTES */
