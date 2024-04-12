#include "../Command.hpp"
#include "../../Game/Game.hpp"

using namespace std;

class Bangun : public Command,Game{
public:
    void useCommand();
    string getName();
};