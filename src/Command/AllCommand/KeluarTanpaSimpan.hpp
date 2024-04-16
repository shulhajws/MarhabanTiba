#include "../Command.hpp"
#include "../../Game/Game.hpp"
#include <cstdlib>

using namespace std;

class KeluarTanpaSimpan : public Command,Game{
public:
    void useCommand();
    string getName();
};