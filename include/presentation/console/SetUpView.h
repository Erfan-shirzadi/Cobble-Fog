#ifndef SETUP_VIEW
#define SETUP_VIEW
#include <string>
#include <raylib.h>
#include <functional>
#include "Application/interaction/MenuRequest.h"

struct GameState;

enum class SetUpState{
    INPUT_AGE,
    SHOW_STARTING_PLAYER,
    HERO_SELECTION,
    PLACEMENT,
};

class SetUpView{

    GameState & gamestate;
    SetUpState state=SetUpState::INPUT_AGE;
    MenuRequest * menurequest;

    std::string player1Age;
    bool editingPlayer1=true;
    std::string player2Age;
    bool editingPlayer2=true;
    int firstPlayer=-1;
    int HeroSelected=-1;

    Rectangle mapRect{450,70,900,600};
    Rectangle player1box{650,240,120,50};
    Rectangle player2box{650,340,120,50};
    Rectangle continueButton{520,500,220,60};
    Rectangle AdvanceToHeroSelectionButton{430,520,420,60};
    Rectangle heroRects[2]{{390,180,256,356},{710,180,256,356}};
    Texture2D herotextures[2];
    Texture2D boardtexture;
    std::vector<bool> selectedHeroes={false,false};
    std::vector<Vector2> nodeCenters;

    std::function<void(int)>onSelection;

    public:
    SetUpView(GameState& );
    void SetInputRequest(MenuRequest & req);

    void Update();
    void Draw();
    
    
    void UpdateInPutAge();
    void UpdateStartingPlayer();
    void UpdateHeroSelection();
    void UpdateHeroPlacement();
    void UpdateSidekickPlacement();
    

    
    
    void DrawInputAge();
    void DrawStartingPlayer();
    void DrawHeroSelection();
    void DrawHeroPlacement();
    void DrawSidekickPlacement();
    void DrawBoard();


    void LoadTextures();


    void SetOnSelection(std::function<void(int)>callback);



    std::vector<Vector2> GetNodeCenters();

};

#endif /* SETUP_VIEW */
