#include "../Command.hpp"
#include "../../Game/Game.hpp"
#include "../../Shop/Shop.hpp"
#include "../../FileIO/Saver.hpp"

using namespace std;

class Simpan : public Command,Game{
public:
    void useCommand();
    string getName();
};