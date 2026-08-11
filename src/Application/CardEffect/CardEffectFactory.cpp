#include "Application/CardEffect/CardEffectFactory.h"
#include "Application/CardEffect/DraculaCardsEffect/AmbushEffect.h"
#include "Application/CardEffect/DraculaCardsEffect/BapismOfBloodEffect.h"
#include "Application/CardEffect/DraculaCardsEffect/BeastFormEffect.h"
#include "Application/CardEffect/DraculaCardsEffect/ExpliotEffect.h"
#include "Application/CardEffect/DraculaCardsEffect/FeedingFrenzyEffect.h"
#include "Application/CardEffect/DraculaCardsEffect/LookIntoMyEyesEffect.h"
#include "Application/CardEffect/DraculaCardsEffect/MistFormEffect.h"
#include "Application/CardEffect/DraculaCardsEffect/PreyUponEffect.h"
#include "Application/CardEffect/DraculaCardsEffect/RaveningSeductoinEffect.h"
#include "Application/CardEffect/DraculaCardsEffect/ThirstEffect.h"
#include "Application/CardEffect/Move3Effect.h"
#include "Application/CardEffect/FeintEffect.h"
#include "Application/CardEffect/HolmesCardsEffect/AdministerAidEffect.h"
#include "Application/CardEffect/HolmesCardsEffect/CounterPunchEffect.h"
#include "Application/CardEffect/HolmesCardsEffect/DeduceStrategyEffect.h"
#include "Application/CardEffect/HolmesCardsEffect/EliminateTheImpossible.h"
#include "Application/CardEffect/HolmesCardsEffect/FixedAPointInChangingAgeEffect.h"
#include "Application/CardEffect/HolmesCardsEffect/MasterOfDeisguseEffect.h"
#include "Application/CardEffect/HolmesCardsEffect/EducationNeverEndsEffect.h"
#include "Application/CardEffect/NoneEffect.h"
#include "Application/CardEffect/HolmesCardsEffect/StudyMethod.h"
#include "Application/CardEffect/InvisibleCardsEffect/CodedNotesEffect.h"
#include "Application/CardEffect/InvisibleCardsEffect/DreamingOfRevengeEffect.h"
#include "Application/CardEffect/InvisibleCardsEffect/ImpossibleToSeeEffect.h"
#include "Application/CardEffect/InvisibleCardsEffect/IntoThinAirEffect.h"
#include "Application/CardEffect/InvisibleCardsEffect/ReignOfTerorrEffect.h"

std::unique_ptr<CardEffect> CardEffectFactory::CreatCardEffect(CardId id){
    
    switch (id)
    {
    case CardId::AMBUSH:
        return std::move(std::make_unique<AmbushEffect>());
        break;
    case CardId::BAPISM_OF_BLOOD:
        return std::move(std::make_unique<BapismOfBloodEffect>());
        break;
    case CardId::BEASTFORM:
        return std::move(std::make_unique<BeastFormEffect>());
        break;
    case CardId::DASH:
        return std::move(std::make_unique<Move3Effect>());
        break;
    case CardId::EXPLOIT:
        return std::move(std::make_unique<ExpliotEffect>());
        break;
    case CardId::FEEDINGFRENZY:
        return std::move(std::make_unique<FeedingFrenzyEffect>());
        break;
    case CardId::FEINT:
        return std::move(std::make_unique<FeintEffect>());
        break;
    case CardId::LOOK_INTO_MY_EYES:
        return std::move(std::make_unique<LookIntoMyEyesEffect>());
        break;
    case CardId::MISTFORM:
        return std::move(std::make_unique<MistFormEffect>());
        break;
    case CardId::PERYUPON:
        return std::move(std::make_unique<PreyUponEffect>());
        break;
    case CardId::RAVENING_SEDUCTION:
        return std::move(std::make_unique<RaveningSeductionEffect>());
        break;
    case CardId::THIRST_FOR_SUSTENANCE:
        return std::make_unique<ThirstEffect>();
        break;
    case CardId::ADMINISTER_AID:
        return std::move(std::make_unique<AdministerAidEffect>());
        break;
    case CardId::COUNTER_PUNCH:
        return std::move(std::make_unique<CounterPunchEffect>());
        break;
    case CardId::DEDUCE_STRATEGY:
        return std::move(std::make_unique<DeduceStrategyEffect>());
        break;
    case CardId::EDUCATION_NEVER_ENDS:
        return std::move(std::make_unique<EducationNeverEndsEffect>());
        break;
    case CardId::ELIMINATE_THE_IMPOSSIBLE:
        return std::move(std::make_unique<EliminateTheImpossibleEffect>());
        break;
    case CardId::FIXED_POINT_IN_A_CHANGING_AGE:
        return std::move(std::make_unique<FixedAPointInChangingAgeEffect>());
        break;
    case CardId::MASTER_OF_DISGUISE:
        return std::move(std::make_unique<MasterOfDeisGuseEffect>());
        break;
    case CardId::SERVICE_REVOLVER:
        return std::move(std::make_unique<NoneEffect>());
        break;
    case CardId::STUDY_METHODS:
        return std::move(std::make_unique<StudyMethod>());
        break;
    case CardId::THE_GAME_IS_AFOOT:
        return std::move(std::make_unique<Move3Effect>());
        break;
    case CardId::CODED_NOTES:
        return std::move(std::make_unique<CodedNotesEffect>());
        break;
    case CardId::DREAMIN_OF_REVENGE:
        return std::move(std::make_unique<DreamingOfRevengeEffect>());
        break;
    case CardId::IMPOSSIBLE_TO_SEE:
        return std::move(std::make_unique<ImpossibleToSeeEffect>());
        break;
    case CardId::INTO_THIN_AIR:
        return std::move(std::make_unique<IntoThinAirEffect>());
        break;
    case CardId::REIGN_OF_TERROR:
        return std::move(std::make_unique<ReignOfTerrorEffect>());
        break;
    default:
        break;
    }

    return std::make_unique<NoneEffect>();


}