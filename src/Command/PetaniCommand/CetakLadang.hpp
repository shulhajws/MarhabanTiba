#include "../Command.hpp"
#include "../../Game/Game.hpp"

using namespace std;

class CetakLadang : public Command, Game{
public:
    void useCommand();
    string getName();
};