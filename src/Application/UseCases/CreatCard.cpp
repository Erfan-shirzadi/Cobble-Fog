#include "Application/UseCases/CreatCard.h"
#include "Domain/Entities/Cards/Dracula/Ambush.h"
#include "Domain/Entities/Cards/Dracula/BapismOfBlood.h"
#include "Domain/Entities/Cards/Dracula/BeastForm.h"
#include "Domain/Entities/Cards/Dracula/Dash.h"
#include "Domain/Entities/Cards/Dracula/Exploit.h"
#include "Domain/Entities/Cards/Dracula/FeedingFrenzy.h"
#include "Domain/Entities/Cards/Dracula/Feint.h"
#include "Domain/Entities/Cards/Dracula/LookIntoMyEyes.h"
#include "Domain/Entities/Cards/Dracula/MistForm.h"
#include "Domain/Entities/Cards/Dracula/PeryUpon.h"
#include "Domain/Entities/Cards/Dracula/RaveningSeduction.h"
#include "Domain/Entities/Cards/Dracula/ThirstForSustenance.h"
#include "Domain/Entities/Cards/Holmes/AdministerAid.h"
#include "Domain/Entities/Cards/Holmes/CounterPunch.h"
#include "Domain/Entities/Cards/Holmes/DeduceStrategy.h"
#include "Domain/Entities/Cards/Holmes/EducationNeverEnds.h"
#include "Domain/Entities/Cards/Holmes/EliminateTheImpossible.h"
#include "Domain/Entities/Cards/Holmes/FixedPointInAChangingAge.h"
#include "Domain/Entities/Cards/Holmes/MasterOfDisguise.h"
#include "Domain/Entities/Cards/Holmes/ServiceRevolver.h"
#include "Domain/Entities/Cards/Holmes/StudyMethods.h"
#include "Domain/Entities/Cards/Holmes/TheGameIsAfoot.h"
#include "Domain/Entities/Cards/InvisibleMan/CodedNotes.h"
#include "Domain/Entities/Cards/InvisibleMan/DreamingOfRevenge.h"
#include "Domain/Entities/Cards/InvisibleMan/EmergeFromMist.h"
#include "Domain/Entities/Cards/InvisibleMan/ImpossibleToSee.h"
#include "Domain/Entities/Cards/InvisibleMan/IntoThinAir.h"
#include "Domain/Entities/Cards/InvisibleMan/Lurking.h"
#include "Domain/Entities/Cards/InvisibleMan/ReignOfTerror.h"
#include "Domain/Entities/Cards/InvisibleMan/RollingFog.h"
#include "Domain/Entities/Cards/InvisibleMan/SlipAway.h"
#include "Domain/Entities/Cards/InvisibleMan/StepLightly.h"

std::unique_ptr<Card> CreatCard::CreatCardid(CardId id){

    switch ( id)
    {
    case CardId::AMBUSH:
        return std::make_unique<Ambush>();
        break;
    case CardId::BAPISM_OF_BLOOD:
        return std::make_unique<BapismOfBlood>();
        break;
    case CardId::BEASTFORM:
        return std::make_unique<BestForm>();
        break;

    case CardId::DASH:
        return std::make_unique<Dash>();
        break;
    case CardId::EXPLOIT:
        return std::make_unique<Exploit>();
        break;
    case CardId::FEEDINGFRENZY:
        return std::make_unique<FeedingFrenzy>();
        break;
    case CardId::LOOK_INTO_MY_EYES:
        return std::make_unique<LookIntoMyEyes>();
        break;
    case CardId::FEINT:
        return std::make_unique<Feint>();
        break;
    case CardId::MISTFORM:
        return std::make_unique<MistForm>();
        break;
    case CardId::PERYUPON:
        return std::make_unique<PeryUpon>();
        break;
    case CardId::RAVENING_SEDUCTION:
        return std::make_unique<RaveningSeduction>();
        break;
    case CardId::THIRST_FOR_SUSTENANCE:
        return std::make_unique<ThirstForSustenance>();
        break;
    case CardId::ADMINISTER_AID:
        return std::make_unique<AdministerAid>();
        break;
    case CardId::COUNTER_PUNCH:
        return std::make_unique<CounterPunch>();
        break;
    case CardId::DEDUCE_STRATEGY:
        return std::make_unique<DeduceStrategy>();
        break;
    case CardId::EDUCATION_NEVER_ENDS:
        return std::make_unique<EducationNeverEnds>();
        break;
    case CardId::ELIMINATE_THE_IMPOSSIBLE:
        return std::make_unique<EliminateTheImpossible>();
        break;
    case CardId::FIXED_POINT_IN_A_CHANGING_AGE:
        return std::make_unique<FixedPointInAChangingAge>();
        break;
    case CardId::MASTER_OF_DISGUISE:
        return std::make_unique<MasterOfDisguise>();
        break;
    case CardId::SERVICE_REVOLVER:
        return std::make_unique<ServiceRevolver>();
        break;
    case CardId::STUDY_METHODS:
        return std::make_unique<StudyMethods>();
        break;
    case CardId::THE_GAME_IS_AFOOT:
        return std::make_unique<TheGameIsAfoot>();
        break;
    
        case CardId::CODED_NOTES:
        return std::make_unique<CodedNotes>();
        break;
    case CardId::DREAMIN_OF_REVENGE:
        return std::make_unique<DreaminOfRevenge>();
        break;
    case CardId::EMERGE_FROM_MIST:
        return std::make_unique<EmergeFromMist>();
        break;
    case CardId::IMPOSSIBLE_TO_SEE:
        return std::make_unique<ImpossibleToSee>();
        break;
    case CardId::INTO_THIN_AIR:
        return std::make_unique<IntoThinAir>();
        break;
    case CardId::LURKING:
        return std::make_unique<Lurking>();
        break;
    case CardId::REIGN_OF_TERROR:
        return std::make_unique<ReignOfTerror>();
        break;
    case CardId::ROLLING_FOG:
        return std::make_unique<RollingFog>();
        break;

    case CardId::SLIP_AWAY:
        return std::make_unique<SlipAway>();
        break;
    case CardId::STEP_LIGHTLY:
        return std::make_unique<StepLightly>();
        break;
    default:
        break;
    }

    return std::make_unique<StepLightly>();

}
