#ifndef SETUPGAME_USECASE
#define SETUPGAME_USECASE
#include "Domain/Game/GameState.h"
#include "Application/interaction/ContinueResult.h"
#include "Application/interaction/EffectContext.h"


enum class SetUpGameStep{
    CHOOSE_HERO,
    DRAW_5CARD,
    PLACEMENT,
};

enum class PlaceMentStep{
    SET_HERO,
    SET_SIDEKICKS,
    FINISHED,
};
class SetUpGameUseCase{

    SetUpGameStep step=SetUpGameStep::CHOOSE_HERO;
    PlaceMentStep placementstep=PlaceMentStep::SET_HERO;

    std::vector<int> ReachbleHeroesNodes{1,26};
    std::vector<std::string> Heroes{"Dracula","Holmes"};

    std::vector<int> ReachbleSidekickNods;

    std::vector<Fighter*>sidekicks;
    int index_sideKick=0;
    public:
    void execute(GameState & gamestate);
    std::unique_ptr<Hero> CreateHero(int choice);
    void ShuffelDecks(Hero *);
    void DrawInitialCards(Hero *);

    ContinueResult ChooseHero(EffectContext &);
    ContinueResult Continue(EffectContext &);
    ContinueResult PlaceMent(EffectContext &);
    
    ContinueResult HeroPlaceMent(EffectContext &);
    ContinueResult SideKickPlaceMent(EffectContext &);

    ContinueResult SetRechbleSideKickNodes(EffectContext&);

    ContinueResult Finished(EffectContext & );
};

#endif /* SETUP_USECASE */
