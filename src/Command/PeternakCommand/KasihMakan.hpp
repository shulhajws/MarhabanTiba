#include "../Command.hpp"
#include "../../Player/PlantFarmer.hpp"
#include "../../Game/Game.hpp"

using namespace std;

class KasihMakan : public Command,Game{
public:
    void useCommand();
    string getName();
};