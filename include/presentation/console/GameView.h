#ifndef GAME_VIEW
#define GAME_VIEW

#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/event.hpp>
#include <ftxui/dom/flexbox_config.hpp>
#include <vector>
#include "Application/interaction/MenuRequest.h"


struct GameState;

class GameView{

    GameState & gamestate;
    public:
    GameView(GameState & );
    // void run(GameState & state);
    // void Close();
    // int ShowMenu(std::vector<std::string>);
    void SetMenu(const MenuRequest &);
    ftxui::Element render();
    ftxui::Element renderMenu();
    void SetOnSelection(std::function<void(int)>callback);
    void Run();

    ftxui::Element Refresh();
    ftxui::Element RenderPlayer(Player* player);
    ftxui::Element RenderLog();


    private:
    ftxui::ScreenInteractive screen=ftxui::ScreenInteractive::TerminalOutput();
    std::vector<std::string> menuOptions;
    // bool CatchEvent(ftxui::Event event);
    int selected=0;
    ftxui::Component menu;
    ftxui::Component root;
    ftxui::Component container=ftxui::Container::Vertical({});

    std::function<void(int)>Onselection;

};

#endif /* GAME_VIEW */
