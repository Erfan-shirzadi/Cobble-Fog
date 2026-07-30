#ifndef SETUP_VIEW
#define SETUP_VIEW
#include <string>
#include <raylib.h>

enum class SetUpState{
    INPUT_AGE,
    SHOW_STARTING_PLAYER,
    HERO_SELECTION
};

class SetUpView{
    SetUpState state=SetUpState::INPUT_AGE;

    std::string player1Age;
    bool editingPlayer1=true;
    std::string player2Age;
    bool editingPlayer2=true;
    int firstPlayer=-1;
    int HeroSelected=-1;

    Rectangle player1box{650,240,120,50};
    Rectangle player2box{650,340,120,50};
    Rectangle continueButton{520,500,220,60};
    Rectangle AdvanceToHeroSelectionButton{430,520,420,60};
    Rectangle heroRects[2]{{390,180,256,356},{710,180,256,356}};
    Texture2D herotextures[2];

    public:
    void Update();
    void Draw();
    void UpdateInPutAge();
    void UpdateStartingPlayer();
    void UpdateHeroSelection();
    void DrawInputAge();
    void DrawStartingPlayer();
    void DrawHeroSelection();


    void LoadTextures();


};

#endif /* SETUP_VIEW */
