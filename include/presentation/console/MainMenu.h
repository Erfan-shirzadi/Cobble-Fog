#ifndef MAIN_MENU
#define MAIN_MENU
#include <vector>
#include <string>
#include "presentation/console/MenuButton.h"

enum class MenuResult{
    NONE,
    START,
    LOAD,
    EXIT
};

class MainMenu{

    std::vector <MenuBotton> buttons;
    MenuResult result=MenuResult::NONE;
    int selected=0;
    
    public :
    MainMenu();
    void Update();
    void Draw();

    MenuResult GetResult();  
    void ResetResult();

};

#endif /* MAIN_MENU */
