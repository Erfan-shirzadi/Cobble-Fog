#ifndef GAME_LOG
#define GAME_LOG
#include <string>
#include <vector>
class GameLog{
    std::vector<std::string> logs;
    public:
    void Add(std::string);

    const std::vector<std::string> & GetLogs();


};

#endif /* GAME_LOG */
