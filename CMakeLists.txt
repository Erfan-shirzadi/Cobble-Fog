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


    src/Domain/Entities/Cards/Dracula/FeedingFrenzy.cpp
    src/Domain/Entities/Cards/Dracula/Ambush.cpp
    src/Domain/Entities/Cards/Dracula/BeastForm.cpp
    src/Domain/Entities/Cards/Dracula/Dash.cpp
    src/Domain/Entities/Cards/Dracula/LookIntoMyEyes.cpp

    src/Application/UseCases/ManeverUseCase.cpp
    src/Application/UseCases/DrawingCardUseCase.cpp
    src/Application/UseCases/DiscardingCardUseCase.cpp
    src/Application/UseCases/PlaceMentUseCase.cpp
    src/Application/UseCases/CombatUseCase.cpp
    src/Domain/Entities/Board.cpp

)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)