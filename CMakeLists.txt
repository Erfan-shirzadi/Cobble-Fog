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
    src/Domain/Entities/Heroes/InvisibleMan.cpp
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


    src/Domain/Entities/Cards/InvisibleMan/CodedNotes.cpp
    src/Domain/Entities/Cards/InvisibleMan/DreamingOfRevenge.cpp
    src/Domain/Entities/Cards/InvisibleMan/EmergeFromMist.cpp
    src/Domain/Entities/Cards/InvisibleMan/ImpossibleToSee.cpp
    src/Domain/Entities/Cards/InvisibleMan/IntoThinAir.cpp
    src/Domain/Entities/Cards/InvisibleMan/Lurking.cpp
    src/Domain/Entities/Cards/InvisibleMan/ReignOfTerror.cpp
    src/Domain/Entities/Cards/InvisibleMan/RollingFog.cpp
    src/Domain/Entities/Cards/InvisibleMan/SlipAway.cpp
    src/Domain/Entities/Cards/InvisibleMan/StepLightly.cpp




    src/Application/UseCases/ManeverUseCase.cpp
    src/Application/UseCases/DrawingCardUseCase.cpp
    src/Application/UseCases/DiscardingCardUseCase.cpp
    src/Application/UseCases/PlaceMentUseCase.cpp
    src/Application/UseCases/CombatUseCase.cpp
    src/Application/UseCases/SetUpGameUseCase.cpp
    src/Application/UseCases/TurnUseCase.cpp
    src/Application/UseCases/SchemeUseCase.cpp
    src/Application/UseCases/AttackUseCase.cpp
    src/Application/UseCases/MoveUseCase.cpp
    src/Domain/Game/GameEngine.cpp
    src/Domain/Entities/Board.cpp


    src/Application/CardEffect/CardEffectFactory.cpp

    src/Application/CardEffect/DraculaCardsEffect/FeedingFrenzyEffect.cpp
    src/Application/CardEffect/DraculaCardsEffect/MistFormEffect.cpp
    src/Application/CardEffect/DraculaCardsEffect/AmbushEffect.cpp
    src/Application/CardEffect/DraculaCardsEffect/BapismOfBloodEffect.cpp
    src/Application/CardEffect/FeintEffect.cpp
    src/Application/CardEffect/DraculaCardsEffect/RaveningSeductionEffect.cpp
    src/Application/CardEffect/DraculaCardsEffect/PreyUpon.cpp
    src/Application/CardEffect/DraculaCardsEffect/LookIntoMyEyesEffect.cpp
    src/Application/CardEffect/DraculaCardsEffect/BeastFormEffect.cpp
    src/Application/CardEffect/DraculaCardsEffect/ExploitEffect.cpp
    src/Application/CardEffect/Move3Effect.cpp
    src/Application/CardEffect/DraculaCardsEffect/ThirstEffect.cpp

    src/Application/CardEffect/HolmesCardsEffect/AdministerAidEffect.cpp
    src/Application/CardEffect/HolmesCardsEffect/CounterPunchEffect.cpp
    src/Application/CardEffect/HolmesCardsEffect/DeduceStrategyEffect.cpp
    src/Application/CardEffect/HolmesCardsEffect/EliminateTheImpossibleEffect.cpp
    src/Application/CardEffect/HolmesCardsEffect/FixedAPointInChangingAgeEffect.cpp
    src/Application/CardEffect/HolmesCardsEffect/MasterOfDisguse.cpp
    src/Application/CardEffect/HolmesCardsEffect/EducationNeverEndsEffect.cpp
    src/Application/CardEffect/HolmesCardsEffect/StudyMethodEffect.cpp
    src/Application/CardEffect/NoneEffect.cpp

    src/Application/CardEffect/InvisibleManEffect/CodedNotesEffect.cpp
    src/Application/CardEffect/InvisibleManEffect/DreamingOfRevengeEffect.cpp
    src/Application/CardEffect/InvisibleManEffect/ImpossibleToSeeEffect.cpp
    src/Application/CardEffect/InvisibleManEffect/IntoThinAirEffect.cpp
    src/Application/CardEffect/InvisibleManEffect/ReignOfTerrorEffect.cpp
    src/Application/CardEffect/InvisibleManEffect/LurkingEffect.cpp
    src/Application/CardEffect/InvisibleManEffect/RollingFogEffect.cpp
    src/Application/CardEffect/InvisibleManEffect/SlipAwayEffect.cpp



    src/Application/Ability/DraculaAbility.cpp


    src/presentation/console/GameView.cpp
    src/presentation/console/MainMenu.cpp
    src/presentation/console/SetUpView.cpp
    src/Domain/Game/GameLog.cpp

)
find_package(raylib REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    raylib
)