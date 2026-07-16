#ifndef ADMINISTERAID_H
#define ADMINISTERAID_H
#include "Domain/Entities/SchemeCard.h"
#include "Application/interaction/ContinueResult.h"
#include "Application/interaction/ActionContext.h"

class AdministerAid: public SchemeCard{

    int step=0;
    std::vector<int> RechableNodes;
    public:
    AdministerAid();
        void Play(Hero * ,Hero * , Board *) override;
        FighterType GetOwner()const override;
        // ContinueResult Continue(ActionContext& );
        ContinueResult RequestNodeSelection(ActionContext&);
        ContinueResult MoveWatson(ActionContext &);
        ContinueResult HealHolmes(ActionContext &);
        ContinueResult DrawCard(ActionContext &);
        ContinueResult Continue(ActionContext&);


};

#endif /* ADMINISTERAID_H */
