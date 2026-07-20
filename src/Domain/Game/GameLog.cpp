#include "Domain/Game/GameLog.h"
void GameLog::Add(std::string massage){
    if(logs.size()>15)
        logs.erase(logs.begin());
    logs.push_back(massage);
}

const std::vector<std::string> & GameLog::GetLogs(){
    return logs;
}
