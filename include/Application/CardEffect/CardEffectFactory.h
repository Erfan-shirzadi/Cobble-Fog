#ifndef CARD_EFFECTFACTORY
#define CARD_EFFECTFACTORY
#include <memory>
#include "Application/CardEffect/CardEffect.h"
#include "Domain/Entities/Cards/CardId.h"

class CardEffectFactory{

    public :
    static CardEffect CreatCardEffect(CardId);
};

#endif /* CARD_EFFECTFACTORY */
