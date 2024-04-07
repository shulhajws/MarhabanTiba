#include "../Command.hpp"
#include "../../Game/Game.hpp"
#include "../../Player/PlantFarmer.hpp"

using namespace std;

class Tanam : public Command, Game{
public:
    void useCommand();
    string getName();
};