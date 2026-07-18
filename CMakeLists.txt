cmake_minimum_required(VERSION 3.20)
project(
    unmatched  
    LANGUAGES CXX
)


set(
    SOURCES
    
    ./main.cpp
    src/Domain/Entities/Fighter.cpp
    src/Domain/Entities/Hero.cpp
    src/Domain/Entities/Graph.cpp
    src/Domain/Entities/Card.cpp
    src/Domain/Entities/CombatCard.cpp
    src/Domain/Entities/Heroes/Dracula.cpp
    src/Domain/Entities/Heroes/Holmes.cpp
    src/Domain/Player.cpp
    src/Domain/Entities/Deck.cpp


    src/Domain/Entities/Cards/Dracula/FeedingFrenzy.cpp
    src/Domain/Entities/Cards/Dracula/Ambush.cpp
    src/Domain/Entities/Cards/Dracula/BeastForm.cpp
    src/Domain/Entities/Cards/Dracula/Dash.cpp
    src/Domain/Entities/Cards/Dracula/LookIntoMyEyes.cpp
    src/Domain/Entities/Cards/Dracula/Feint.cpp
    src/Domain/Entities/Cards/Dracula/ThirstForSustenance.cpp
    src/Domain/Entities/Cards/Dracula/Exploit.cpp
    src/Domain/Entities/Cards/Dracula/PreyUpon.cpp
    src/Domain/Entities/Cards/Dracula/MistForm.cpp
    src/Domain/Entities/Cards/Dracula/BapismOfBlood.cpp
    src/Domain/Entities/Cards/Dracula/RaveningSeduction.cpp

    src/Domain/Entities/Cards/Holmes/CounterPunch.cpp
    src/Domain/Entities/Cards/Holmes/DeduceStrategy.cpp
    src/Domain/Entities/Cards/Holmes/EducationNeverEnds.cpp
    src/Domain/Entities/Cards/Holmes/TheGameIsAfoot.cpp
    src/Domain/Entities/Cards/Holmes/StudyMethods.cpp
    src/Domain/Entities/Cards/Holmes/ServiceRevolver.cpp
    src/Domain/Entities/Cards/Holmes/FixedPointInAChangingAge.cpp
    src/Domain/Entities/Cards/Holmes/EliminateTheImpossible.cpp
    src/Domain/Entities/Cards/Holmes/MasterOfDisguise.cpp
    src/Domain/Entities/Cards/Holmes/AdministerAid.cpp

    src/Application/UseCases/ManeverUseCase.cpp
    src/Application/UseCases/DrawingCardUseCase.cpp
    src/Application/UseCases/DiscardingCardUseCase.cpp
    src/Application/UseCases/PlaceMentUseCase.cpp
    src/Application/UseCases/CombatUseCase.cpp
    src/Application/UseCases/SetUpGameUseCase.cpp
    src/Application/UseCases/TurnUseCase.cpp
    src/Application/UseCases/SchemeUseCase.cpp
    src/Application/UseCases/AttackUseCase.cpp
    src/Domain/Game/GameEngine.cpp
    src/Domain/Entities/Board.cpp


    src/Application/CardEffect/CardEffectFactory.cpp
    src/Application/CardEffect/DraculaCardsEffect/FeedingFrenzyEffect.cpp
    src/Application/CardEffect/DraculaCardsEffect/MistFormEffect.cpp
    src/Application/CardEffect/DraculaCardsEffect/AmbushEffect.cpp

    src/presentation/console/GameView.cpp

)
find_package(ftxui REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    ftxui::screen
    ftxui::dom
    ftxui::component
)