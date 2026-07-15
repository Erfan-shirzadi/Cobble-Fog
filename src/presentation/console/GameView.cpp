#include "Domain/Game/GameState.h"
#include "presentation/console/GameView.h"


#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

using namespace ftxui;

 void GameView::run(GameState & state){
    
    auto renderer= Renderer([&] {
        
        return vbox({
            text("Cobble & Fog"),
            vbox({
                text("Turn"),
                separator(),
                text("Ditale"),
                separator(),
                text("Logs"),
                separator(),
                text("Menu"),

            })
        });
        
    });
    screen.Loop(renderer);
 }


// int GameView::chooseCard(std::vector<Card*> card){
//     std::vector <std::string> cards;
//     for(auto c:card){
//         cards.push_back(c->GetName());
//     }

//     int selected=0;
//     auto menu=Menu(&cards,&selected);

//     auto renderer=Renderer(menu, [&]{
//         return vbox({
//             text("Choose Card"),
//             separator(),
//             menu->Render(),
//         });
//     });

//     auto component=CatchEvent(renderer, [&](Event event){
//         if(event==Event::Return){
//             screen.ExitLoopClosure()();
//             return true;
//         }
//         return false;
//     });

//     screen.Loop(component);
//     return selected;
// }

void GameView::Close(){
    this->screen.ExitLoopClosure();
}

int GameView::ShowMenu(std::vector<std::string> a){
    int selected=0;
    auto menu =Menu(&a,&selected);

    this->screen.Loop(menu);

    return selected;
}
