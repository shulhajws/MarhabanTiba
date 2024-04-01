#include "../Command.hpp"
#include "../../Tax/Tax.hpp"
#include "../../Game/Game.hpp"

using namespace std;

class PungutPajak : public Command, Game{
public:
    void useCommand();
    string getName();
};