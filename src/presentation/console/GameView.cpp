#include "Domain/Game/GameState.h"
#include "presentation/console/GameView.h"


#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

using namespace ftxui;

//  void GameView::run(GameState & state){
    
//     auto renderer= Renderer([&] {
        
//         return vbox({
//             text("Cobble & Fog"),
//             vbox({
//                 text("Turn"),
//                 separator(),
//                 text("Ditale"),
//                 separator(),
//                 text("Logs"),
//                 separator(),
//                 text("Menu"),

//             })
//         });
        
//     });
//     screen.Loop(renderer);
//  }


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

// void GameView::Close(){
//     this->screen.ExitLoopClosure();
// }

// void GameView::ShowMenu(std::vector<std::string> a){
//     int selected=0;
//     auto menu =Menu(&a,&selected);

//     this->screen.Loop(menu);

//     return selected;
// }

GameView::GameView(GameState & gamestate):gamestate(gamestate){
    
    root =CatchEvent(Renderer(container,[&]{
        return Refresh();
    }),
        [&](Event event){
            if(event==Event::Return){
                Onselection(selected);
                return true;
            }
            return false;
        }
    );
}

ftxui::Element GameView::render(){
    return renderMenu();
    
}
ftxui::Element GameView::renderMenu(){

    return vbox({
        text("Menu"),
        separator(),
        menu ? menu->Render():text("Loding ....")
    })|border;
}

void GameView::SetMenu(const MenuRequest & menu){
    this->menuOptions=menu.options;
    this->menu=Menu(&menuOptions, &selected);
    container->DetachAllChildren();
     container->Add(this->menu);
    this->menu->TakeFocus();
}

void GameView::SetOnSelection(std::function<void(int)>callback){
    Onselection=std::move(callback);
}

void GameView::Run(){
    screen.Loop(root);
}



Element GameView::Refresh(){
    return vbox({
        vbox({
            text("Turn : ...")|center,
        hbox({
        RenderPlayer(gamestate.player1)|border|size(WIDTH,EQUAL,30)|flex,
        RenderLog()|border|size(WIDTH,EQUAL,40)|flex,
        RenderPlayer(gamestate.player2)|border|size(WIDTH,EQUAL,30)|flex,
        })
        })|border,
        renderMenu()
});
}


ftxui::Element GameView::RenderPlayer(Player* player){
        auto hero=player->GetHero();
    std::vector<Element>elements;
    if(hero){
    elements.push_back(text(hero->GetName()));
    elements.push_back(separator());
    elements.push_back(text("HP : "+std::to_string(hero->GetHP())));
    elements.push_back(text("Action : "+std::to_string(hero->GetRemainingAction())));
    elements.push_back(separator());
    elements.push_back(text("Hand :"));
    elements.push_back(separator());
    if(hero==gamestate.currnetPlayer->GetHero())
        elements.push_back(vbox({text(hero->GetHandCards())}));
    elements.push_back(separator());
   
    for(auto fighter:hero->GetSideKicks()){
        elements.push_back(text(fighter->GetName()+"  HP : "+
        std::to_string(fighter->GetHP())+"  ("+
        std::to_string(fighter->GetNode())+")"));
    }
    elements.push_back(separator());
    elements.push_back(text("Hand Size :"+std::to_string(hero->GetSizeHand())));
    elements.push_back(text("Deck Size :"+std::to_string(hero->GetDeckSize())));
    }
    else{
    elements.push_back(text("...."));
    elements.push_back(separator());
    elements.push_back(text("HP : ....."));
    elements.push_back(separator());
    elements.push_back(text("Hand :"));
    elements.push_back(separator());
    elements.push_back(vbox({text(".....")}));
    elements.push_back(separator());
   
    elements.push_back(text("Side Kikcs Loading ......"));
    elements.push_back(separator());
    elements.push_back(text("Hand Size :...."));
    elements.push_back(text("Deck Size : ....."));

    }


    return vbox(elements);
    
}

ftxui::Element GameView::RenderLog(){

    std::vector<Element> elements;
    for(auto log : gamestate.log.GetLogs()){
        elements.push_back(text(log));
    }
    elements.push_back(text("salam"));
    elements.push_back(text("herlo"));
    elements.push_back(text("Fuck you"));
    return vbox(elements);
}
