#include "../Command.hpp"
#include "../../Game/Game.hpp"

using namespace std;

class Beli : public Command,Game{
public:
    void useCommand();
    string getName();
};