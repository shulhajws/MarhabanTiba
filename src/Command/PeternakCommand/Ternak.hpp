#include "../Command.hpp"

using namespace std;
#include "../../Player/PlantFarmer.hpp"
#include "../../Game/Game.hpp"

class Ternak : public Command,Game{
public:
    void useCommand();
    string getName();
};