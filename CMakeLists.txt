cmake_minimum_required(VERSION 3.20)
project(
    unmatched  
    LANGUAGES CXX
)


set(
    SOURCES
    
    ./main.cpp
    src/Domain/Entiteis/Fighter.cpp
    src/Domain/Entities/Hero.cpp
    src/Domain/Entities/Graph.cpp
    src/Domain/Entities/Card.cpp
    src/Domain/Entities/Heroes/Dracula.cpp
    src/Domain/Entities/Heroes/SherlockHolmes.cpp

    src/Application/UseCases/ManeverUseCase.cpp
    src/Application/UseCases/DrawingCardUseCase.cpp
    src/Application/UseCases/DiscardingCardUseCase.cpp

)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)