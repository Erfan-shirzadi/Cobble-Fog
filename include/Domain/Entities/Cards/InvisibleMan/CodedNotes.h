#ifndef CODED_NOTES
#define CODED_NOTES

#include "Domain/Entities/CombatCard.h"

class CodedNotes : public CombatCard{

    public:
    CodedNotes();
     PlayTiming GetCardPlayTiming()const override;
     FighterType GetOwner()const override;



};



#endif /* CODED_NOTES */
