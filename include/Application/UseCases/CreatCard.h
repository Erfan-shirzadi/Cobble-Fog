#ifndef CREAT_CARD
#define CREAT_CARD
#include <memory>
#include "Domain/Entities/Card.h"
class CreatCard{

    public:
    static std::unique_ptr<Card> CreatCardid(CardId);
};

#endif /* CREAT_CARD */
