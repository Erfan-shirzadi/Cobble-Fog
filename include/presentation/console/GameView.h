#ifndef GAME_VIEW
#define GAME_VIEW

#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/dom/flexbox_config.hpp>
#include <vector>


struct GameState;

class GameView{

    public:

    void run(GameState & state);
    void Close();
    int ShowMenu(std::vector<std::string>);

    private:
    ftxui::Element render(const GameState & state);
    ftxui::ScreenInteractive screen=ftxui::ScreenInteractive::TerminalOutput();

};

#endif /* GAME_VIEW */
