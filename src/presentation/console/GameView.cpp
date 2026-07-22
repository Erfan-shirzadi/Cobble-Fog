#include "Domain/Game/GameState.h"
#include "presentation/console/GameView.h"


#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

using namespace ftxui;


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
        text(this->menurequest.title)|center,
        separator(),
        menu ? menu->Render():text("Loding ....")
    })|border;
}

void GameView::SetMenu(const MenuRequest & menu){
    this->menuOptions=menu.options;
    this->menurequest=menu;
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
        RenderTurnBar()|center,
        hbox({
        RenderPlayer(gamestate.player1)|border|flex,
        RenderLog()|border|flex,
        RenderPlayer(gamestate.player2)|border|flex,
        })|flex,
        RenderMap()|border
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
        elements.push_back(text(log)|center);
    }
    
    return vbox(elements);
}

ftxui::Element GameView::RenderMap(){
    std::vector<Element>elements;
    Board board=gamestate.board;
    if(gamestate.opponentPlayre)
        return vbox(text(board.GetGraph()));
    
    return vbox(text("Loading map ....."));
}


ftxui::Element GameView::RenderTurnBar(){

    Hero * hero=gamestate.currnetPlayer->GetHero();
    
    if(hero){
        return text("Turn : "+hero->GetName());
    }
    else return text("Set Up");
}
