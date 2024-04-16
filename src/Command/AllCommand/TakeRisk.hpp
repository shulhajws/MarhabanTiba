#include "../Command.hpp"
#include "../../Game/Game.hpp"
#include "../../Risk/Risk.hpp"

using namespace std;

class TakeRisk : public Command, Game{
public:
    void useCommand();
    string getName();
};