#ifndef BEAST_FORM_EFFECT
#define BEAST_FORM_EFFECT
#include "Application/CardEffect/CardEffect.h"

enum class BeastFormStep{
    ASK_FOR_DISCADINGCARD,
    CHOOSE_CARD,
};
class BeastFormEffect :public CardEffect{

    BeastFormStep step=BeastFormStep::ASK_FOR_DISCADINGCARD;
    public: 
    ContinueResult Continue(EffectContext &);

    ContinueResult AskForDiscardinCard(EffectContext & );
    ContinueResult ChooseCard(EffectContext &);

    ContinueResult BuildCardMenu(EffectContext &);
    
};

#endif /* BEAST_FORM_EFFECT */
